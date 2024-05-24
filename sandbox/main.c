#include <stdio.h>
#include <stdlib.h>
#include <cz_string.h>

int main(void) {
	HeapString message = heap_string_make("Hello");
	HeapString message2 = heap_string_make(", world!");
	HeapString text = heap_string_concat(&message, &message2);
	printf("%s, %lli\n", text.chars, text.length);
	heap_string_free(&message);
	heap_string_free(&message2);
	heap_string_free(&text);

	return 0;
}