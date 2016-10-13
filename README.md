array-tools
===================
Collection of utility functions operating on arrays, written in C


# Functions


### `void print_int_array(int array[], size_t n)`

Print contents of `array`

* `array` is an array of integers
* `n` is the size of `array`


### `int random_int(int lower_bound, int upper_bound);`

Generate a uniformly random integer between a given range

* `lower_bound` is the minimum value that can be returned
* `upper_bound` is the maximum value that can be returned

**Returns** A random integer


### `void random_int_array(int output[], size_t n, int min_val, int max_val);`

Fill an array with uniformly random integers between a given range

* `output` is an empty integer array
* `n` is the size of `output`
* `min_val` is the minimum value that an integer in the array may have
* `max_val` is the maximum value that an integer in the array may have


### `void random_permutation(int output[], size_t n)`

Fill an array with a random permutation of the integers `{1, 2, ..., n-1, n}`

* `output` is an empty integer array
* `n` is the size of `output`


### `void ordered_array(int output[], size_t n)`

Fill an array with the first `n` positive integers `{1, 2, ..., n-1, n}`

* `output` is an empty integer array
* `n` is the number of elements in `array`


### `int new_rank(int array[], size_t n, int value)`

Find the index of an ordered array  at which a a new integer should be inserted while maintaining the numerical ordering

* `array` is an ***ordered*** array of integers
* `n` is the size of `array`
* `value` is an integer for which the appropriate index must be found

**Returns** An integer representing the index at which `value` should be inserted to maintain numerical ordering in `array`


### `void insertion_sort(int array[], size_t n)`

Sort an array in place using the insertion sort method

* `array` is an array of integers
* `n` is the size of `array`


### `int select_rank(int k, int array[], size_t n, bool forceLinear)`

Select the element from an integer array with a specific numerical rank. `0` is the minimum value, rank `n-1` is the maximum value.

* `k` is the numerical rank
* `array` is an array of integers
* `n` is the size of `array`
* `forceLinear` is a boolean that specifies the algorithm used. It runs a guaranteed linear algorithm if `true`, a worst-case linear algorithm if `false`. In practice, a setting of `false` will result in a faster result

**Returns** An integer value from `array` with the specified rank `k`

# Credits
(c) 2016 Steven Watts
