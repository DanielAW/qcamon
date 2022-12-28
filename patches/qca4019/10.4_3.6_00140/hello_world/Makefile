FW_PATH=$(NEXMON_ROOT)/firmwares/qca4019/10.4_3.6_00140
include $(FW_PATH)/definitions.mk

all: compress_parts fw_file

compress_parts: 
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_000C3800.bin segment2_000C3800_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_000DF5D0.bin segment2_000DF5D0_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_000DFEE0.bin segment2_000DFEE0_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_00409200.bin segment2_00409200_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_0040D840.bin segment2_0040D840_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_00410AA0.bin segment2_00410AA0_comp.bin
	$(Q)$(NEXMON_ROOT)/buildtools/scripts/ath10k_comp $(FW_PATH)/segment2_00980000.bin segment2_00980000_comp.bin

fw_file:
	@printf "\033[0;31m SGMT \033[0m\n"
	$(Q)echo "53474D54" | xxd -r -p - > out.bin
	@printf "\033[0;31m flags 'compressed' \033[0m\n"
	$(Q)echo "01000000" | xxd -r -p - >> out.bin
	@printf "\033[0;31m addr: 0x409200 \033[0m\n"
	$(Q)echo "00924000" | xxd -r -p - >> out.bin
	@printf "\033[0;31m len: 0x4460 \033[0m\n"
	$(Q)echo "60440000" | xxd -r -p - >> out.bin
	@printf "\033[0;31m segment2_00409200_comp.bin \033[0m\n"
	$(Q)cat segment2_00409200_comp.bin >> out.bin
	@printf "\033[0;31m addr: 0x40D840 \033[0m\n"
	$(Q)echo "40D84000" | xxd -r -p - >> out.bin
	@printf "\033[0;31m len: 0x3260 \033[0m\n"
	$(Q)echo "60320000" | xxd -r -p - >> out.bin
	@printf "\033[0;31m segment2_0040D840_comp.bin \033[0m\n"
	$(Q)cat segment2_0040D840_comp.bin >> out.bin
	@printf "\033[0;31m addr: 0x410AA0 \033[0m\n"
	$(Q)echo "A00A4100" | xxd -r -p - >> out.bin
	@printf "\033[0;31m len: 0x2998 \033[0m\n"
	$(Q)echo "98290000" | xxd -r -p - >> out.bin
	@printf "\033[0;31m segment2_00410AA0_comp.bin \033[0m\n"
	$(Q)cat segment2_00410AA0_comp.bin >> out.bin
	@printf "\033[0;31m addr: 0x980000 \033[0m\n"
	$(Q)echo "00009800" | xxd -r -p - >> out.bin
	@printf "\033[0;31m len: 0x4FF48 \033[0m\n"
	$(Q)echo "48FF0400" | xxd -r -p - >> out.bin
	@printf "\033[0;31m segment2_00980000_comp.bin \033[0m\n"
	$(Q)cat segment2_00980000_comp.bin >> out.bin
	@printf "\033[0;31m addr: 0xDF5D0 \033[0m\n"
	$(Q)echo "D0F50D00" | xxd -r -p - >> out.bin
	@printf "\033[0;31m len: 0x910 \033[0m\n"
	$(Q)echo "10090000" | xxd -r -p - >> out.bin
	@printf "\033[0;31m segment2_000DF5D0_comp.bin \033[0m\n"
	$(Q)cat segment2_000DF5D0_comp.bin >> out.bin
	@printf "\033[0;31m addr: 0xDFEE0 \033[0m\n"
	$(Q)echo "E0FE0D00" | xxd -r -p - >> out.bin
	@printf "\033[0;31m len: 0x45F0 \033[0m\n"
	$(Q)echo "F0450000" | xxd -r -p - >> out.bin
	@printf "\033[0;31m segment2_000DFEE0_comp.bin \033[0m\n"
	$(Q)cat segment2_000DFEE0_comp.bin >> out.bin
	@printf "\033[0;31m addr: 0xC3800 \033[0m\n"
	$(Q)echo "00380C00" | xxd -r -p - >> out.bin
	@printf "\033[0;31m len: 0x1BDC1 \033[0m\n"
	$(Q)echo "C1BD0100" | xxd -r -p - >> out.bin
	@printf "\033[0;31m segment2_000C3800_comp.bin \033[0m\n"
	$(Q)cat segment2_000C3800_comp.bin >> out.bin
	$(Q)echo "04009800fdffffff" | xxd -r -p - >> out.bin
	$(Q)echo "00000000ffffffff" | xxd -r -p - >> out.bin

clean:
	$(Q)rm *comp.bin
