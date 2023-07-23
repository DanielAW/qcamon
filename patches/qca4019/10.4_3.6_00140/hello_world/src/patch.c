#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <patcher.h>
#include <wrapper.h>
#include <helper.h>

void my_patch(void *a1, void *a2, void *a3, void *a4) {
    int *p = (int *) 0x410a88;
    *p = 0x1234;
    wlan_main(a1, a2, a3, a4);
}

__attribute__((at(0x409228, "", CHIP_VER_QCA, FW_VER_QCA, "segment2_00409200_mod.bin")))
GenericPatch4(my_patch, my_patch);

//alternative using call8 instead of overwriting literal pool table:
/*
//opcode to jump from: 0x9800a0, to: 0x9c8200 => e51548
__attribute__((at(0x9800a0, "", CHIP_VER_QCA, FW_VER_QCA, "segment2_00980000_mod.bin")))
GenericPatch1(my_patch1, 0xe5);
__attribute__((at(0x9800a1, "", CHIP_VER_QCA, FW_VER_QCA, "segment2_00980000_mod.bin")))
GenericPatch1(my_patch2, 0x15);
__attribute__((at(0x9800a2, "", CHIP_VER_QCA, FW_VER_QCA, "segment2_00980000_mod.bin")))
GenericPatch1(my_patch3, 0x48);
*/
