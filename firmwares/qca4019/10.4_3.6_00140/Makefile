include definitions.mk

all: segment2.bin uncompress

segment2.bin: $(RAM_FILE) definitions.mk
	@printf "\033[0;31m EXTRACTING SEGMENT #2\033[0m\n"
	$(Q)dd if=$< of=$@ bs=1 skip=$$(($(2ND_SEGMENT_START))) count=$$(($(2ND_SEGMENT_SIZE))) 2>/dev/null

uncompress: segment2.bin definitions.mk
	@printf "\033[0;31m DECOMPRESS PARTS IN SEGMENT #2\033[0m\n"
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_unlz.py $< segment2
	
