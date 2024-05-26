/**
 * @file:      main.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sample data structure (16 bytes)
typedef struct sample_data_t
{
    uint8_t int_data;
    char *text_data;
} sample_data_t;

// A function that asserts a condition and displays a message on failure
void puddle_assert(const bool condition, const char *message)
{
    if (condition)
    {
        return;
    }

    fprintf(stderr, "puddle::assertion_failure: %s\n", message);
    exit(EXIT_FAILURE);
}

int main(void)
{
    // Create a puddle object
    puddle_t puddle;

    // Create a memory block that will be used by the puddle library
    uint8_t puddle_memory[2 * sizeof(sample_data_t)];

    // Initialize the puddle library
    puddle_initialize(&puddle, puddle_memory, sizeof(puddle_memory));

    // Allocate memory for a sample data structure
    sample_data_t *const sample_data1 = puddle_allocate(&puddle, sizeof(sample_data_t));
    sample_data_t *const sample_data2 = puddle_allocate(&puddle, sizeof(sample_data_t));

    // Check if memory was allocated
    puddle_assert(sample_data1 != NULL, "memory not allocated for sample_data1");
    puddle_assert(sample_data2 != NULL, "memory not allocated for sample_data2");

    // Set values for the sample data structures
    sample_data1->int_data = 42;
    sample_data1->text_data = "Hello, World!";
    sample_data2->int_data = 69;
    sample_data2->text_data = "Goodbye, World!";

    // Check if the values in the sample data structures are correct
    puddle_assert(
        sample_data1->int_data == 42,
        "sample_data1->int_data is different then expected"
    );

    puddle_assert(
        strcmp(sample_data1->text_data, "Hello, World!") == 0,
        "sample_data1->text_data is different then expected"
    );

    puddle_assert(
        sample_data2->int_data == 69,
        "sample_data2->int_data is different then expected"
    );

    puddle_assert(
        strcmp(sample_data2->text_data, "Goodbye, World!") == 0,
        "sample_data2->text_data is different then expected"
    );

    // Try to allocate one more object
    sample_data_t *const sample_data3 = puddle_allocate(&puddle, sizeof(sample_data_t));

    // Check if memory was allocated. This should fail, since there isn't enough space in the puddle memory
    puddle_assert(sample_data3 == NULL, "memory not allocated for sample_data3");

    // Exit and return 0
    return 0;
}
