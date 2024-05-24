#ifndef STRING_HPP
#define STRING_HPP

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	const char* chars;
	size_t length;
} String;

typedef struct {
	char* chars;
	size_t length;
} HeapString;

inline String string_make(const char* string) {
	size_t len = 0;

	while (string[len] != '\0') {
		len++;
	}

	return (String) {
		.chars = string,
		.length = len
	};
}

inline HeapString heap_string_make(const char* string) {
	size_t len = 0;

	while (string[len] != '\0') {
		len++;
	}

	char* string_space = malloc(len + 1);

	if (!string_space) {
		return (HeapString) {
			.chars = NULL,
			.length = 0
		};
	}

	for (unsigned int i = 0; i <= len; i++) {
		string_space[i] = string[i];
	}

	return (HeapString) {
		.chars = string_space,
		.length = len
	};
}

inline void heap_string_free(HeapString* string) {
	free(string->chars);
	string->chars = NULL;
	string->length = -1;
}

inline HeapString string_concat(String* string_a, String* string_b) {
	size_t total_length = string_a->length + string_b->length;
	char* new_string_space = malloc(total_length + 1);
	
	if (!new_string_space) {
		return (HeapString) {
			.chars = NULL,
			.length = -1
		};
	}

	for (size_t i = 0; i < string_a->length; i++) {
		new_string_space[i] = string_a->chars[i];
	}

	for (size_t i = 0; i <= string_b->length; i++) {
		new_string_space[string_a->length + i] = string_b->chars[i];
	}

	return (HeapString) {
		.chars = new_string_space,
		.length = total_length
	};
}

inline HeapString heap_string_concat(HeapString* string_a, HeapString* string_b) {
	size_t total_length = string_a->length + string_b->length;
	char* new_string_space = malloc(total_length + 1);

	if (!new_string_space) {
		return (HeapString) {
			.chars = NULL,
			.length = -1
		};
	}

	for (size_t i = 0; i < string_a->length; i++) {
		new_string_space[i] = string_a->chars[i];
	}

	for (size_t i = 0; i <= string_b->length; i++) {
		new_string_space[string_a->length + i] = string_b->chars[i];
	}

	return (HeapString) {
		.chars = new_string_space,
		.length = total_length
	};
}

#endif