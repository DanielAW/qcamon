#!/usr/bin/env python3

# https://android.googlesource.com/kernel/msm.git/+/android-msm-bullhead-3.10-n-preview-1/drivers/staging/qcacld-2.0/CORE/SERVICES/COMMON/bmi_msg.h
# https://github.com/MariadeAnton/bcl/blob/master/src/lz.c

import binascii
import sys
import struct

f = open(sys.argv[1], 'rb')
inf = f.read()
f.close()

sgmt_file_header = inf[:8]
inf = inf[8:]

assert sgmt_file_header[0:4] == b'SGMT'
assert struct.unpack("<I", sgmt_file_header[4:8])[0] == 1

def _readvarsize(inf):
    out = 0

    while True:
        b = inf[0]
        inf = inf[1:]

        out = (out << 7) | (b & 0x7f)
        if (b & 0x80) == 0:
            break

    return out, inf

print(binascii.hexlify(inf[0x4018:0x4020]))
# Segments
while inf:
    seg_meta = inf[:8]
    inf = inf[8:]

    load_addr, seg_len = struct.unpack("<II", seg_meta)
    print("Segment @ 0x{:08X} len {:08X}".format(load_addr, seg_len))

    if seg_len == 0xFFFFFFFD:
        print("*** BEGINADDR: 0x{:08X} ***".format(load_addr))
        continue
    if seg_len == 0xFFFFFFFF:
        print("*** DONE ***")
        continue

    # The LZ77 part
    lz77_marker = inf[0:1]
    inf = inf[1:]
    outf = b''
    print(" LZ77 marker 0x{:02X}".format(lz77_marker[0]))

    while len(outf) < seg_len:
        len_begin = len(inf)
        b = inf[0:1]
        inf = inf[1:]

        if b == lz77_marker:
            if inf[0] == 0:
                # Literal marker
                inf = inf[1:]
                outf += lz77_marker
            else:
                ref_len, inf = _readvarsize(inf)
                ref_off, inf = _readvarsize(inf)
                #print(" LZ77 ref len {} off {}".format(ref_len, ref_off))

                # Bad ref?
                assert ref_off <= len(outf)
                # Overrun final output length?
                assert len(outf) + ref_len <= seg_len

                for _ in range(ref_len):
                    outf += outf[-ref_off:-ref_off + 1]
        else:
            outf += b

    outfn = "{}_{:08X}.bin".format(sys.argv[2], load_addr)
    f = open(outfn, 'wb')
    f.write(outf)
    f.close()

