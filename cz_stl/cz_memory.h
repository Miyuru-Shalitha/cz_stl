#ifndef CZ_MEMORY_H
#define CZ_MEMORY_H

#include <stdlib.h>

#include "cz_types.h"

#define KB(kb) kb * 1024
#define MB(mb) mb * 1024 * 1024
#define GB(gb) gb * 1024 * 1024 * 1024

typedef struct {
	usize capacity;
	usize size;
	u8* space;
} Arena;

Arena arena_create(usize initial_capacity) {
	void* arena_space = malloc(initial_capacity);

	if (!arena_space) {
		// TODO(Miyuru): Handle error
	}

	return (Arena) {
		.capacity = initial_capacity,
		.size = 0,
		.space = arena_space
	};
}

void* arena_alloc(Arena* arena, usize size) {
	if (arena->size + size > arena->capacity) {
		// TODO(Miyuru): Handle error
		return NULL;
	}

	void* space = arena->space + arena->size;
	arena->size += size;
	return space;
}

void arena_reset(Arena* arena) {
	arena->size = 0;
}

void arena_free(Arena* arena) {
	free(arena->space);
	arena->space = NULL;
	arena->capacity = 0;
	arena->size = 0;
}

#endif