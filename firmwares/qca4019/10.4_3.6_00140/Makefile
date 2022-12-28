include definitions.mk

all: header.bin segment1.bin segment2.bin swap_image.bin uncompress

header.bin: $(RAM_FILE) definitions.mk
	@printf "\033[0;31m EXTRACTING HEADER\033[0m\n"
	$(Q)dd if=$< of=$@ bs=1 count=$$(($(HEADER_SIZE))) 2>/dev/null

segment1.bin: $(RAM_FILE) definitions.mk
	@printf "\033[0;31m EXTRACTING SEGMENT #1\033[0m\n"
	$(Q)dd if=$< of=$@ bs=1 skip=$$(($(1ST_SEGMENT_START))) count=$$(($(1ST_SEGMENT_SIZE))) 2>/dev/null

segment2.bin: $(RAM_FILE) definitions.mk
	@printf "\033[0;31m EXTRACTING SEGMENT #2\033[0m\n"
	$(Q)dd if=$< of=$@ bs=1 skip=$$(($(2ND_SEGMENT_START))) count=$$(($(2ND_SEGMENT_SIZE))) 2>/dev/null

swap_image.bin: $(RAM_FILE) definitions.mk
	@printf "\033[0;31m EXTRACTING SWAP IMAGE\033[0m\n"
	$(Q)dd if=$< of=$@ bs=1 skip=$$(($(SWAP_IMG_START))) count=$$(($(SWAP_IMG_SIZE))) 2>/dev/null

uncompress: segment2.bin definitions.mk
	@printf "\033[0;31m DECOMPRESS PARTS IN SEGMENT #2\033[0m\n"
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_unlz.py $< segment2
	
