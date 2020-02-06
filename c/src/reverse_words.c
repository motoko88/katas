#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* reverseWord(const char* text) {
	for (size_t i = 0; i < strlen(text); ++i) {
		printf("%c", text[i]);
	}

	return NULL;
}

char* reverseWords(const char* text) {
	char* buffer = (char*) malloc(sizeof(char) * strlen(text));


	for (size_t i = 0; i < strlen(text); ++i) {
		printf("%c", text[i]);
		if (text[i] == ' ') {
			reverseWord(text);
		}
	}

	return NULL;
}

int main(int argc, char const *argv[]) {
	const char* test = "This is an example";
	reverseWords(test);
	return 0;
}