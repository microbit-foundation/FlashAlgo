/* Flash OS Routines (Automagically Generated)
 * Copyright (c) 2009-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

static const uint32_t nrf52833_flash_prog_blob[] = {
    0xE00ABE00, 
    0xf8d24a09, 0xf0133404, 0xd00b03ff, 0x2504f8d2, 0x4a06b142, 0x07d84906, 0x6011bf48, 0xf102085b,
    0xd1f80204, 0xbf004770, 0x40010000, 0x40010600, 0x6e524635, 0x47702000, 0x47702000, 0x4c09b510,
    0xf8c42302, 0x23013504, 0x350cf8c4, 0x3400f8d4, 0xd40207db, 0xffd4f7ff, 0x2000e7f8, 0x0504f8c4,
    0xbf00bd10, 0x4001e000, 0x4c0bb510, 0xf1b02302, 0xf8c42f10, 0xbf263504, 0xf8c42301, 0xf8c43514,
    0xf7ff0508, 0xf8d4ffbd, 0x07db3400, 0x2000d5f9, 0x0504f8c4, 0xbf00bd10, 0x4001e000, 0x4e0fb5f8,
    0x088d2301, 0x3504f8c6, 0x1a874614, 0x682219e3, 0x3404601a, 0x3408f8d6, 0xd40207da, 0xffa0f7ff,
    0x3d01e7f8, 0xf8d6d1f2, 0x07db3400, 0xf7ffd402, 0xe7f8ff97, 0xf8c62000, 0xbdf80504, 0x4001e000
};

// Start address of flash
static const uint32_t flash_start = 0x00000000;
// Size of flash
static const uint32_t flash_size = 0x00080000;

/**
* List of start and size for each size of flash sector - even indexes are start, odd are size
* The size will apply to all sectors between the listed address and the next address
* in the list.
* The last pair in the list will have sectors starting at that address and ending
* at address flash_start + flash_size.
*/
static const uint32_t sectors_info[] = {
    0x00000000, 0x00080000,
    0x10001000, 0x00000308,
};

static const program_target_t flash = {
    0x20000039, // Init
    0x2000003d, // UnInit
    0x20000041, // EraseChip
    0x2000006d, // EraseSector
    0x200000a1, // ProgramPage
    0x120000003, // Verify

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20000001,
        0x200000e4,
        0x20000300
    },

    0x20000000 + 0x00000A00,  // mem buffer location
    0x20000000,               // location to write prog_blob in target RAM
    sizeof(nrf52833_flash_prog_blob),   // prog_blob size
    nrf52833_flash_prog_blob,           // address of prog_blob
    0x00000004       // ram_to_flash_bytes_to_be_written
};