/**
 * https://www.codewars.com/kata/5592e3bd57b64d00f3000047/train/c
 *
 * Test:
 * ./cubes 441 should be 6
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long findNb(long long m) {
	long long sum = 0;
	long long i = 0;
	while (m - sum > 0) {
		sum += pow(i, 3);
		i++;
	}

	return sum == m ? i - 1 : -1;
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		fprintf(stdout, "%s <long long>\n", argv[0]);
		return 1;
	}

	long long res = findNb(atol(argv[1]));
	fprintf(stdout, "%lld\n", res);

	return 0;
}