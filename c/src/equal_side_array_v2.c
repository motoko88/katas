/**
 * Cameron Brenke
 * Time: 878ms Passed: 50 Failed: 0
 */

#include <stdio.h>
#include <time.h>

int find_even_index(const int *values, size_t length) {
	int left = 0;
	int right = 0;
	for (size_t i = 1; i < length; ++i) {
		right += values[i];
	}

	size_t i = 0;
	for (; i < length - 1; ++i) {
		if (left == right) {
			return i;
		}

		left += values[i];
		right -= values[i + 1];
	}

	return left == right ? i : -1;
}

int main(int argc, char const *argv[]) {
	if (argc != 1) {
		printf("Usage: %s\n", argv[0]);
		return 1;
	}

	const int array[] = {1,100,50,-51,1,1}; // Expected 1

	clock_t t;
    t = clock();
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

	int arr[] = { 10,-80,10,10,15,35,20 };
	result = find_even_index(arr, 7);
	printf("%d\n", result);
	return 0;
}