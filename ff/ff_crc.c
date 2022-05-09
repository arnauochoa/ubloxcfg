// flipflip's CRC stuff
//
// Copyright (c) 2022 Philippe Kehl (flipflip at oinkzwurgl dot org),
// https://oinkzwurgl.org/hacking/ubloxcfg
//
// This program is free software: you can redistribute it and/or modify it under the terms of the
// GNU General Public License as published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
// even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.
// If not, see <https://www.gnu.org/licenses/>.

#include "ff_stuff.h"
#include "ff_crc.h"

/* ****************************************************************************************************************** */

// CRC tables generated using https://github.com/madler/crcany.git
// See also https://reveng.sourceforge.io/crc-catalogue/all.htm
// rm -f src/*spartn*; ./mincrc < spartn.txt | ./crcadd

// ---------------------------------------------------------------------------------------------------------------------

// width=4 poly=0x9 init=0x0 refin=true refout=true xorout=0x0 check=0x0 residue=0x0 name="FF-SPARTN-4"
static const uint8_t sSpartnCrc4[256] =
{
    0x0, 0xb, 0x5, 0xe, 0xa, 0x1, 0xf, 0x4, 0x7, 0xc, 0x2, 0x9, 0xd, 0x6, 0x8, 0x3,
    0xe, 0x5, 0xb, 0x0, 0x4, 0xf, 0x1, 0xa, 0x9, 0x2, 0xc, 0x7, 0x3, 0x8, 0x6, 0xd,
    0xf, 0x4, 0xa, 0x1, 0x5, 0xe, 0x0, 0xb, 0x8, 0x3, 0xd, 0x6, 0x2, 0x9, 0x7, 0xc,
    0x1, 0xa, 0x4, 0xf, 0xb, 0x0, 0xe, 0x5, 0x6, 0xd, 0x3, 0x8, 0xc, 0x7, 0x9, 0x2,
    0xd, 0x6, 0x8, 0x3, 0x7, 0xc, 0x2, 0x9, 0xa, 0x1, 0xf, 0x4, 0x0, 0xb, 0x5, 0xe,
    0x3, 0x8, 0x6, 0xd, 0x9, 0x2, 0xc, 0x7, 0x4, 0xf, 0x1, 0xa, 0xe, 0x5, 0xb, 0x0,
    0x2, 0x9, 0x7, 0xc, 0x8, 0x3, 0xd, 0x6, 0x5, 0xe, 0x0, 0xb, 0xf, 0x4, 0xa, 0x1,
    0xc, 0x7, 0x9, 0x2, 0x6, 0xd, 0x3, 0x8, 0xb, 0x0, 0xe, 0x5, 0x1, 0xa, 0x4, 0xf,
    0x9, 0x2, 0xc, 0x7, 0x3, 0x8, 0x6, 0xd, 0xe, 0x5, 0xb, 0x0, 0x4, 0xf, 0x1, 0xa,
    0x7, 0xc, 0x2, 0x9, 0xd, 0x6, 0x8, 0x3, 0x0, 0xb, 0x5, 0xe, 0xa, 0x1, 0xf, 0x4,
    0x6, 0xd, 0x3, 0x8, 0xc, 0x7, 0x9, 0x2, 0x1, 0xa, 0x4, 0xf, 0xb, 0x0, 0xe, 0x5,
    0x8, 0x3, 0xd, 0x6, 0x2, 0x9, 0x7, 0xc, 0xf, 0x4, 0xa, 0x1, 0x5, 0xe, 0x0, 0xb,
    0x4, 0xf, 0x1, 0xa, 0xe, 0x5, 0xb, 0x0, 0x3, 0x8, 0x6, 0xd, 0x9, 0x2, 0xc, 0x7,
    0xa, 0x1, 0xf, 0x4, 0x0, 0xb, 0x5, 0xe, 0xd, 0x6, 0x8, 0x3, 0x7, 0xc, 0x2, 0x9,
    0xb, 0x0, 0xe, 0x5, 0x1, 0xa, 0x4, 0xf, 0xc, 0x7, 0x9, 0x2, 0x6, 0xd, 0x3, 0x8,
    0x5, 0xe, 0x0, 0xb, 0xf, 0x4, 0xa, 0x1, 0x2, 0x9, 0x7, 0xc, 0x8, 0x3, 0xd, 0x6
};

