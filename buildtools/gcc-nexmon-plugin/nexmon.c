#include <gcc-plugin.h>
#include <tree.h>
#include <print-tree.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <tree-iterator.h>
#include <c-tree.h>
#include <c-family/c-pragma.h>

static tree handle_nexmon_place_at_attribute(tree *node, tree name, tree args, int flags, bool *no_add_attr);

int plugin_is_GPL_compatible = 1;

static const char *objfile = "patch.o";
static const char *fwfile = "fw_bcmdhd.bin";
static const char *prefile = "nexmon.generated.pre";
static const char *targetregion = NULL;
static unsigned int ramstart = 0x180000;
static unsigned int chipver = 0;
static unsigned int fwver = 0;

static FILE *pre_fp;

static struct attribute_spec user_attr =
{
	.name = "at",
	.min_length = 1,
	.max_length = 5,
	.decl_required = true,
	.type_required = false,
	.function_type_required = false,
	.affects_type_identity = false,
	.handler = handle_nexmon_place_at_attribute,
};

static void 
pre_genericize_callback(void *event_data, void *user_data) {
    tree t = (tree)event_data;
    char asm_str_start[] = "rsr.litbase a15\n \
                            movi a14, 0 \n \
                            wsr.litbase a14\n";
    char asm_str_end[] = "wsr.litbase a15\n";

    tree dt = DECL_SAVED_TREE(t);
    tree body_stmt = BIND_EXPR_BODY(dt);
    //debug_tree(body);
    printf("tree code:: %d == %d\n", TREE_CODE(body_stmt), STATEMENT_LIST);

    //for(tree_stmt_iterator i = tsi_start(body_stmt); !tsi_end_p(i); tsi_next(&i)) {
    //    printf("new statement\n");
    //    tree stmt = tsi_stmt(i);
    //}
    tree s_start = build_string(sizeof(asm_str_start), asm_str_start);
    tree s_end = build_string(sizeof(asm_str_end), asm_str_end);
    tree asm_expr_start = build_asm_expr(EXPR_LOCATION(dt), s_start, NULL, NULL, NULL, NULL, true, false);
    tree asm_expr_end = build_asm_expr(EXPR_LOCATION(dt), s_end, NULL, NULL, NULL, NULL, true, false);
    tree asm_stmt_start = build_asm_stmt(true, asm_expr_start);
    tree asm_stmt_end = build_asm_stmt(true, asm_expr_end);

    tree_stmt_iterator i = tsi_start(body_stmt);
    tsi_link_before(&i, asm_stmt_start, TSI_SAME_STMT);
    for(i = tsi_start(body_stmt); !tsi_one_before_end_p(i); tsi_next(&i)) {
    }
    tsi_link_before(&i, asm_stmt_end, TSI_SAME_STMT);
    //append_to_statement_list(asm_expr, &body_stmt);
    printf("------------------------\n");
    //printf("debug: stmt #%d\n", j);
    //debug_tree(stmt);
}

