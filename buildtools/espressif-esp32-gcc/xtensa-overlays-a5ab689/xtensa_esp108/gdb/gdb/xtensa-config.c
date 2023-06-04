/* Configuration for the Xtensa architecture for GDB, the GNU debugger.

   Copyright (c) 2003-2015 Tensilica Inc.

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */

#define XTENSA_CONFIG_VERSION 0x60

#include "defs.h"
#include "xtensa-config.h"
#include "xtensa-tdep.h"



/* Masked registers.  */
xtensa_reg_mask_t xtensa_submask0[] = { { 75, 0, 1 } };
const xtensa_mask_t xtensa_mask0 = { 1, xtensa_submask0 };
xtensa_reg_mask_t xtensa_submask1[] = { { 75, 1, 1 } };
const xtensa_mask_t xtensa_mask1 = { 1, xtensa_submask1 };
xtensa_reg_mask_t xtensa_submask2[] = { { 75, 2, 1 } };
const xtensa_mask_t xtensa_mask2 = { 1, xtensa_submask2 };
xtensa_reg_mask_t xtensa_submask3[] = { { 75, 3, 1 } };
const xtensa_mask_t xtensa_mask3 = { 1, xtensa_submask3 };
xtensa_reg_mask_t xtensa_submask4[] = { { 75, 4, 1 } };
const xtensa_mask_t xtensa_mask4 = { 1, xtensa_submask4 };
xtensa_reg_mask_t xtensa_submask5[] = { { 75, 5, 1 } };
const xtensa_mask_t xtensa_mask5 = { 1, xtensa_submask5 };
xtensa_reg_mask_t xtensa_submask6[] = { { 75, 6, 1 } };
const xtensa_mask_t xtensa_mask6 = { 1, xtensa_submask6 };
xtensa_reg_mask_t xtensa_submask7[] = { { 75, 7, 1 } };
const xtensa_mask_t xtensa_mask7 = { 1, xtensa_submask7 };
xtensa_reg_mask_t xtensa_submask8[] = { { 75, 8, 1 } };
const xtensa_mask_t xtensa_mask8 = { 1, xtensa_submask8 };
xtensa_reg_mask_t xtensa_submask9[] = { { 75, 9, 1 } };
const xtensa_mask_t xtensa_mask9 = { 1, xtensa_submask9 };
xtensa_reg_mask_t xtensa_submask10[] = { { 75, 10, 1 } };
const xtensa_mask_t xtensa_mask10 = { 1, xtensa_submask10 };
xtensa_reg_mask_t xtensa_submask11[] = { { 75, 11, 1 } };
const xtensa_mask_t xtensa_mask11 = { 1, xtensa_submask11 };
xtensa_reg_mask_t xtensa_submask12[] = { { 75, 12, 1 } };
const xtensa_mask_t xtensa_mask12 = { 1, xtensa_submask12 };
xtensa_reg_mask_t xtensa_submask13[] = { { 75, 13, 1 } };
const xtensa_mask_t xtensa_mask13 = { 1, xtensa_submask13 };
xtensa_reg_mask_t xtensa_submask14[] = { { 75, 14, 1 } };
const xtensa_mask_t xtensa_mask14 = { 1, xtensa_submask14 };
xtensa_reg_mask_t xtensa_submask15[] = { { 75, 15, 1 } };
const xtensa_mask_t xtensa_mask15 = { 1, xtensa_submask15 };
xtensa_reg_mask_t xtensa_submask16[] = { { 73, 0, 4 } };
const xtensa_mask_t xtensa_mask16 = { 1, xtensa_submask16 };
xtensa_reg_mask_t xtensa_submask17[] = { { 73, 5, 1 } };
const xtensa_mask_t xtensa_mask17 = { 1, xtensa_submask17 };
xtensa_reg_mask_t xtensa_submask18[] = { { 73, 18, 1 } };
const xtensa_mask_t xtensa_mask18 = { 1, xtensa_submask18 };
xtensa_reg_mask_t xtensa_submask19[] = { { 73, 4, 1 } };
const xtensa_mask_t xtensa_mask19 = { 1, xtensa_submask19 };
xtensa_reg_mask_t xtensa_submask20[] = { { 73, 16, 2 } };
const xtensa_mask_t xtensa_mask20 = { 1, xtensa_submask20 };
xtensa_reg_mask_t xtensa_submask21[] = { { 73, 8, 4 } };
const xtensa_mask_t xtensa_mask21 = { 1, xtensa_submask21 };
xtensa_reg_mask_t xtensa_submask22[] = { { 77, 0, 32 }, { 78, 0, 8 } };
const xtensa_mask_t xtensa_mask22 = { 2, xtensa_submask22 };
xtensa_reg_mask_t xtensa_submask23[] = { { 122, 8, 4 } };
const xtensa_mask_t xtensa_mask23 = { 1, xtensa_submask23 };


