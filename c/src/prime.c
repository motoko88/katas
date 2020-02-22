#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Check if a number is prime.
 * @param  num Any number
 * @return If the number is prime or not.
 */
bool is_prime(int num) {
	for (size_t i = 3; i < sqrt(num); i += 2) {
		if (num % i == 0) {
			return false;
		}
	}

    return true;
}

/**
 * Checks for trivial non-prime values.
 * @param  num Any number
 * @return If the number is prime or not.
 */
bool trivial_prime_check(int num) {
	if (num < 2) {
		return false;
	} else if (num == 2) {
		return true;
	} else if (num % 2 == 0) {
		return false;
	}

	return is_prime(num);
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		fprintf(stdout, "Usage: %s\n", argv[0]);
		return 1;
	}

	bool res = trivial_prime_check(atoi(argv[1]));
	if (res) {
		fprintf(stdout, "true\n");
	} else {
		fprintf(stdout, "false\n");
	}

	return 0;
}