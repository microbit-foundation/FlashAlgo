"""
 Flash OS Routines (Automagically Generated)
 Copyright (c) 2017-2018 ARM Limited

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
"""

flash_algo = {
    'load_address' : 0x20000000,

    # Flash algorithm as a hex string
    'instructions': [
    0xE00ABE00, 
    0xf8d24a09, 0xf0133404, 0xd00b03ff, 0x2504f8d2, 0x4a06b142, 0x07d84906, 0x6011bf48, 0xf102085b,
    0xd1f80204, 0xbf004770, 0x40010000, 0x40010600, 0x6e524635, 0x47702000, 0x47702000, 0x4c09b510,
    0xf8c42302, 0x23013504, 0x350cf8c4, 0x3400f8d4, 0xd40207db, 0xffd4f7ff, 0x2000e7f8, 0x0504f8c4,
    0xbf00bd10, 0x4001e000, 0x4c0bb510, 0xf1b02302, 0xf8c42f10, 0xbf263504, 0xf8c42301, 0xf8c43514,
    0xf7ff0508, 0xf8d4ffbd, 0x07db3400, 0x2000d5f9, 0x0504f8c4, 0xbf00bd10, 0x4001e000, 0x4e0fb5f8,
    0x088d2301, 0x3504f8c6, 0x1a874614, 0x682219e3, 0x3404601a, 0x3408f8d6, 0xd40207da, 0xffa0f7ff,
    0x3d01e7f8, 0xf8d6d1f2, 0x07db3400, 0xf7ffd402, 0xe7f8ff97, 0xf8c62000, 0xbdf80504, 0x4001e000
    ],

    # Relative function addresses
    'pc_init': 0x20000039,
    'pc_unInit': 0x2000003d,
    'pc_program_page': 0x200000a1,
    'pc_erase_sector': 0x2000006d,
    'pc_eraseAll': 0x20000041,

    'static_base' : 0x20000000 + 0x00000004 + 0x000000e0,
    'begin_stack' : 0x20000300,
    'begin_data' : 0x20000000 + 0x1000,
    'page_size' : 0x4,
    'analyzer_supported' : False,
    'analyzer_address' : 0x00000000,
    'page_buffers' : [0x20001000, 0x20001004],   # Enable double buffering
    'min_program_length' : 0x4,

    # Flash information
    'flash_start': 0x0,
    'flash_size': 0x80000,
    'sector_sizes': (
        (0x0, 0x80000),
        (0x10001000, 0x308),
    )
}
