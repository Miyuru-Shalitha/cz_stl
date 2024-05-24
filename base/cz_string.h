#ifndef STRING_HPP
#define STRING_HPP

#include <stdlib.h>
#include <stdio.h>

typedef enum {
	STRING_VALID_STACK,
	STRING_VALID_HEAP,
	STRING_INVALID
} StringFlag;

typedef struct {
	const char* chars;
	size_t length;
	StringFlag flag;
} String;

inline String string_make(const char* string) {
	size_t len = 0;

	while (string[len] != '\0') {
		len++;
	}

	return (String) {
		.chars = string,
		.length = len,
		.flag = STRING_VALID_STACK
	};
}

inline void string_free(String* string) {
	if (string->flag == STRING_VALID_HEAP) {
		puts("FREE");
		free(string->chars); // BUG
		string->chars = NULL;
		string->length = 0;
		string->flag = STRING_INVALID;
	}
}

inline String string_concat(String* string_a, String* string_b) {
	char* new_string_space = malloc(string_a->length + string_b->length + 1);
	
	if (!new_string_space) {
		return (String) {
			.chars = "",
			.length = 0,
			.flag = STRING_INVALID
		};
	}

	for (size_t i = 0; i < string_a->length; i++) {
		new_string_space[i] = string_a->chars[i];
	}

	size_t total_length = string_a->length + string_b->length;

	for (size_t i = 0; i < total_length; i++) {
		new_string_space[string_a->length + i] = string_b->chars[i];
	}

	string_free(string_a);
	string_free(string_b);

	return (String) {
		.chars = new_string_space,
		.length = total_length,
		.flag = STRING_VALID_HEAP
	};
}

#endif