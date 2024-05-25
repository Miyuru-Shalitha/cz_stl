#ifndef CZ_LIST_H
#define CZ_LIST_H

#include <stdlib.h>

#include "cz_types.h"

typedef struct {
	void** array;
	usize capacity;
	usize size;
} List;

List list_create(usize initial_capacity) {
	if (initial_capacity <= 0) {
		return (List) {
			.array = NULL,
			.capacity = 0,
			.size = 0
		};
	}

	void* list_space = malloc(sizeof(void*) * initial_capacity);

	if (!list_space) {
		return (List) {
			.array = NULL,
			.capacity = 0,
			.size = 0
		};
	}

	return (List) {
		.array = list_space,
		.capacity = initial_capacity,
		.size = 0
	};
}

void list_free(List* list) {
	free(list->array);
	list->array = NULL;
	list->capacity = 0;
	list->size = 0;
}

bool list_append(List* list, void* item) {
	if (list->array == NULL) {
		return false;
	}

	if (list->size == list->capacity) {
		list->capacity = list->capacity * 2;
		void* new_list_space = realloc(list->array, sizeof(void*) * list->capacity);

		if (!new_list_space) {
			return false;
		}

		list->array = new_list_space;
	}

	list->array[list->size++] = item;
	return true;
}

void list_pop(List* list, usize index) {
	// TODO(Miyuru): Implement this.
}

#define list_get_item(list, T, index) *((T**)list.array)[index]
#define list_ptr_get_item(list, T, index) *((T**)list->array)[index]

#endif