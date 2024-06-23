#include <stdio.h>

int main(void) {
	char xor_pattern[] = "P{ [>2";
	char encrypted_pw[] = {0x32, 0xa2, 0xdf, 0x2d, 0x99, 0x2b, 0x00};

	printf("%s\n", (char *)((char)encrypted_pw ^ (char)xor_pattern));
}