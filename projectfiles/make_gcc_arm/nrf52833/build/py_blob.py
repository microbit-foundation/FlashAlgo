"""
 Flash OS Routines (Automagically Generated)
 Copyright (c) 2017-2017 ARM Limited

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

    # Flash algorithm as a hex string
    'instructions':
        "094ad2f8043413f0ff030bd0d2f8042542b1064a0649d80748bf11605b0802f1"
        "0402f8d1704700bf00000140000601403546526e002070470020704710b5094c"
        "0223c4f804350123c4f80c35d4f80034db0702d4fff7d4fff8e70020c4f80405"
        "10bd00bf00e0014010b50b4c0223b0f1102fc4f8043526bf0123c4f81435c4f8"
        "0805fff7bdffd4f80034db07f9d50020c4f8040510bd00bf00e00140f8b50f4e"
        "01238d08c6f804351446871ae31922681a600434d6f80834da0702d4fff7a0ff"
        "f8e7013df2d1d6f80034db0702d4fff797fff8e70020c6f80405f8bd00e00140",

    # Relative function addresses
    'pc_init': 0x35,
    'pc_unInit': 0x39,
    'pc_program_page': 0x9d,
    'pc_erase_sector': 0x69,
    'pc_eraseAll': 0x3d,

    # Relative region addresses and sizes
    'ro_start': 0x0,
    'ro_size': 0xe0,
    'rw_start': 0xe0,
    'rw_size': 0x0,
    'zi_start': 0xe0,
    'zi_size': 0x0,

    # Flash information
    'flash_start': 0x0,
    'flash_size': 0x80000,
    'page_size': 0x4,
    'sector_sizes': (
        (0x0, 0x80000),
        (0x10001000, 0x308),
    )
}