static tree
handle_nexmon_place_at_attribute(tree *node, tree name, tree args, int flags, bool *no_add_attr)
{
	//tree itr; 
	tree tmp_tree;

	const char *decl_name = IDENTIFIER_POINTER(DECL_NAME(*node));
	//const char *attr_name = IDENTIFIER_POINTER(name);
	//const char *param1_str = TREE_STRING_POINTER(TREE_VALUE(args));
	const char *region = NULL;
    const char *patch_file = fwfile;
    //const char *patch_file = NULL;
	unsigned int addr = 0;
	bool is_dummy = false;
	bool is_region = false;
	bool is_flashpatch = false;
	unsigned int chipver_local = 0;
	unsigned int fwver_local = 0;

	if (TREE_CODE(TREE_VALUE(args)) == STRING_CST) {
		region = TREE_STRING_POINTER(TREE_VALUE(args));
		is_region = true;
	} else if (TREE_CODE(TREE_VALUE(args)) == INTEGER_CST) {
		addr = TREE_INT_CST_LOW(TREE_VALUE(args));
	}

	tmp_tree = TREE_CHAIN(args);
	if(tmp_tree != NULL_TREE) {
		is_dummy = strstr(TREE_STRING_POINTER(TREE_VALUE(tmp_tree)), "dummy");
		is_flashpatch = strstr(TREE_STRING_POINTER(TREE_VALUE(tmp_tree)), "flashpatch");

		tmp_tree = TREE_CHAIN(tmp_tree);
		if(tmp_tree != NULL_TREE) {
			chipver_local = TREE_INT_CST_LOW(TREE_VALUE(tmp_tree));

			tmp_tree = TREE_CHAIN(tmp_tree);
			if(tmp_tree != NULL_TREE) {
				fwver_local = TREE_INT_CST_LOW(TREE_VALUE(tmp_tree));
			}
            tmp_tree = TREE_CHAIN(tmp_tree);
            if(tmp_tree != NULL_TREE && TREE_CODE(TREE_VALUE(tmp_tree)) == STRING_CST) {
                patch_file = TREE_STRING_POINTER(TREE_VALUE(tmp_tree));
                printf("file: %s\n", patch_file);
            }
		}
	}

	//printf("decl_name: %s\n", decl_name);
	//printf("attr_name: %s\n", attr_name);
    DECL_COMMON_CHECK (*node)->decl_common.align = 8;

	//printf("align: %d\n", DECL_COMMON_CHECK (*node)->decl_common.align);
	//if (DECL_COMMON_CHECK (*node)->decl_common.align == 32 && (addr & 1))
	//	DECL_COMMON_CHECK (*node)->decl_common.align = 8;

	//if (DECL_COMMON_CHECK (*node)->decl_common.align == 32 && (addr & 2))
	//	DECL_COMMON_CHECK (*node)->decl_common.align = 16;
	//printf("align: %d\n", DECL_COMMON_CHECK (*node)->decl_common.align);

	//for(itr = args; itr != NULL_TREE; itr = TREE_CHAIN(itr)) {
	//	printf("arg: %s %08x\n", TREE_STRING_POINTER(TREE_VALUE(itr)), (unsigned int) strtol(TREE_STRING_POINTER(TREE_VALUE(itr)), NULL, 0));
		//debug_tree(itr);
		//debug_tree(TREE_VALUE(itr));
	//}

	if ((chipver == 0 || chipver_local == 0 || chipver == chipver_local) && (fwver == 0 || fwver_local == 0 || fwver == fwver_local)) {
		if (is_region) {
			fprintf(pre_fp, "%s REGION %s %s %s\n", region, objfile, decl_name, patch_file);
		} else if (is_flashpatch) {
			fprintf(pre_fp, "0x%08x FLASHPATCH %s %s %s\n", addr, objfile, decl_name, patch_file);
		} else if (is_dummy) {
			fprintf(pre_fp, "0x%08x DUMMY %s %s %s\n", addr, objfile, decl_name, patch_file);
		} else {
			fprintf(pre_fp, "0x%08x PATCH %s %s %s\n", addr, objfile, decl_name, patch_file);
		}
	}

	//debug_tree(*node);
	//debug_tree(name);
	return NULL_TREE;
}

static void
register_attributes(void *event_data, void *data)
{
	register_attribute(&user_attr);
}

static void
handle_pragma_targetregion(cpp_reader *dummy)
{
	tree message = 0;
	if (pragma_lex(&message) != CPP_STRING) {
      	printf ("<#pragma NEXMON targetregion> is not a string");
      	return;
    }

 	if (TREE_STRING_LENGTH (message) > 1) {
		targetregion = TREE_STRING_POINTER (message);
		fprintf(pre_fp, "%s TARGETREGION %s %s\n", targetregion, objfile, fwfile);
 	}
}

static void 
register_pragmas(void *event_data, void *data)
{
	c_register_pragma("NEXMON", "targetregion", handle_pragma_targetregion);
}

static void
handle_plugin_finish(void *event_data, void *data)
{
	fclose(pre_fp);
}

int
plugin_init(struct plugin_name_args *info, struct plugin_gcc_version *ver)
{
	int i = 0;
	for (i = 0; i < info->argc; i++) {
		if (!strcmp(info->argv[i].key, "objfile")) {
			objfile = info->argv[i].value;
		} else if (!strcmp(info->argv[i].key, "prefile")) {
			prefile = info->argv[i].value;
		} else if (!strcmp(info->argv[i].key, "fwfile")) {
			fwfile = info->argv[i].value;
		} else if (!strcmp(info->argv[i].key, "ramstart")) {
			ramstart = (unsigned int) strtol(info->argv[i].value, NULL, 0);
		} else if (!strcmp(info->argv[i].key, "chipver")) {
			chipver = (unsigned int) strtol(info->argv[i].value, NULL, 0);
		} else if (!strcmp(info->argv[i].key, "fwver")) {
			fwver = (unsigned int) strtol(info->argv[i].value, NULL, 0);
		}
	}
    printf("fw file: %s\n", fwfile);

	pre_fp = fopen(prefile, "a");

	if (!pre_fp) {
		fprintf(stderr, "gcc_nexmon_plugin: Pre file not writeable! (error)\n");
		return -1;
	}

    register_callback("nexmon", PLUGIN_PRE_GENERICIZE, pre_genericize_callback, NULL);
	register_callback("nexmon", PLUGIN_ATTRIBUTES, register_attributes, NULL);
	register_callback("nexmon", PLUGIN_PRAGMAS, register_pragmas, NULL);
	register_callback("nexmon", PLUGIN_FINISH, handle_plugin_finish, NULL);

	return 0;
}
