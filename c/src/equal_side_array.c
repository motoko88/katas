/**
 * Cameron Brenke
 * Time: 977ms Passed: 50 Failed: 0
 */

#include <stdio.h>
#include <time.h>

int sum(const int *values, size_t start, size_t end) {
	size_t sum = 0;
	for (size_t i = start; i < end; i++) {
		sum += values[i];
	}

	return sum;
}

int find_even_index(const int *values, size_t length) {
	for (size_t i = 0; i < length; i++) {
		if (sum(values, 0, i) == sum(values, i + 1, length)) {
			return i;
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	if (argc != 1) {
		printf("Usage: %s\n", argv[0]);
		return 1;
	}

	clock_t t;
    t = clock();
	const int array[] = {1,100,50,-51,1,1}; // Expected 1
	int result = find_even_index(array, 6);
	printf("%d\n", result);

	const int array_1[] = {1,2,3,4,3,2,1}; // Expected 3
	result = find_even_index(array_1, 7);
	printf("%d\n", result);

	const int corner[] = {20,10,-80,10,10,15,35};
	result = find_even_index(corner, 7);
	t = clock() - t;
	printf("%d\n", result);

	const double time_taken = ((double)t) / CLOCKS_PER_SEC; // In seconds
	printf("%f [s]\n", time_taken);
	return 0;
}