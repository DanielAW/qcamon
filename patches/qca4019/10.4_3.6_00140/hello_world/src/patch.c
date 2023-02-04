#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <patcher.h>
#include <wrapper.h>
#include <helper.h>

void my_patch(void *a1, void *a2, void *a3, void *a4) {
    asm (
            "mov.n   a10, a2\n"
            "mov.n   a11, a3\n"
            "mov.n   a12, a4\n"
            "mov.n   a13, a5\n"

            //a6 = 0x1234
            "movi a6, 0x12\n"
            "slli a6, a6, 8\n"
            "movi a7, 0x34\n"
            "add a6, a6, a7\n"

            //a7 = 0x410a88
            "movi a7, 0x41\n"
            "slli a7, a7, 16\n"
            "movi a8, 0x0a\n"
            "slli a8, a8, 8\n"
            "add a7, a7, a8\n"
            "movi a8, 0x88\n"
            "add a7, a7, a8\n"

            //store 0x1234 at 0x9e1300
            "s32i.n  a6, a7, 0\n"

            //a6 = 0xc3834
            "movi a6, 0xc\n"
            "slli a6, a6, 16\n"
            "movi a7, 0x38\n"
            "slli a7, a7, 8\n"
            "add a6, a6, a7\n"
            "movi a7, 0x34\n"
            "add a6, a6, a7\n"

            "callx8 a6\n"
        );
}

/*
void my_patch(void *a1, void *a2, void *a3, void *a4) {
    int *p = (int *) 0x9e1300;
    *p = 0x1234;
    wlan_main(a1, a2, a3, a4);
}
*/

//int32_t wlan_main_ptr = 0xDEADBEEF;

//__attribute__((at(0x409228, "", CHIP_VER_QCA, FW_VER_QCA)))
//GenericPatch4(wlan_main_ptr_patch, wlan_main_ptr);
