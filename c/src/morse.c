/**
 * Cameron Brenke
 *
 * Compile:
 * gcc morse.c -Wall -o morse
 * clang morse.c -Wall -o morse
 *
 * Sample Tests:
 * TODO
 * ./morse ".... . -.--   .--- ..- -.. ."
 *
 * TODO
 * ./morse "----. -.- .. --... .... ..--.. -.-- -.- .----. -- .--. -.-- / .-..-. -.-- .. -..-. -.--. .-.. ---.. --.- ...-..-"
 *
 * GSOS!7AER&@I7VK$+'!ZKTL
 * ./morse "--. ... --- ... -.-.-- --... .- . .-. .-... .--.-. .. --... ...- -.- ...-..- .-.-. .----. -.-.-- --.. -.- - .-.."
 *
 * "SOS! THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG."
 * ./morse "      ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-  "
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DELIM ' '
#define SYLLABARY 55
#define MAX_MORSE_SIZE 9
#define MAX_ASCII_SIZE 3

const char* morse[55] = {
	".-", "-...", "-.-.", "-..", ".",
	"..-.", "--.", "....", "..", ".---",
	"-.-", ".-..", "--", "-.", "---",
	".--.", "--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-", "-.--",
	"--..", "-----", ".----", "..---", "...--",
	"....-", ".....", "-....", "--...", "---..",
	"----.", ".-.-.-", "--..--", "..--..", ".----.",
	"-.-.--", "-..-.", "-.--.", "-.--.-", ".-...",
	"---...", "-.-.-.", "-...-", ".-.-.", "-....-",
	"..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."
};
const char* ascii[55] = {
	"A", "B", "C", "D", "E",
	"F", "G", "H", "I",  "J",
	"K", "L", "M",  "N",  "O",
	"P", "Q", "R", "S", "T",
	"U", "V", "W", "X", "Y",
	"Z", "0", "1", "2", "3",
	"4", "5", "6", "7", "8",
	"9", ".", ",", "?", "'",
	"!", "/", "(", ")", "&",
	":", ";", "=", "+", "-",
	"_", "\"", "$", "@", "SOS"
};

_Bool lin_search(const int query, const int* array, const size_t len);
int* source_delimeters(const char* phrase, const char delim, size_t* len);
size_t words(const char* phrase, const char delim);
char** tokenize(const char* phrase);
char* decode_morse(const char* morse_code);

/**
 * Linear Search
 */
_Bool lin_search(const int query, const int* array, const size_t len) {
	for (size_t i = 0; i < len; ++i) {
		if (array[i] == query) {
			return true;
		}
	}

	return false;
}

/**
 * Finds Purposeful Delimeters
 *
 * A purposeful delimeter indicates that the source
 * syllabary has a delimeter that isn't used to merely separate tokens, but instead is
 * an empty token itself which should be translated to an empty token in a
 * target syllabary.
 */
int* source_delimeters(const char* phrase, const char delim, size_t* len) {
	const size_t arr_size = words(phrase, DELIM);
	int* space_arr = (int*) malloc(sizeof(int) * (arr_size - 1));
	if (space_arr == NULL) {
		exit(0);
	}

	// Set all values to -1 to indicate that no purposeful delimeter exists (yet).
	for (size_t i = 0; i < arr_size; ++i) {
		space_arr[i] = -1;
	}
	size_t space_arr_i = 0;

	size_t words = 0;
	char previous = phrase[0];
	size_t previous_delim_count = 0;
	for (size_t i = 0; i < strlen(phrase); ++i) {
		if (phrase[i] == delim && previous != delim) {
			words++;
			previous_delim_count = 0;
		} else if (previous == delim) {
			previous_delim_count++;
			if (previous_delim_count == 2 && words > 0) {
				space_arr[space_arr_i] = words;
				space_arr_i++;
				previous_delim_count = 0;
			}
		}

		previous = phrase[i];
	}

	*len = words;
	return space_arr;
}

/**
 * Counts the Words in a Phrase
 */
size_t words(const char* phrase, const char delim) {
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

char* decode_morse(const char* morse_code) {
	char* morse_code_copy = (char*) malloc(sizeof(char) * (strlen(morse_code) + 1));
	strncpy(morse_code_copy, morse_code, strlen(morse_code));

	size_t spaces_len = 0;
	int* spaces = source_delimeters(morse_code, DELIM, &spaces_len);

	char* token = strtok(morse_code_copy, " ");
	const size_t tokens = words(morse_code_copy, DELIM);

	char* return_string = (char*) malloc(sizeof(char) * MAX_ASCII_SIZE * tokens + spaces_len);
	if (return_string == NULL) {
		exit(0);
	}
	size_t return_string_i = 0;

	size_t i = 0;
	while (token) {

		if (lin_search(i, spaces, spaces_len)) {
			return_string[return_string_i] = DELIM;
			return_string_i++;
		}

		size_t compare_len;
		// Linearly searches through the Morse Code syllabary
		for (size_t j = 0; j < SYLLABARY; ++j) {
			compare_len = strlen(token) > strlen(morse[j]) ? strlen(token) : strlen(morse[j]);
			if (strncmp(token, morse[j], compare_len) == 0) {
				for (size_t k = 0; k < strlen(ascii[j]); ++k) {
					return_string[return_string_i] = ascii[j][k];
					return_string_i++;
				}

				break;
			}
		}

		token = strtok(NULL, " ");
		++i;
	}

	return_string[return_string_i] = '\0';
	free(spaces);
	free(morse_code_copy);
	return return_string;
}

int main(int argc, char const* argv[]) {
	if (argc != 2) {
		printf("Usage: %s\n", argv[0]);
		return 1;
	}

	const char* morse_code = argv[1];
	char* result = decode_morse(morse_code);
	printf("|%s|\n", result);
	free((char*)result);
	return 0;
}