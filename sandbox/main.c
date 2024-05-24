#include <stdio.h>
#include <cz_string.h>

int main(void) {
	String test1 = string_make("TEST1");
	printf("%s: %lli\n", test1.chars, test1.length);

	String test2 = string_make("TEST2");
	printf("%s: %lli\n", test2.chars, test2.length);

	String agian = string_concat(&test1, &test2);
	printf("%s: %lli\n", agian.chars, agian.length);

	String agian2 = string_concat(&test1, &agian);
	printf("%s: %lli\n", agian2.chars, agian2.length);

	return 0;
}