uint32_t crcSpartn4(const uint8_t *data, const int len)
{
    uint32_t crc = 0;
    for (int ix = 0; ix < len; ix++)
    {
        crc = sSpartnCrc4[crc ^ data[ix]];
    }
    return crc & 0x0000000f;
}

// ---------------------------------------------------------------------------------------------------------------------

// width=24 poly=0x864cfb init=0x000000 refin=false refout=false xorout=0x000000 check=0x000000 residue=0x000000 name="FF-SPARTN-24"
static const uint32_t sSpartnCrc24[256] =
{
    0x000000, 0x864cfb, 0x8ad50d, 0x0c99f6, 0x93e6e1, 0x15aa1a, 0x1933ec, 0x9f7f17,
    0xa18139, 0x27cdc2, 0x2b5434, 0xad18cf, 0x3267d8, 0xb42b23, 0xb8b2d5, 0x3efe2e,
    0xc54e89, 0x430272, 0x4f9b84, 0xc9d77f, 0x56a868, 0xd0e493, 0xdc7d65, 0x5a319e,
    0x64cfb0, 0xe2834b, 0xee1abd, 0x685646, 0xf72951, 0x7165aa, 0x7dfc5c, 0xfbb0a7,
    0x0cd1e9, 0x8a9d12, 0x8604e4, 0x00481f, 0x9f3708, 0x197bf3, 0x15e205, 0x93aefe,
    0xad50d0, 0x2b1c2b, 0x2785dd, 0xa1c926, 0x3eb631, 0xb8faca, 0xb4633c, 0x322fc7,
    0xc99f60, 0x4fd39b, 0x434a6d, 0xc50696, 0x5a7981, 0xdc357a, 0xd0ac8c, 0x56e077,
    0x681e59, 0xee52a2, 0xe2cb54, 0x6487af, 0xfbf8b8, 0x7db443, 0x712db5, 0xf7614e,
    0x19a3d2, 0x9fef29, 0x9376df, 0x153a24, 0x8a4533, 0x0c09c8, 0x00903e, 0x86dcc5,
    0xb822eb, 0x3e6e10, 0x32f7e6, 0xb4bb1d, 0x2bc40a, 0xad88f1, 0xa11107, 0x275dfc,
    0xdced5b, 0x5aa1a0, 0x563856, 0xd074ad, 0x4f0bba, 0xc94741, 0xc5deb7, 0x43924c,
    0x7d6c62, 0xfb2099, 0xf7b96f, 0x71f594, 0xee8a83, 0x68c678, 0x645f8e, 0xe21375,
    0x15723b, 0x933ec0, 0x9fa736, 0x19ebcd, 0x8694da, 0x00d821, 0x0c41d7, 0x8a0d2c,
    0xb4f302, 0x32bff9, 0x3e260f, 0xb86af4, 0x2715e3, 0xa15918, 0xadc0ee, 0x2b8c15,
    0xd03cb2, 0x567049, 0x5ae9bf, 0xdca544, 0x43da53, 0xc596a8, 0xc90f5e, 0x4f43a5,
    0x71bd8b, 0xf7f170, 0xfb6886, 0x7d247d, 0xe25b6a, 0x641791, 0x688e67, 0xeec29c,
    0x3347a4, 0xb50b5f, 0xb992a9, 0x3fde52, 0xa0a145, 0x26edbe, 0x2a7448, 0xac38b3,
    0x92c69d, 0x148a66, 0x181390, 0x9e5f6b, 0x01207c, 0x876c87, 0x8bf571, 0x0db98a,
    0xf6092d, 0x7045d6, 0x7cdc20, 0xfa90db, 0x65efcc, 0xe3a337, 0xef3ac1, 0x69763a,
    0x578814, 0xd1c4ef, 0xdd5d19, 0x5b11e2, 0xc46ef5, 0x42220e, 0x4ebbf8, 0xc8f703,
    0x3f964d, 0xb9dab6, 0xb54340, 0x330fbb, 0xac70ac, 0x2a3c57, 0x26a5a1, 0xa0e95a,
    0x9e1774, 0x185b8f, 0x14c279, 0x928e82, 0x0df195, 0x8bbd6e, 0x872498, 0x016863,
    0xfad8c4, 0x7c943f, 0x700dc9, 0xf64132, 0x693e25, 0xef72de, 0xe3eb28, 0x65a7d3,
    0x5b59fd, 0xdd1506, 0xd18cf0, 0x57c00b, 0xc8bf1c, 0x4ef3e7, 0x426a11, 0xc426ea,
    0x2ae476, 0xaca88d, 0xa0317b, 0x267d80, 0xb90297, 0x3f4e6c, 0x33d79a, 0xb59b61,
    0x8b654f, 0x0d29b4, 0x01b042, 0x87fcb9, 0x1883ae, 0x9ecf55, 0x9256a3, 0x141a58,
    0xefaaff, 0x69e604, 0x657ff2, 0xe33309, 0x7c4c1e, 0xfa00e5, 0xf69913, 0x70d5e8,
    0x4e2bc6, 0xc8673d, 0xc4fecb, 0x42b230, 0xddcd27, 0x5b81dc, 0x57182a, 0xd154d1,
    0x26359f, 0xa07964, 0xace092, 0x2aac69, 0xb5d37e, 0x339f85, 0x3f0673, 0xb94a88,
    0x87b4a6, 0x01f85d, 0x0d61ab, 0x8b2d50, 0x145247, 0x921ebc, 0x9e874a, 0x18cbb1,
    0xe37b16, 0x6537ed, 0x69ae1b, 0xefe2e0, 0x709df7, 0xf6d10c, 0xfa48fa, 0x7c0401,
    0x42fa2f, 0xc4b6d4, 0xc82f22, 0x4e63d9, 0xd11cce, 0x575035, 0x5bc9c3, 0xdd8538
};

