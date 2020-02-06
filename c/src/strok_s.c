/**
 * Tokenizes All the Words in a Phrase
 */
char** tokenize(const char* phrase) {
	char** tokens = (char**) malloc(sizeof(char*) * word_count(phrase, DELIM) * MAX_MORSE_SIZE);
	if (tokens == NULL) {
		exit(0);
	}
	size_t token_i = 0;

	char* buffer = (char*) malloc(sizeof(char) * strlen(phrase));
	if (buffer == NULL) {
		exit(0);
	}
	size_t buffer_i = 0;

	char previous = phrase[0];
	for (size_t i = 0; i < strlen(phrase); ++i) {
		if (phrase[i] != DELIM) {
			buffer[buffer_i] = phrase[i];
			buffer_i++;
		} else if (previous != DELIM) {
			buffer[buffer_i] = '\0';
			buffer_i = 0;
			tokens[token_i] = (char*) malloc(sizeof(char) * strlen(buffer));
			strncpy(tokens[token_i], buffer, strlen(buffer));
			token_i++;
		}

		previous = phrase[i];
	}

	buffer[buffer_i] = '\0'; // Gives Last Word
	tokens[token_i] = (char*) malloc(sizeof(char) * strlen(buffer));
	strncpy(tokens[token_i], buffer, strlen(buffer));
	return tokens;
}