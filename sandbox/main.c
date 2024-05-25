#include <stdio.h>
#include <stdlib.h>
#include <cz_string.h>
#include <cz_types.h>
#include <cz_list.h>
#include <cz_memory.h>

int main(void) {
	Arena assets_arena = arena_create(MB(1));
	char* character = arena_alloc(&assets_arena, sizeof(char));
	character[0] = 'A';

	int* numbers = arena_alloc(&assets_arena, sizeof(int) * 2);
	numbers[0] = 1024;
	numbers[1] = 2048;

	printf("%c\n", character[0]);
	printf("%d\n", numbers[0]);
	printf("%d\n", numbers[1]);
	printf("size: %lli, capacity: %lli\n", assets_arena.size, assets_arena.capacity);

	arena_reset(&assets_arena);

	printf("size: %lli, capacity: %lli\n", assets_arena.size, assets_arena.capacity);

	arena_free(&assets_arena);

	return 0;
}