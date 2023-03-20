/* mbed Microcontroller Library
 * Copyright (c) 2017 ARM Limited
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

#include "flash_api.h"
#include "flash_data.h"
#include "critical.h"

// This file is automagically generated

#if DEVICE_FLASH

// This is a flash algo binary blob. It is PIC (position independent code) that should be stored in RAM
static uint32_t FLASH_ALGO[] = {
    0xf8d24a09, 0xf0133404, 0xd00b03ff, 0x2504f8d2, 0x4a06b142, 0x07d84906, 0x6011bf48, 0xf102085b,
    0xd1f80204, 0xbf004770, 0x40010000, 0x40010600, 0x6e524635, 0x47702000, 0x47702000, 0x4c09b510,
    0xf8c42302, 0x23013504, 0x350cf8c4, 0x3400f8d4, 0xd40207db, 0xffd4f7ff, 0x2000e7f8, 0x0504f8c4,
    0xbf00bd10, 0x4001e000, 0x4c0bb510, 0xf1b02302, 0xf8c42f10, 0xbf263504, 0xf8c42301, 0xf8c43514,
    0xf7ff0508, 0xf8d4ffbd, 0x07db3400, 0x2000d5f9, 0x0504f8c4, 0xbf00bd10, 0x4001e000, 0x4e0fb5f8,
    0x088d2301, 0x3504f8c6, 0x1a874614, 0x682219e3, 0x3404601a, 0x3408f8d6, 0xd40207da, 0xffa0f7ff,
    0x3d01e7f8, 0xf8d6d1f2, 0x07db3400, 0xf7ffd402, 0xe7f8ff97, 0xf8c62000, 0xbdf80504, 0x4001e000
};

static const flash_algo_t flash_algo_config = {
    .init = 0x35,
    .uninit = 0x39,
    .erase_sector = 0x69,
    .program_page = 0x9d,
    .static_base = 0xe0,
    .algo_blob = FLASH_ALGO
};

static const sector_info_t sectors_info[] = {
    {0x0, 0x80000},
    {0x10001000, 0x308},
};

static const flash_target_config_t flash_target_config = {
    .page_size  = 0x4,
    .flash_start = 0x0,
    .flash_size = 0x80000,
    .sectors = sectors_info,
    .sector_info_count = sizeof(sectors_info) / sizeof(sector_info_t)
};

void flash_set_target_config(flash_t *obj)
{
    obj->flash_algo = &flash_algo_config;
    obj->target_config = &flash_target_config;
}

#endif