/* Register map.  */
xtensa_register_t rmap[] = 
{
  /*    idx ofs bi sz al targno  flags cp typ group name  */
  XTREG(  0,  0,32, 4, 4,0x0020,0x0006 & ~1,-2, 9,0x0100,pc,          0,0,0,0,0,0)
  XTREG(  1,  4,32, 4, 4,0x0100,0x0006 & ~1,-2, 1,0x0002,ar0,         0,0,0,0,0,0)
  XTREG(  2,  8,32, 4, 4,0x0101,0x0006 & ~1,-2, 1,0x0002,ar1,         0,0,0,0,0,0)
  XTREG(  3, 12,32, 4, 4,0x0102,0x0006 & ~1,-2, 1,0x0002,ar2,         0,0,0,0,0,0)
  XTREG(  4, 16,32, 4, 4,0x0103,0x0006 & ~1,-2, 1,0x0002,ar3,         0,0,0,0,0,0)
  XTREG(  5, 20,32, 4, 4,0x0104,0x0006 & ~1,-2, 1,0x0002,ar4,         0,0,0,0,0,0)
  XTREG(  6, 24,32, 4, 4,0x0105,0x0006 & ~1,-2, 1,0x0002,ar5,         0,0,0,0,0,0)
  XTREG(  7, 28,32, 4, 4,0x0106,0x0006 & ~1,-2, 1,0x0002,ar6,         0,0,0,0,0,0)
  XTREG(  8, 32,32, 4, 4,0x0107,0x0006 & ~1,-2, 1,0x0002,ar7,         0,0,0,0,0,0)
  XTREG(  9, 36,32, 4, 4,0x0108,0x0006 & ~1,-2, 1,0x0002,ar8,         0,0,0,0,0,0)
  XTREG( 10, 40,32, 4, 4,0x0109,0x0006 & ~1,-2, 1,0x0002,ar9,         0,0,0,0,0,0)
  XTREG( 11, 44,32, 4, 4,0x010a,0x0006 & ~1,-2, 1,0x0002,ar10,        0,0,0,0,0,0)
  XTREG( 12, 48,32, 4, 4,0x010b,0x0006 & ~1,-2, 1,0x0002,ar11,        0,0,0,0,0,0)
  XTREG( 13, 52,32, 4, 4,0x010c,0x0006 & ~1,-2, 1,0x0002,ar12,        0,0,0,0,0,0)
  XTREG( 14, 56,32, 4, 4,0x010d,0x0006 & ~1,-2, 1,0x0002,ar13,        0,0,0,0,0,0)
  XTREG( 15, 60,32, 4, 4,0x010e,0x0006 & ~1,-2, 1,0x0002,ar14,        0,0,0,0,0,0)
  XTREG( 16, 64,32, 4, 4,0x010f,0x0006 & ~1,-2, 1,0x0002,ar15,        0,0,0,0,0,0)
  XTREG( 17, 68,32, 4, 4,0x0110,0x0006 & ~1,-2, 1,0x0002,ar16,        0,0,0,0,0,0)
  XTREG( 18, 72,32, 4, 4,0x0111,0x0006 & ~1,-2, 1,0x0002,ar17,        0,0,0,0,0,0)
  XTREG( 19, 76,32, 4, 4,0x0112,0x0006 & ~1,-2, 1,0x0002,ar18,        0,0,0,0,0,0)
  XTREG( 20, 80,32, 4, 4,0x0113,0x0006 & ~1,-2, 1,0x0002,ar19,        0,0,0,0,0,0)
  XTREG( 21, 84,32, 4, 4,0x0114,0x0006 & ~1,-2, 1,0x0002,ar20,        0,0,0,0,0,0)
  XTREG( 22, 88,32, 4, 4,0x0115,0x0006 & ~1,-2, 1,0x0002,ar21,        0,0,0,0,0,0)
  XTREG( 23, 92,32, 4, 4,0x0116,0x0006 & ~1,-2, 1,0x0002,ar22,        0,0,0,0,0,0)
  XTREG( 24, 96,32, 4, 4,0x0117,0x0006 & ~1,-2, 1,0x0002,ar23,        0,0,0,0,0,0)
  XTREG( 25,100,32, 4, 4,0x0118,0x0006 & ~1,-2, 1,0x0002,ar24,        0,0,0,0,0,0)
  XTREG( 26,104,32, 4, 4,0x0119,0x0006 & ~1,-2, 1,0x0002,ar25,        0,0,0,0,0,0)
  XTREG( 27,108,32, 4, 4,0x011a,0x0006 & ~1,-2, 1,0x0002,ar26,        0,0,0,0,0,0)
  XTREG( 28,112,32, 4, 4,0x011b,0x0006 & ~1,-2, 1,0x0002,ar27,        0,0,0,0,0,0)
  XTREG( 29,116,32, 4, 4,0x011c,0x0006 & ~1,-2, 1,0x0002,ar28,        0,0,0,0,0,0)
  XTREG( 30,120,32, 4, 4,0x011d,0x0006 & ~1,-2, 1,0x0002,ar29,        0,0,0,0,0,0)
  XTREG( 31,124,32, 4, 4,0x011e,0x0006 & ~1,-2, 1,0x0002,ar30,        0,0,0,0,0,0)
  XTREG( 32,128,32, 4, 4,0x011f,0x0006 & ~1,-2, 1,0x0002,ar31,        0,0,0,0,0,0)
  XTREG( 33,132,32, 4, 4,0x0120,0x0006 & ~1,-2, 1,0x0002,ar32,        0,0,0,0,0,0)
  XTREG( 34,136,32, 4, 4,0x0121,0x0006 & ~1,-2, 1,0x0002,ar33,        0,0,0,0,0,0)
  XTREG( 35,140,32, 4, 4,0x0122,0x0006 & ~1,-2, 1,0x0002,ar34,        0,0,0,0,0,0)
  XTREG( 36,144,32, 4, 4,0x0123,0x0006 & ~1,-2, 1,0x0002,ar35,        0,0,0,0,0,0)
  XTREG( 37,148,32, 4, 4,0x0124,0x0006 & ~1,-2, 1,0x0002,ar36,        0,0,0,0,0,0)
  XTREG( 38,152,32, 4, 4,0x0125,0x0006 & ~1,-2, 1,0x0002,ar37,        0,0,0,0,0,0)
  XTREG( 39,156,32, 4, 4,0x0126,0x0006 & ~1,-2, 1,0x0002,ar38,        0,0,0,0,0,0)
  XTREG( 40,160,32, 4, 4,0x0127,0x0006 & ~1,-2, 1,0x0002,ar39,        0,0,0,0,0,0)
  XTREG( 41,164,32, 4, 4,0x0128,0x0006 & ~1,-2, 1,0x0002,ar40,        0,0,0,0,0,0)
  XTREG( 42,168,32, 4, 4,0x0129,0x0006 & ~1,-2, 1,0x0002,ar41,        0,0,0,0,0,0)
  XTREG( 43,172,32, 4, 4,0x012a,0x0006 & ~1,-2, 1,0x0002,ar42,        0,0,0,0,0,0)
  XTREG( 44,176,32, 4, 4,0x012b,0x0006 & ~1,-2, 1,0x0002,ar43,        0,0,0,0,0,0)
  XTREG( 45,180,32, 4, 4,0x012c,0x0006 & ~1,-2, 1,0x0002,ar44,        0,0,0,0,0,0)
  XTREG( 46,184,32, 4, 4,0x012d,0x0006 & ~1,-2, 1,0x0002,ar45,        0,0,0,0,0,0)
  XTREG( 47,188,32, 4, 4,0x012e,0x0006 & ~1,-2, 1,0x0002,ar46,        0,0,0,0,0,0)
  XTREG( 48,192,32, 4, 4,0x012f,0x0006 & ~1,-2, 1,0x0002,ar47,        0,0,0,0,0,0)
  XTREG( 49,196,32, 4, 4,0x0130,0x0006 & ~1,-2, 1,0x0002,ar48,        0,0,0,0,0,0)
  XTREG( 50,200,32, 4, 4,0x0131,0x0006 & ~1,-2, 1,0x0002,ar49,        0,0,0,0,0,0)
  XTREG( 51,204,32, 4, 4,0x0132,0x0006 & ~1,-2, 1,0x0002,ar50,        0,0,0,0,0,0)
  XTREG( 52,208,32, 4, 4,0x0133,0x0006 & ~1,-2, 1,0x0002,ar51,        0,0,0,0,0,0)
  XTREG( 53,212,32, 4, 4,0x0134,0x0006 & ~1,-2, 1,0x0002,ar52,        0,0,0,0,0,0)
  XTREG( 54,216,32, 4, 4,0x0135,0x0006 & ~1,-2, 1,0x0002,ar53,        0,0,0,0,0,0)
  XTREG( 55,220,32, 4, 4,0x0136,0x0006 & ~1,-2, 1,0x0002,ar54,        0,0,0,0,0,0)
  XTREG( 56,224,32, 4, 4,0x0137,0x0006 & ~1,-2, 1,0x0002,ar55,        0,0,0,0,0,0)
  XTREG( 57,228,32, 4, 4,0x0138,0x0006 & ~1,-2, 1,0x0002,ar56,        0,0,0,0,0,0)
  XTREG( 58,232,32, 4, 4,0x0139,0x0006 & ~1,-2, 1,0x0002,ar57,        0,0,0,0,0,0)
  XTREG( 59,236,32, 4, 4,0x013a,0x0006 & ~1,-2, 1,0x0002,ar58,        0,0,0,0,0,0)
  XTREG( 60,240,32, 4, 4,0x013b,0x0006 & ~1,-2, 1,0x0002,ar59,        0,0,0,0,0,0)
  XTREG( 61,244,32, 4, 4,0x013c,0x0006 & ~1,-2, 1,0x0002,ar60,        0,0,0,0,0,0)
  XTREG( 62,248,32, 4, 4,0x013d,0x0006 & ~1,-2, 1,0x0002,ar61,        0,0,0,0,0,0)
  XTREG( 63,252,32, 4, 4,0x013e,0x0006 & ~1,-2, 1,0x0002,ar62,        0,0,0,0,0,0)
  XTREG( 64,256,32, 4, 4,0x013f,0x0006 & ~1,-2, 1,0x0002,ar63,        0,0,0,0,0,0)
  XTREG( 65,260,32, 4, 4,0x0200,0x0006 & ~1,-2, 2,0x1100,lbeg,        0,0,0,0,0,0)
  XTREG( 66,264,32, 4, 4,0x0201,0x0006 & ~1,-2, 2,0x1100,lend,        0,0,0,0,0,0)
  XTREG( 67,268,32, 4, 4,0x0202,0x0006 & ~1,-2, 2,0x1100,lcount,      0,0,0,0,0,0)
  XTREG( 68,272, 6, 4, 4,0x0203,0x0006 & ~1,-2, 2,0x1100,sar,         0,0,0,0,0,0)
  XTREG( 69,276, 4, 4, 4,0x0248,0x0006 & ~1,-2, 2,0x1002,windowbase,  0,0,0,0,0,0)
  XTREG( 70,280,16, 4, 4,0x0249,0x0006 & ~1,-2, 2,0x1002,windowstart, 0,0,0,0,0,0)
  XTREG( 71,284,32, 4, 4,0x02b0,0x0002 & ~1,-2, 2,0x1000,configid0,   0,0,0,0,0,0)
  XTREG( 72,288,32, 4, 4,0x02d0,0x0002 & ~1,-2, 2,0x1000,configid1,   0,0,0,0,0,0)
  XTREG( 73,292,19, 4, 4,0x02e6,0x0006 & ~1,-2, 2,0x1100,ps,          0,0,0,0,0,0)
  XTREG( 74,296,32, 4, 4,0x03e7,0x0006 & ~1,-2, 3,0x0110,threadptr,   0,0,0,0,0,0)
  XTREG( 75,300,16, 4, 4,0x0204,0x0006 & ~1,-1, 2,0x1100,br,          0,0,0,0,0,0)
  XTREG( 76,304,32, 4, 4,0x020c,0x0006 & ~1,-1, 2,0x1100,scompare1,   0,0,0,0,0,0)
  XTREG( 77,308,32, 4, 4,0x0210,0x0006 & ~1,-1, 2,0x1100,acclo,       0,0,0,0,0,0)
  XTREG( 78,312, 8, 4, 4,0x0211,0x0006 & ~1,-1, 2,0x1100,acchi,       0,0,0,0,0,0)
  XTREG( 79,316,32, 4, 4,0x0220,0x0006 & ~1,-1, 2,0x1100,m0,          0,0,0,0,0,0)
  XTREG( 80,320,32, 4, 4,0x0221,0x0006 & ~1,-1, 2,0x1100,m1,          0,0,0,0,0,0)
  XTREG( 81,324,32, 4, 4,0x0222,0x0006 & ~1,-1, 2,0x1100,m2,          0,0,0,0,0,0)
  XTREG( 82,328,32, 4, 4,0x0223,0x0006 & ~1,-1, 2,0x1100,m3,          0,0,0,0,0,0)
  XTREG( 83,332,32, 4, 4,0x03e6,0x000e & ~1,-1, 3,0x0110,expstate,    0,0,0,0,0,0)
  XTREG( 84,336,32, 4, 4,0x0259,0x000d & ~1,-2, 2,0x1000,mmid,        0,0,0,0,0,0)
  XTREG( 85,340, 2, 4, 4,0x0260,0x0007 & ~1,-2, 2,0x1000,ibreakenable,0,0,0,0,0,0)
  XTREG( 86,344, 1, 4, 4,0x0261,0x0007 & ~1,-2, 2,0x1000,memctl,      0,0,0,0,0,0)
  XTREG( 87,348, 6, 4, 4,0x0263,0x0007 & ~1,-2, 2,0x1000,atomctl,     0,0,0,0,0,0)
  XTREG( 88,352,32, 4, 4,0x0268,0x0007 & ~1,-2, 2,0x1000,ddr,         0,0,0,0,0,0)
  XTREG( 89,356,32, 4, 4,0x0280,0x0007 & ~1,-2, 2,0x1000,ibreaka0,    0,0,0,0,0,0)
  XTREG( 90,360,32, 4, 4,0x0281,0x0007 & ~1,-2, 2,0x1000,ibreaka1,    0,0,0,0,0,0)
  XTREG( 91,364,32, 4, 4,0x0290,0x0007 & ~1,-2, 2,0x1000,dbreaka0,    0,0,0,0,0,0)
  XTREG( 92,368,32, 4, 4,0x0291,0x0007 & ~1,-2, 2,0x1000,dbreaka1,    0,0,0,0,0,0)
  XTREG( 93,372,32, 4, 4,0x02a0,0x0007 & ~1,-2, 2,0x1000,dbreakc0,    0,0,0,0,0,0)
  XTREG( 94,376,32, 4, 4,0x02a1,0x0007 & ~1,-2, 2,0x1000,dbreakc1,    0,0,0,0,0,0)
  XTREG( 95,380,32, 4, 4,0x02b1,0x0007 & ~1,-2, 2,0x1000,epc1,        0,0,0,0,0,0)
  XTREG( 96,384,32, 4, 4,0x02b2,0x0007 & ~1,-2, 2,0x1000,epc2,        0,0,0,0,0,0)
  XTREG( 97,388,32, 4, 4,0x02b3,0x0007 & ~1,-2, 2,0x1000,epc3,        0,0,0,0,0,0)
  XTREG( 98,392,32, 4, 4,0x02b4,0x0007 & ~1,-2, 2,0x1000,epc4,        0,0,0,0,0,0)
  XTREG( 99,396,32, 4, 4,0x02b5,0x0007 & ~1,-2, 2,0x1000,epc5,        0,0,0,0,0,0)
  XTREG(100,400,32, 4, 4,0x02b6,0x0007 & ~1,-2, 2,0x1000,epc6,        0,0,0,0,0,0)
  XTREG(101,404,32, 4, 4,0x02b7,0x0007 & ~1,-2, 2,0x1000,epc7,        0,0,0,0,0,0)
  XTREG(102,408,32, 4, 4,0x02c0,0x0007 & ~1,-2, 2,0x1000,depc,        0,0,0,0,0,0)
  XTREG(103,412,19, 4, 4,0x02c2,0x0007 & ~1,-2, 2,0x1000,eps2,        0,0,0,0,0,0)
  XTREG(104,416,19, 4, 4,0x02c3,0x0007 & ~1,-2, 2,0x1000,eps3,        0,0,0,0,0,0)
  XTREG(105,420,19, 4, 4,0x02c4,0x0007 & ~1,-2, 2,0x1000,eps4,        0,0,0,0,0,0)
  XTREG(106,424,19, 4, 4,0x02c5,0x0007 & ~1,-2, 2,0x1000,eps5,        0,0,0,0,0,0)
  XTREG(107,428,19, 4, 4,0x02c6,0x0007 & ~1,-2, 2,0x1000,eps6,        0,0,0,0,0,0)
  XTREG(108,432,19, 4, 4,0x02c7,0x0007 & ~1,-2, 2,0x1000,eps7,        0,0,0,0,0,0)
  XTREG(109,436,32, 4, 4,0x02d1,0x0007 & ~1,-2, 2,0x1000,excsave1,    0,0,0,0,0,0)
  XTREG(110,440,32, 4, 4,0x02d2,0x0007 & ~1,-2, 2,0x1000,excsave2,    0,0,0,0,0,0)
  XTREG(111,444,32, 4, 4,0x02d3,0x0007 & ~1,-2, 2,0x1000,excsave3,    0,0,0,0,0,0)
  XTREG(112,448,32, 4, 4,0x02d4,0x0007 & ~1,-2, 2,0x1000,excsave4,    0,0,0,0,0,0)
  XTREG(113,452,32, 4, 4,0x02d5,0x0007 & ~1,-2, 2,0x1000,excsave5,    0,0,0,0,0,0)
  XTREG(114,456,32, 4, 4,0x02d6,0x0007 & ~1,-2, 2,0x1000,excsave6,    0,0,0,0,0,0)
  XTREG(115,460,32, 4, 4,0x02d7,0x0007 & ~1,-2, 2,0x1000,excsave7,    0,0,0,0,0,0)
  XTREG(116,464,32, 4, 4,0x02e2,0x000b & ~1,-2, 2,0x1000,interrupt,   0,0,0,0,0,0)
  XTREG(117,468,32, 4, 4,0x02e2,0x000d & ~1,-2, 2,0x1000,intset,      0,0,0,0,0,0)
  XTREG(118,472,32, 4, 4,0x02e3,0x000d & ~1,-2, 2,0x1000,intclear,    0,0,0,0,0,0)
  XTREG(119,476,32, 4, 4,0x02e4,0x0007 & ~1,-2, 2,0x1000,intenable,   0,0,0,0,0,0)
  XTREG(120,480,32, 4, 4,0x02e7,0x0007 & ~1,-2, 2,0x1000,vecbase,     0,0,0,0,0,0)
  XTREG(121,484, 6, 4, 4,0x02e8,0x0007 & ~1,-2, 2,0x1000,exccause,    0,0,0,0,0,0)
  XTREG(122,488,12, 4, 4,0x02e9,0x0003 & ~1,-2, 2,0x1000,debugcause,  0,0,0,0,0,0)
  XTREG(123,492,32, 4, 4,0x02ea,0x000f & ~1,-2, 2,0x1000,ccount,      0,0,0,0,0,0)
  XTREG(124,496,32, 4, 4,0x02eb,0x0003 & ~1,-2, 2,0x1000,prid,        0,0,0,0,0,0)
  XTREG(125,500,32, 4, 4,0x02ec,0x000f & ~1,-2, 2,0x1000,icount,      0,0,0,0,0,0)
  XTREG(126,504, 4, 4, 4,0x02ed,0x0007 & ~1,-2, 2,0x1000,icountlevel, 0,0,0,0,0,0)
  XTREG(127,508,32, 4, 4,0x02ee,0x0007 & ~1,-2, 2,0x1000,excvaddr,    0,0,0,0,0,0)
  XTREG(128,512,32, 4, 4,0x02f0,0x000f & ~1,-2, 2,0x1000,ccompare0,   0,0,0,0,0,0)
  XTREG(129,516,32, 4, 4,0x02f1,0x000f & ~1,-2, 2,0x1000,ccompare1,   0,0,0,0,0,0)
  XTREG(130,520,32, 4, 4,0x02f2,0x000f & ~1,-2, 2,0x1000,ccompare2,   0,0,0,0,0,0)
  XTREG(131,524,32, 4, 4,0x02f4,0x0007 & ~1,-2, 2,0x1000,misc0,       0,0,0,0,0,0)
  XTREG(132,528,32, 4, 4,0x02f5,0x0007 & ~1,-2, 2,0x1000,misc1,       0,0,0,0,0,0)
  XTREG(133,532,32, 4, 4,0x02f6,0x0007 & ~1,-2, 2,0x1000,misc2,       0,0,0,0,0,0)
  XTREG(134,536,32, 4, 4,0x02f7,0x0007 & ~1,-2, 2,0x1000,misc3,       0,0,0,0,0,0)
  XTREG(135,540,32, 4, 4,0x0000,0x0006 & ~1,-2, 8,0x0100,a0,          0,0,0,0,0,0)
  XTREG(136,544,32, 4, 4,0x0001,0x0006 & ~1,-2, 8,0x0100,a1,          0,0,0,0,0,0)
  XTREG(137,548,32, 4, 4,0x0002,0x0006 & ~1,-2, 8,0x0100,a2,          0,0,0,0,0,0)
  XTREG(138,552,32, 4, 4,0x0003,0x0006 & ~1,-2, 8,0x0100,a3,          0,0,0,0,0,0)
  XTREG(139,556,32, 4, 4,0x0004,0x0006 & ~1,-2, 8,0x0100,a4,          0,0,0,0,0,0)
  XTREG(140,560,32, 4, 4,0x0005,0x0006 & ~1,-2, 8,0x0100,a5,          0,0,0,0,0,0)
  XTREG(141,564,32, 4, 4,0x0006,0x0006 & ~1,-2, 8,0x0100,a6,          0,0,0,0,0,0)
  XTREG(142,568,32, 4, 4,0x0007,0x0006 & ~1,-2, 8,0x0100,a7,          0,0,0,0,0,0)
  XTREG(143,572,32, 4, 4,0x0008,0x0006 & ~1,-2, 8,0x0100,a8,          0,0,0,0,0,0)
  XTREG(144,576,32, 4, 4,0x0009,0x0006 & ~1,-2, 8,0x0100,a9,          0,0,0,0,0,0)
  XTREG(145,580,32, 4, 4,0x000a,0x0006 & ~1,-2, 8,0x0100,a10,         0,0,0,0,0,0)
  XTREG(146,584,32, 4, 4,0x000b,0x0006 & ~1,-2, 8,0x0100,a11,         0,0,0,0,0,0)
  XTREG(147,588,32, 4, 4,0x000c,0x0006 & ~1,-2, 8,0x0100,a12,         0,0,0,0,0,0)
  XTREG(148,592,32, 4, 4,0x000d,0x0006 & ~1,-2, 8,0x0100,a13,         0,0,0,0,0,0)
  XTREG(149,596,32, 4, 4,0x000e,0x0006 & ~1,-2, 8,0x0100,a14,         0,0,0,0,0,0)
  XTREG(150,600,32, 4, 4,0x000f,0x0006 & ~1,-2, 8,0x0100,a15,         0,0,0,0,0,0)
  XTREG(151,604, 1, 1, 1,0x0010,0x0006 & ~1,-2, 6,0x1010,b0,
            0,0,&xtensa_mask0,0,0,0)
  XTREG(152,605, 1, 1, 1,0x0011,0x0006 & ~1,-2, 6,0x1010,b1,
            0,0,&xtensa_mask1,0,0,0)
  XTREG(153,606, 1, 1, 1,0x0012,0x0006 & ~1,-2, 6,0x1010,b2,
            0,0,&xtensa_mask2,0,0,0)
  XTREG(154,607, 1, 1, 1,0x0013,0x0006 & ~1,-2, 6,0x1010,b3,
            0,0,&xtensa_mask3,0,0,0)
  XTREG(155,608, 1, 1, 1,0x0014,0x0006 & ~1,-2, 6,0x1010,b4,
            0,0,&xtensa_mask4,0,0,0)
  XTREG(156,609, 1, 1, 1,0x0015,0x0006 & ~1,-2, 6,0x1010,b5,
            0,0,&xtensa_mask5,0,0,0)
  XTREG(157,610, 1, 1, 1,0x0016,0x0006 & ~1,-2, 6,0x1010,b6,
            0,0,&xtensa_mask6,0,0,0)
  XTREG(158,611, 1, 1, 1,0x0017,0x0006 & ~1,-2, 6,0x1010,b7,
            0,0,&xtensa_mask7,0,0,0)
  XTREG(159,612, 1, 1, 1,0x0018,0x0006 & ~1,-2, 6,0x1010,b8,
            0,0,&xtensa_mask8,0,0,0)
  XTREG(160,613, 1, 1, 1,0x0019,0x0006 & ~1,-2, 6,0x1010,b9,
            0,0,&xtensa_mask9,0,0,0)
  XTREG(161,614, 1, 1, 1,0x001a,0x0006 & ~1,-2, 6,0x1010,b10,
            0,0,&xtensa_mask10,0,0,0)
  XTREG(162,615, 1, 1, 1,0x001b,0x0006 & ~1,-2, 6,0x1010,b11,
            0,0,&xtensa_mask11,0,0,0)
  XTREG(163,616, 1, 1, 1,0x001c,0x0006 & ~1,-2, 6,0x1010,b12,
            0,0,&xtensa_mask12,0,0,0)
  XTREG(164,617, 1, 1, 1,0x001d,0x0006 & ~1,-2, 6,0x1010,b13,
            0,0,&xtensa_mask13,0,0,0)
  XTREG(165,618, 1, 1, 1,0x001e,0x0006 & ~1,-2, 6,0x1010,b14,
            0,0,&xtensa_mask14,0,0,0)
  XTREG(166,619, 1, 1, 1,0x001f,0x0006 & ~1,-2, 6,0x1010,b15,
            0,0,&xtensa_mask15,0,0,0)
  XTREG(167,620, 4, 4, 4,0x2008,0x0006 & ~1,-2, 6,0x1010,psintlevel,
            0,0,&xtensa_mask16,0,0,0)
  XTREG(168,624, 1, 4, 4,0x2009,0x0006 & ~1,-2, 6,0x1010,psum,
            0,0,&xtensa_mask17,0,0,0)
  XTREG(169,628, 1, 4, 4,0x200a,0x0006 & ~1,-2, 6,0x1010,pswoe,
            0,0,&xtensa_mask18,0,0,0)
  XTREG(170,632, 1, 4, 4,0x200b,0x0006 & ~1,-2, 6,0x1010,psexcm,
            0,0,&xtensa_mask19,0,0,0)
  XTREG(171,636, 2, 4, 4,0x200c,0x0006 & ~1,-2, 6,0x1010,pscallinc,
            0,0,&xtensa_mask20,0,0,0)
  XTREG(172,640, 4, 4, 4,0x200d,0x0006 & ~1,-2, 6,0x1010,psowb,
            0,0,&xtensa_mask21,0,0,0)
  XTREG(173,644,40, 8, 4,0x200e,0x0006 & ~1,-2, 6,0x1010,acc,
            0,0,&xtensa_mask22,0,0,0)
  XTREG_END
};



#ifdef XTENSA_CONFIG_INSTANTIATE
XTENSA_CONFIG_INSTANTIATE(rmap,0)
#endif

