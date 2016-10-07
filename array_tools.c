#include "array_tools.h"

void print_int_array(int array[], size_t n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int random_int(int lower_bound, int upper_bound) {
	return lower_bound + (rand() % (upper_bound - lower_bound + 1));
}

void random_int_array(int output[], size_t n, int min_val, int max_val) {
	for (int i = 0; i < n; ++i) {
		output[i] = random_int(min_val, max_val);
	}
}

void random_permutation(int output[], size_t n) {
	// Initialises array as [0, 1, 2, ... n - 1]
	for (int i = 0; i < n; ++i) {
		output[i] = i;
	}

	// Randomly shuffles permutation in linear time
	for (int i = n-1; i > 0; --i) {
		int random_index = random_int(0, i);

		// Switch out chosen value
		int temp = output[random_index];
		output[random_index] = output[i];
		output[i] = temp;
	}
}

void ordered_array(int output[], size_t n) {
	for (int i = 0; i < n; ++i) {
		output[i] = i;
	}
}

int new_rank(int array[], size_t n, int value) {
	int lower = -1, upper = n, middle = (lower + upper) / 2;

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

void insertion_sort(int array[], size_t n) {
	int i, key, j;
	for (i = 1; i < n; ++i)
	{
	   key = array[i];
	   j = i-1;

	   while (j >= 0 && array[j] > key)
	   {
	       array[j+1] = array[j];
	       j = j-1;
	   }
	   array[j+1] = key;
	}
}

int select_rank(int k, int array[], size_t n, bool forceLinear) {
	if (n <= 0 || k < 0 || k >= n) {
		return INT_MAX;
	}

	int s1[n], s3[n], m;
	size_t s1_size = 0, s2_size = 0, s3_size = 0;

	if (forceLinear) {
		int ds = 5;
		size_t divisionsCount = 1 + (int) ((n - 1) / ds);
		size_t finalDivisionSize = ((n % ds) == 0 ? ds : (n % ds));
		int M[divisionsCount];
		int division[ds];
		
		for (int i = 0; i < divisionsCount - 1; ++i) {
			for (int j = 0; j < ds; ++j) {
				division[j] = array[ds * i + j];
			}

			insertion_sort(division, ds);

			M[i] = division[((int) ((ds + 1) / 2)) - 1];
		}

		for (int j = 0; j < finalDivisionSize; ++j) {
			division[j] = array[5 * (divisionsCount - 1) + j];
		}

		insertion_sort(division, finalDivisionSize);

		M[divisionsCount - 1] = division[((int) ((finalDivisionSize + 1) / 2)) - 1];
		
		if (divisionsCount <= 1) {
			m = M[0];
		}
		else {
			m = select_rank(((int) ((divisionsCount + 1) / 2)) - 1, M, divisionsCount, true);
		}
	}
	else {
		m = array[(int) (rand() * n / RAND_MAX)];
	}

	for (int i = 0; i < n; ++i) {
		if (array[i] < m) {
			s1[s1_size++] = array[i];
		}
		else if (array[i] == m) {
			s2_size++;
		}
		else if (array[i] > m) {
			s3[s3_size++] = array[i];
		}
	}

	if (s1_size > k) {
		return select_rank(k, s1, s1_size, forceLinear);
	}
	else if (s1_size + s2_size > k) {
		return m;
	}
	else {
		return select_rank(k - s1_size - s2_size, s3, s3_size, forceLinear);
	}
}