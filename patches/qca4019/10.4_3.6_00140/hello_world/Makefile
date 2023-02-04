FW_PATH=$(NEXMON_ROOT)/firmwares/qca4019/10.4_3.6_00140
include $(FW_PATH)/definitions.mk

LOCAL_SRCS=$(wildcard src/*.c)
COMMON_SRCS=$(wildcard $(NEXMON_ROOT)/patches/common/*.c)

OBJS=$(addprefix obj/,$(notdir $(LOCAL_SRCS:.c=.o)) $(notdir $(COMMON_SRCS:.c=.o)) $(notdir $(FW_SRCS:.c=.o)))

CFLAGS= \
	-fplugin=$(CCPLUGIN) \
	-fplugin-arg-nexmon-objfile=$@ \
	-fplugin-arg-nexmon-prefile=gen/nexmon.pre \
	-fplugin-arg-nexmon-chipver=$(NEXMON_CHIP_NUM) \
	-fplugin-arg-nexmon-fwver=$(NEXMON_FW_VERSION_NUM) \
	-DNEXMON_CHIP=$(NEXMON_CHIP) \
	-DNEXMON_FW_VERSION=$(NEXMON_FW_VERSION) \
    -Wall -Werror -O3 -nostdlib -nostartfiles -ffreestanding \
	-mtext-section-literals \
	-I$(NEXMON_ROOT)/patches/include \
	-I$(FW_PATH) \
	-Isrc

#	-ffunction-sections -fdata-sections \
#	-mtext-section-literals -mauto-litpools \

all: firmware-5.bin

init: FORCE
	$(Q)make -s -f $(NEXMON_ROOT)/patches/common/header.mk
	$(Q)mkdir -p obj gen log

obj/%.o: src/%.c
	@printf "\033[0;31m  COMPILING\033[0m %s => %s (details: log/compiler.log)\n" $< $@
	$(Q)cat gen/nexmon.pre 2>>log/error.log | gawk '{ if ($$3 != "$@") print; }' > tmp && mv tmp gen/nexmon.pre
#	$(Q)$(CC)gcc $(CFLAGS) -c $< -o $@ >>log/compiler.log
	$(Q)$(CC)gcc $(CFLAGS) -c $< -o $@

obj/%.o: $(NEXMON_ROOT)/patches/common/%.c
	@printf "\033[0;31m  COMPILING\033[0m %s => %s (details: log/compiler.log)\n" $< $@
	$(Q)cat gen/nexmon.pre 2>>log/error.log | gawk '{ if ($$3 != "$@") print; }' > tmp && mv tmp gen/nexmon.pre
	$(Q)$(CC)gcc $(CFLAGS) -c $< -o $@ >>log/compiler.log

gen/nexmon.ld: $(OBJS)
	@printf "\033[0;31m  GENERATING LINKER FILE\033[0m gen/nexmon.pre => %s\n" $@
	$(Q)sort gen/nexmon.pre | gawk -f $(NEXMON_ROOT)/buildtools/scripts/nexmon.ld.awk > $@

gen/nexmon.mk: $(OBJS) $(FW_PATH)/definitions.mk
	@printf "\033[0;31m  GENERATING MAKE FILE\033[0m gen/nexmon.pre => %s\n" $@
#	$(Q)printf "$(RAM_FILE): gen/patch.elf FORCE\n" > $@
	$(Q)printf "segment2_00980000_mod.bin: gen/patch.elf FORCE\n" > $@
	$(Q)sort gen/nexmon.pre | \
		gawk -v src_file=gen/patch.elf -f $(NEXMON_ROOT)/buildtools/scripts/nexmon.mk.1.awk | \
		gawk -v ramstart=$(RAMSTART) -f $(NEXMON_ROOT)/buildtools/scripts/nexmon.mk.2.awk >> $@
	$(Q)printf "\nFORCE:\n" >> $@
	$(Q)gawk '!a[$$0]++' $@ > tmp && mv tmp $@

gen/memory.ld: $(FW_PATH)/definitions.mk
	@printf "\033[0;31m  GENERATING LINKER FILE\033[0m %s\n" $@
	$(Q)printf "rom : ORIGIN = 0x%08x, LENGTH = 0x%08x\n" $(ROMSTART) $(ROMSIZE) > $@
	$(Q)printf "ram : ORIGIN = 0x%08x, LENGTH = 0x%08x\n" $(RAMSTART) $(RAMSIZE) >> $@
	$(Q)printf "patch : ORIGIN = 0x%08x, LENGTH = 0x%08x\n" $(PATCHSTART) $(PATCHSIZE) >> $@

gen/patch.elf: patch.ld gen/nexmon.ld gen/memory.ld $(OBJS)
	@printf "\033[0;31m  LINKING OBJECTS\033[0m => %s (details: log/linker.log, log/linker.err)\n" $@
#	$(Q)$(CC)ld -T $< -o $@ --gc-sections --print-gc-sections -M >>log/linker.log 2>>log/linker.err
#	$(Q)$(CC)ld -T $< -o $@ -M >>log/linker.log 2>>log/linker.err
	$(Q)$(CC)ld -T $< -o $@


#######################################################

segment2_00980000_mod.bin: 
	$(Q)cp $(FW_PATH)/segment2_00980000.bin $@
	@printf "\033[0;31m  APPLYING PATCHES\033[0m gen/nexmon.mk => %s (details: log/patches.log)\n" $@
	$(Q)make -f gen/nexmon.mk >>log/patches.log 2>>log/patches.log

compress_parts: segment2_00980000_mod.bin
	@printf "\033[0;31m Compress parts ...\033[0m\n"
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_000C3800.bin segment2_000C3800_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_000DF5D0.bin segment2_000DF5D0_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_000DFEE0.bin segment2_000DFEE0_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_00409200_mod.bin segment2_00409200_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_0040D840.bin segment2_0040D840_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_00410AA0.bin segment2_00410AA0_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp segment2_00980000_mod.bin segment2_00980000_comp.bin
#	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp patch_space.bin patch_space_comp.bin

2nd_segment.bin: compress_parts
	@printf "\033[0;31m SGMT \033[0m\n"
	$(Q)echo "53474D54" | xxd -r -p - > 2nd_segment.bin
	@printf "\033[0;31m flags 'compressed' \033[0m\n"
	$(Q)echo "01000000" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m addr: 0x409200 \033[0m\n"
	$(Q)echo "00924000" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m len: 0x4460 \033[0m\n"
	$(Q)echo "60440000" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m segment2_00409200_comp.bin \033[0m\n"
	$(Q)cat segment2_00409200_comp.bin >> 2nd_segment.bin
	@printf "\033[0;31m addr: 0x40D840 \033[0m\n"
	$(Q)echo "40D84000" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m len: 0x3260 \033[0m\n"
	$(Q)echo "60320000" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m segment2_0040D840_comp.bin \033[0m\n"
	$(Q)cat segment2_0040D840_comp.bin >> 2nd_segment.bin
	@printf "\033[0;31m addr: 0x410AA0 \033[0m\n"
	$(Q)echo "A00A4100" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m len: 0x2998 \033[0m\n"
	$(Q)echo "98290000" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m segment2_00410AA0_comp.bin \033[0m\n"
	$(Q)cat segment2_00410AA0_comp.bin >> 2nd_segment.bin
	@printf "\033[0;31m addr: 0x980000 \033[0m\n"
	$(Q)echo "00009800" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m len: 0x4ff48 \033[0m\n"
	$(Q)echo "48ff0400" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m segment2_00980000_comp.bin \033[0m\n"
	$(Q)cat segment2_00980000_comp.bin >> 2nd_segment.bin
	@printf "\033[0;31m addr: 0xDF5D0 \033[0m\n"
	$(Q)echo "D0F50D00" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m len: 0x910 \033[0m\n"
	$(Q)echo "10090000" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m segment2_000DF5D0_comp.bin \033[0m\n"
	$(Q)cat segment2_000DF5D0_comp.bin >> 2nd_segment.bin
	@printf "\033[0;31m addr: 0xDFEE0 \033[0m\n"
	$(Q)echo "E0FE0D00" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m len: 0x45F0 \033[0m\n"
	$(Q)echo "F0450000" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m segment2_000DFEE0_comp.bin \033[0m\n"
	$(Q)cat segment2_000DFEE0_comp.bin >> 2nd_segment.bin
	@printf "\033[0;31m addr: 0xC3800 \033[0m\n"
	$(Q)echo "00380C00" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m len: 0x1BDC1 \033[0m\n"
	$(Q)echo "C1BD0100" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m segment2_000C3800_comp.bin \033[0m\n"
	$(Q)cat segment2_000C3800_comp.bin >> 2nd_segment.bin
#	@printf "\033[0;31m addr: 0x9E0000 \033[0m\n"
#	$(Q)echo "00009E00" | xxd -r -p - >> 2nd_segment.bin
#	@printf "\033[0;31m len: 0x200 \033[0m\n"
#	$(Q)echo "00020000" | xxd -r -p - >> 2nd_segment.bin
#	@printf "\033[0;31m patch_space_comp.bin \033[0m\n"
#	$(Q)cat patch_space_comp.bin >> 2nd_segment.bin
#	@printf "\033[0;31m Adding filler 00 bytes \033[0m\n"
#	$(Q)echo "0000" | xxd -r -p - >> 2nd_segment.bin
	$(Q)echo "04009800fdffffff" | xxd -r -p - >> 2nd_segment.bin
	$(Q)echo "00000000ffffffff" | xxd -r -p - >> 2nd_segment.bin
	@printf "\033[0;31m adding padding bytes \033[0m\n"
	@SGMT_PAD=`stat --printf="%s" 2nd_segment.bin | xargs printf '4-%d%%4\n' | bc |tr -d "\n"`; \
	if [ $$SGMT_PAD -ne 4 ]; then \
		dd if=/dev/zero bs=1 count=$$SGMT_PAD >> 2nd_segment.bin; \
	fi

firmware-5.bin: init gen/patch.elf $(FW_PATH)/$(RAM_FILE) gen/nexmon.mk 2nd_segment.bin
	@printf "\033[0;31m Header ...\033[0m\n"
	$(Q)cat $(FW_PATH)/header.bin > $@
	@printf "\033[0;31m Segment #1 (OTP Image) ...\033[0m\n"
	$(Q)echo "04000000" | xxd -r -p - >> $@
	$(Q)echo "44120000" | xxd -r -p - >> $@
	$(Q)cat $(FW_PATH)/segment1.bin >> $@
	@printf "\033[0;31m Segment #2 (FW Image) ...\033[0m\n"
	$(Q)echo "03000000" | xxd -r -p - >> $@
	@printf "\033[0;31m size of Segment #2 (should be 4 byte aligned) 0x%x\033[0m\n" `stat --printf="%s" 2nd_segment.bin`
	$(Q)stat --printf="%s" 2nd_segment.bin |xargs printf '000%x' | fold -w2 |tac |tr -d "\n" | xxd -r -p - >> $@
	$(Q)cat 2nd_segment.bin >> $@
	$(Q)echo "02000000" | xxd -r -p - >> $@
	$(Q)echo "03000000" | xxd -r -p - >> $@
	$(Q)echo "08700377" | xxd -r -p - >> $@
	$(Q)echo "05000000" | xxd -r -p - >> $@
	$(Q)echo "04000000" | xxd -r -p - >> $@
	$(Q)echo "06000000" | xxd -r -p - >> $@
	$(Q)echo "06000000" | xxd -r -p - >> $@
	$(Q)echo "04000000" | xxd -r -p - >> $@
	$(Q)echo "04000000" | xxd -r -p - >> $@
	@printf "\033[0;31m Swap Image ...\033[0m\n"
	$(Q)echo "07000000" | xxd -r -p - >> $@
	$(Q)echo "EFFA0200" | xxd -r -p - >> $@
	$(Q)cat $(FW_PATH)/swap_image.bin >> $@
	$(Q)echo "77" | xxd -r -p - >> $@

clean: FORCE
	$(Q)rm -r *comp.bin 2nd_segment.bin firmware-5.bin obj gen log segment2_00980000_mod.bin

install:
	scp -O -oHostKeyAlgorithms=+ssh-rsa firmware-5.bin habanero:/lib/firmware/ath10k/QCA4019/hw1.0/firmware-5.bin
	ssh habanero "rmmod ath10k_pci && insmod /root/ath10k_pci.ko"

FORCE:
