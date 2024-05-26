/**
 * @file:      puddle.h
 *
 * @date:      26 May 2024
 *
 * @author:    Kostoski Stefan
 *
 * @copyright: Copyright (c) 2024 Kostoski Stefan.
 *             This work is licensed under the terms of the MIT license.
 *             For a copy, see <https://opensource.org/license/MIT>.
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct puddle_t
{
    uint8_t *next;
    uint8_t *end;
    uint32_t capacity;
} puddle_t;

void puddle_initialize(puddle_t *const puddle, void *memory, const uint32_t capacity);
void *puddle_allocate(puddle_t *const puddle, const uint32_t number_of_bytes);