uint32_t crcSpartn24(const uint8_t *data, const int len)
{
    uint32_t crc = 0;
    for (int ix = 0; ix < len; ix++)
    {
        crc = (crc << 8) ^ sSpartnCrc24[((crc >> 16) ^ data[ix]) & 0xff];
    }
    return crc & 0x00ffffff;
}

// ---------------------------------------------------------------------------------------------------------------------

inline uint32_t crcRtcm3(const uint8_t *data, const int len)
{
    return crcSpartn24(data, len);
}

// ---------------------------------------------------------------------------------------------------------------------

// width=8 poly=0x07 init=0x00 refin=false refout=false xorout=0x0 check=0x0 residue=0x0 name="FF-SPARTN-8"
static const uint8_t sCrcSpartn8[256] =
{
    0x00, 0x07, 0x0e, 0x09, 0x1c, 0x1b, 0x12, 0x15, 0x38, 0x3f, 0x36, 0x31, 0x24,
    0x23, 0x2a, 0x2d, 0x70, 0x77, 0x7e, 0x79, 0x6c, 0x6b, 0x62, 0x65, 0x48, 0x4f,
    0x46, 0x41, 0x54, 0x53, 0x5a, 0x5d, 0xe0, 0xe7, 0xee, 0xe9, 0xfc, 0xfb, 0xf2,
    0xf5, 0xd8, 0xdf, 0xd6, 0xd1, 0xc4, 0xc3, 0xca, 0xcd, 0x90, 0x97, 0x9e, 0x99,
    0x8c, 0x8b, 0x82, 0x85, 0xa8, 0xaf, 0xa6, 0xa1, 0xb4, 0xb3, 0xba, 0xbd, 0xc7,
    0xc0, 0xc9, 0xce, 0xdb, 0xdc, 0xd5, 0xd2, 0xff, 0xf8, 0xf1, 0xf6, 0xe3, 0xe4,
    0xed, 0xea, 0xb7, 0xb0, 0xb9, 0xbe, 0xab, 0xac, 0xa5, 0xa2, 0x8f, 0x88, 0x81,
    0x86, 0x93, 0x94, 0x9d, 0x9a, 0x27, 0x20, 0x29, 0x2e, 0x3b, 0x3c, 0x35, 0x32,
    0x1f, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0d, 0x0a, 0x57, 0x50, 0x59, 0x5e, 0x4b,
    0x4c, 0x45, 0x42, 0x6f, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7d, 0x7a, 0x89, 0x8e,
    0x87, 0x80, 0x95, 0x92, 0x9b, 0x9c, 0xb1, 0xb6, 0xbf, 0xb8, 0xad, 0xaa, 0xa3,
    0xa4, 0xf9, 0xfe, 0xf7, 0xf0, 0xe5, 0xe2, 0xeb, 0xec, 0xc1, 0xc6, 0xcf, 0xc8,
    0xdd, 0xda, 0xd3, 0xd4, 0x69, 0x6e, 0x67, 0x60, 0x75, 0x72, 0x7b, 0x7c, 0x51,
    0x56, 0x5f, 0x58, 0x4d, 0x4a, 0x43, 0x44, 0x19, 0x1e, 0x17, 0x10, 0x05, 0x02,
    0x0b, 0x0c, 0x21, 0x26, 0x2f, 0x28, 0x3d, 0x3a, 0x33, 0x34, 0x4e, 0x49, 0x40,
    0x47, 0x52, 0x55, 0x5c, 0x5b, 0x76, 0x71, 0x78, 0x7f, 0x6a, 0x6d, 0x64, 0x63,
    0x3e, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2c, 0x2b, 0x06, 0x01, 0x08, 0x0f, 0x1a,
    0x1d, 0x14, 0x13, 0xae, 0xa9, 0xa0, 0xa7, 0xb2, 0xb5, 0xbc, 0xbb, 0x96, 0x91,
    0x98, 0x9f, 0x8a, 0x8d, 0x84, 0x83, 0xde, 0xd9, 0xd0, 0xd7, 0xc2, 0xc5, 0xcc,
    0xcb, 0xe6, 0xe1, 0xe8, 0xef, 0xfa, 0xfd, 0xf4, 0xf3
};

