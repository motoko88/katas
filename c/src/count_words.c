/**
 * Cameron Brenke
 */

#include <stdio.h>
#include <string.h>

const size_t word_count(const char* phrase, const char delim) {
	size_t words = 0;
	char previous = phrase[0];
	for (size_t i = 0; i < strlen(phrase); ++i) {
		if (phrase[i] == delim && previous != delim) {
			words++;
		}

		previous = phrase[i];
	}

	if (previous != delim) {
		words++;
	}

	return words;
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		printf("Usage: %s\n", argv[0]);
		return 1;
	}

	fprintf(stdout, "%zu\n", word_count(argv[1], ' '));

	return 0;
}