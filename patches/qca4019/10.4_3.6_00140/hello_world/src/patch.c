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