uint32_t crcSpartn8(const uint8_t *data, const int len)
{
    uint32_t crc = 0;
    for (int ix = 0; ix < len; ix++)
    {
        crc = sCrcSpartn8[crc ^ data[ix]];
    }
    return crc & 0x000000ff;
}

// ---------------------------------------------------------------------------------------------------------------------

// width=16 poly=0x1021 init=0x0000 refin=false refout=false xorout=0x0000 check=0x0000 residue=0x0000 name="FF-SPARTN-16"
static const uint16_t sCrcSpartn16[256] =
{
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129,
    0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252,
    0x52b5, 0x4294, 0x72f7, 0x62d6, 0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c,
    0xf3ff, 0xe3de, 0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
    0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672,
    0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738,
    0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861,
    0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
    0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc,
    0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a, 0x6ca6, 0x7c87, 0x4ce4, 0x5cc5,
    0x2c22, 0x3c03, 0x0c60, 0x1c41, 0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b,
    0x8d68, 0x9d49, 0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
    0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 0x9188, 0x81a9,
    0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3,
    0x5004, 0x4025, 0x7046, 0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c,
    0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d, 0x34e2, 0x24c3,
    0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8,
    0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676,
    0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c,
    0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16,
    0x0af1, 0x1ad0, 0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b,
    0x9de8, 0x8dc9, 0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
    0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, 0x6e17, 0x7e36,
    0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

uint32_t crcSpartn16(const uint8_t *data, const int len)
{
    uint32_t crc = 0;
    for (int ix = 0; ix < len; ix++)
    {
        crc = (crc << 8) ^ sCrcSpartn16[((crc >> 8) ^ data[ix]) & 0xff];
    }
    return crc & 0x0000ffff;
}

// ---------------------------------------------------------------------------------------------------------------------

// width=32 poly=0x04c11db7 init=0xffffffff refin=false refout=false xorout=0xffffffff check=0x00000000 residue=0x000000 name="FF-SPARTN-32"
static const uint32_t sCrcSpartn32[256] =
{
    0xb1f7404b, 0xb5365dfc, 0xb8757b25, 0xbcb46692, 0xa2f33697, 0xa6322b20,
    0xab710df9, 0xafb0104e, 0x97ffadf3, 0x933eb044, 0x9e7d969d, 0x9abc8b2a,
    0x84fbdb2f, 0x803ac698, 0x8d79e041, 0x89b8fdf6, 0xfde69b3b, 0xf927868c,
    0xf464a055, 0xf0a5bde2, 0xeee2ede7, 0xea23f050, 0xe760d689, 0xe3a1cb3e,
    0xdbee7683, 0xdf2f6b34, 0xd26c4ded, 0xd6ad505a, 0xc8ea005f, 0xcc2b1de8,
    0xc1683b31, 0xc5a92686, 0x29d4f6ab, 0x2d15eb1c, 0x2056cdc5, 0x2497d072,
    0x3ad08077, 0x3e119dc0, 0x3352bb19, 0x3793a6ae, 0x0fdc1b13, 0x0b1d06a4,
    0x065e207d, 0x029f3dca, 0x1cd86dcf, 0x18197078, 0x155a56a1, 0x119b4b16,
    0x65c52ddb, 0x6104306c, 0x6c4716b5, 0x68860b02, 0x76c15b07, 0x720046b0,
    0x7f436069, 0x7b827dde, 0x43cdc063, 0x470cddd4, 0x4a4ffb0d, 0x4e8ee6ba,
    0x50c9b6bf, 0x5408ab08, 0x594b8dd1, 0x5d8a9066, 0x8571303c, 0x81b02d8b,
    0x8cf30b52, 0x883216e5, 0x967546e0, 0x92b45b57, 0x9ff77d8e, 0x9b366039,
    0xa379dd84, 0xa7b8c033, 0xaafbe6ea, 0xae3afb5d, 0xb07dab58, 0xb4bcb6ef,
    0xb9ff9036, 0xbd3e8d81, 0xc960eb4c, 0xcda1f6fb, 0xc0e2d022, 0xc423cd95,
    0xda649d90, 0xdea58027, 0xd3e6a6fe, 0xd727bb49, 0xef6806f4, 0xeba91b43,
    0xe6ea3d9a, 0xe22b202d, 0xfc6c7028, 0xf8ad6d9f, 0xf5ee4b46, 0xf12f56f1,
    0x1d5286dc, 0x19939b6b, 0x14d0bdb2, 0x1011a005, 0x0e56f000, 0x0a97edb7,
    0x07d4cb6e, 0x0315d6d9, 0x3b5a6b64, 0x3f9b76d3, 0x32d8500a, 0x36194dbd,
    0x285e1db8, 0x2c9f000f, 0x21dc26d6, 0x251d3b61, 0x51435dac, 0x5582401b,
    0x58c166c2, 0x5c007b75, 0x42472b70, 0x468636c7, 0x4bc5101e, 0x4f040da9,
    0x774bb014, 0x738aada3, 0x7ec98b7a, 0x7a0896cd, 0x644fc6c8, 0x608edb7f,
    0x6dcdfda6, 0x690ce011, 0xd8fba0a5, 0xdc3abd12, 0xd1799bcb, 0xd5b8867c,
    0xcbffd679, 0xcf3ecbce, 0xc27ded17, 0xc6bcf0a0, 0xfef34d1d, 0xfa3250aa,
    0xf7717673, 0xf3b06bc4, 0xedf73bc1, 0xe9362676, 0xe47500af, 0xe0b41d18,
    0x94ea7bd5, 0x902b6662, 0x9d6840bb, 0x99a95d0c, 0x87ee0d09, 0x832f10be,
    0x8e6c3667, 0x8aad2bd0, 0xb2e2966d, 0xb6238bda, 0xbb60ad03, 0xbfa1b0b4,
    0xa1e6e0b1, 0xa527fd06, 0xa864dbdf, 0xaca5c668, 0x40d81645, 0x44190bf2,
    0x495a2d2b, 0x4d9b309c, 0x53dc6099, 0x571d7d2e, 0x5a5e5bf7, 0x5e9f4640,
    0x66d0fbfd, 0x6211e64a, 0x6f52c093, 0x6b93dd24, 0x75d48d21, 0x71159096,
    0x7c56b64f, 0x7897abf8, 0x0cc9cd35, 0x0808d082, 0x054bf65b, 0x018aebec,
    0x1fcdbbe9, 0x1b0ca65e, 0x164f8087, 0x128e9d30, 0x2ac1208d, 0x2e003d3a,
    0x23431be3, 0x27820654, 0x39c55651, 0x3d044be6, 0x30476d3f, 0x34867088,
    0xec7dd0d2, 0xe8bccd65, 0xe5ffebbc, 0xe13ef60b, 0xff79a60e, 0xfbb8bbb9,
    0xf6fb9d60, 0xf23a80d7, 0xca753d6a, 0xceb420dd, 0xc3f70604, 0xc7361bb3,
    0xd9714bb6, 0xddb05601, 0xd0f370d8, 0xd4326d6f, 0xa06c0ba2, 0xa4ad1615,
    0xa9ee30cc, 0xad2f2d7b, 0xb3687d7e, 0xb7a960c9, 0xbaea4610, 0xbe2b5ba7,
    0x8664e61a, 0x82a5fbad, 0x8fe6dd74, 0x8b27c0c3, 0x956090c6, 0x91a18d71,
    0x9ce2aba8, 0x9823b61f, 0x745e6632, 0x709f7b85, 0x7ddc5d5c, 0x791d40eb,
    0x675a10ee, 0x639b0d59, 0x6ed82b80, 0x6a193637, 0x52568b8a, 0x5697963d,
    0x5bd4b0e4, 0x5f15ad53, 0x4152fd56, 0x4593e0e1, 0x48d0c638, 0x4c11db8f,
    0x384fbd42, 0x3c8ea0f5, 0x31cd862c, 0x350c9b9b, 0x2b4bcb9e, 0x2f8ad629,
    0x22c9f0f0, 0x2608ed47, 0x1e4750fa, 0x1a864d4d, 0x17c56b94, 0x13047623,
    0x0d432626, 0x09823b91, 0x04c11d48, 0x000000ff
};

uint32_t crcSpartn32(const uint8_t *data, const int len)
{
    uint32_t crc = 0;
    for (int ix = 0; ix < len; ix++)
    {
        crc = (crc << 8) ^ sCrcSpartn32[((crc >> 24) ^ data[ix]) & 0xff];
    }
    return crc;
}

// ---------------------------------------------------------------------------------------------------------------------

// https://docs.novatel.com/OEM7/Content/Messages/32_Bit_CRC.htm
uint32_t crcNovatel32(const uint8_t *data, const int len)
{
    uint32_t crc = 0;
    for (int i = 0; i < len; i++)
    {
        crc ^= data[i];
        for (int j = 0; j < 8; j++)
        {
            if (crc & 1)
            {
                 crc= (crc >> 1) ^ 0xedb88320u;
            }
            else
            {
                crc >>= 1;
            }
        }
    }
    return crc;
}

/* ****************************************************************************************************************** */
// eof
