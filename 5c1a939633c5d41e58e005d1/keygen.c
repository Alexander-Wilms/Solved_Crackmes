#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long strcat_str(void) {
	int i;
	long retval;

	retval = 0x21;
	for (i = 1; i < 10; i += 1) {
		(&retval)[i] = i + (&retval)[i + -1] + 1;
	}
	return retval;
}

int main(void) {
	size_t input_length;
	ulong i_copy;
	char user_input[112];
	long local_28;
	int i;
	int ascii_sum;

	ascii_sum = 0;
	puts("enter the magic string");
	fgets(user_input, 100, stdin);
	input_length = strlen(user_input);
	if (input_length < 12) {
		i = 0;
		while (true) {
			i_copy = i;
			if (input_length <= i_copy)
				break;
			ascii_sum += user_input[i];
			i += 1;
		}
		printf("ascii_sum: %d\n", ascii_sum);
		if (ascii_sum == 1000) {
			local_28 = strcat_str();
			printf("flag is flag{");
			for (i = 0; i < 10; i += 1) {
				putchar(local_28 + i);
			}
			puts("}");
		} else {
			puts("wrong string\nNo flag for you.");
		}
	} else {
		puts("too long...sorry no flag for you!!!");
	}
	return 0;
}