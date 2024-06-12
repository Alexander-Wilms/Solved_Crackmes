#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int return_32() {
	return 32;
};

int main(void) {
	char _32;
	size_t string_length;
	uint local_34;
	uint serial_4;
	char *tmp;
	uint serial_3;
	uint serial_2;
	uint serial_1;
	size_t i;
	char *user_name;
	char two;
	char one;
	size_t zero;

	zero = 0;
	one = 1;
	two = 2;
	printf("USERNAME  >>> ");
	string_length = return_32();
	user_name = malloc(string_length);
	_32 = return_32();
	fgets(user_name, _32, stdin);
	string_length = strlen(user_name);
	user_name[string_length - one] = '\0';
	string_length = strlen(user_name);
	if (string_length == zero) {
		printf(" Username required!\n");
	} else {
		serial_1 = 0;
		serial_2 = 0;
		serial_3 = 0;
		for (i = zero; user_name[i] != '\0'; i += 1) {
			serial_1 += user_name[i] * (i + one);
			serial_2 += user_name[i] * (i + two);

			tmp = user_name + i;
			serial_3 += *tmp / (i + two) + serial_2;
		}
		local_34 = serial_1 ^ serial_2 ^ serial_3;
		string_length = strlen(user_name);
		serial_4 = local_34 * string_length;

		printf("SERIAL-%05X-%05X-%05X-%05X\n", serial_1, serial_2, serial_3, serial_4);
	}
}