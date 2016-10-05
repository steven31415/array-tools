#ifndef ARRAY_TOOLS_H_
#define ARRAY_TOOLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>

void print_int_array(int array[], size_t n);

int random_int(int lower_bound, int upper_bound);

void random_int_array(int output[], size_t n, int min_val, int max_val);

void random_permutation(int output[], size_t n);

void ordered_array(int output[], size_t n);

int new_rank(int array[], size_t n, int value);

void insertion_sort(int array[], size_t n);

int select_rank(int k, int array[], size_t n, bool forceLinear);

#endif