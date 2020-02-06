#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		printf("Usage: %s\n", argv[0]);
		return 1;
	}

	char* copy = (char*) malloc(sizeof(char) * strlen(argv[1]));
	strncpy(copy, argv[1], strlen(argv[1]));

    char* token = strtok(copy, " ");
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

	return 0;
}