#include <stdio.h>
#include <stdlib.h>

#include "array_utilities.h"



/////////////////////////////////
//// ARRAY UTILITY FUNCTIONS ////
/////////////////////////////////

void print_int_array(int array[], size_t n) {
	for (int i=0; i<n; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int random_int(int lower_bound, int upper_bound) {
	return lower_bound + (rand() % (upper_bound - lower_bound + 1));
}

void random_int_array(int output[], size_t n, int min_val, int max_val) {
	for (int i=0; i<n; ++i) {
		output[i] = random_int(min_val, max_val);
	}
}

void random_permutation(int output[], size_t n) {
	// Initialises array as [0, 1, 2, ... n - 1]
	for (int i=0; i<n; ++i) {
		output[i] = i;
	}

	// Randomly shuffles permutation in linear time
	for (int i=n-1; i>0; --i) {
		int random_index = random_int(0, i);

		// Switch out chosen value
		int temp = output[random_index];
		output[random_index] = output[i];
		output[i] = temp;
	}
}

void ordered_array(int output[], size_t n) {
	for (int i=0; i<n; ++i) {
		output[i] = i;
	}
}

int new_rank(int array[], size_t n, int value) {
	int lower = -1;
	int upper = n;

	int middle = (lower + upper) / 2;

	while (upper - lower > 1) {
		if (value > array[middle]) {
			lower = middle;
		}
		else if (value < array[middle]) {
			upper = middle;
		}
		else {
			return middle;
		}

		middle = (lower + upper) / 2;
	}

	return lower + 1;
}