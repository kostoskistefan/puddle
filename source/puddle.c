/**
 * @file:      puddle.c
 *
 * @date:      26 May 2024
 *
 * @author:    Kostoski Stefan
 *
 * @copyright: Copyright (c) 2024 Kostoski Stefan.
 *             This work is licensed under the terms of the MIT license.
 *             For a copy, see <https://opensource.org/license/MIT>.
 */

#include "../include/puddle.h"
#include <stdlib.h>

void puddle_initialize(puddle_t *const puddle, void *memory, const uint32_t capacity)
{
    puddle->capacity = capacity;
    puddle->next = (uint8_t *) memory;
    puddle->end = puddle->next + puddle->capacity;
}

void *puddle_allocate(puddle_t *const puddle, const uint32_t number_of_bytes)
{
    if (puddle->end - puddle->next < number_of_bytes)
    {
        return NULL;
    }

    void *allocated_memory = (void *) puddle->next;
    puddle->next += number_of_bytes;
    return allocated_memory;
}
