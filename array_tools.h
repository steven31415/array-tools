#ifndef ARRAY_UTILITIES_H_
#define ARRAY_UTILITIES_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Print out a given array of integers
void print_int_array(int array[], size_t n);

// Return a random integer between a lower and upper bound inclusive
int random_int(int lower_bound, int upper_bound);

// Return a random array of integers
void random_int_array(int output[], size_t n, int min_val, int max_val);

// Return a random permutation as an array
void random_permutation(int output[], size_t n);

// Return an array of the form [0, 1, 2, ..., n-1]
void ordered_array(int output[], size_t n);

// Return index at which a new integer should be inserted into an ordered array of integers
// in order to maintain the numerical ordering
int new_rank(int array[], size_t n, int value);

#endif