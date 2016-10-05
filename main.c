#include <stdio.h>
#include <array_tools.h>

int main() {
	int A[] = {5, 4, 2, 7, 9, 100, 3, 2, 2, 31, 24};
	printf("%d", select_rank(10, A, 11, false));
}
