#include <stdio.h>

void main(void) {
	int password = 2;
	for (int i = 2; i < 20; i += 1) {
		printf("%d\n", i);
		password *= i;
	}

	printf("password: %d\n", password);
}