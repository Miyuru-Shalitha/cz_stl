#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdio.h>
#include "cz_types.h"

typedef struct {
	usize length;
	const i8* chars;
} String;

typedef struct {
	usize length;
	i8* chars;
} HeapString;

inline String string_make(const i8* string) {
	usize len = 0;

	while (string[len] != '\0') {
		len++;
	}

	return (String) {
		.chars = string,
		.length = len
	};
}

inline HeapString heap_string_make(const i8* string) {
	usize len = 0;

	while (string[len] != '\0') {
		len++;
	}

	i8* string_space = malloc(len + 1);

	if (!string_space) {
		return (HeapString) {
			.chars = NULL,
			.length = 0
		};
	}

	for (u32 i = 0; i <= len; i++) {
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
	usize total_length = string_a->length + string_b->length;
	i8* new_string_space = malloc(total_length + 1);
	
	if (!new_string_space) {
		return (HeapString) {
			.chars = NULL,
			.length = -1
		};
	}

	for (usize i = 0; i < string_a->length; i++) {
		new_string_space[i] = string_a->chars[i];
	}

	for (usize i = 0; i <= string_b->length; i++) {
		new_string_space[string_a->length + i] = string_b->chars[i];
	}

	return (HeapString) {
		.chars = new_string_space,
		.length = total_length
	};
}

inline HeapString heap_string_concat(HeapString* string_a, HeapString* string_b) {
	usize total_length = string_a->length + string_b->length;
	i8* new_string_space = malloc(total_length + 1);

	if (!new_string_space) {
		return (HeapString) {
			.chars = NULL,
			.length = -1
		};
	}

	for (usize i = 0; i < string_a->length; i++) {
		new_string_space[i] = string_a->chars[i];
	}

	for (usize i = 0; i <= string_b->length; i++) {
		new_string_space[string_a->length + i] = string_b->chars[i];
	}

	return (HeapString) {
		.chars = new_string_space,
		.length = total_length
	};
}

#endif