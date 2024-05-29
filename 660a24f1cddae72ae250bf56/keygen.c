#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *string_1;
	char *string_2;
	*string_1 = L'n';
	string_1[1] = L'`';
	string_1[2] = L'^';
	string_1[3] = L'm';
	string_1[4] = L'`';
	string_1[5] = L'o';
	for (int i = 0; i < 5; i = i + 1) {
		*string_1 = *string_1 + 1;
		string_1[1] = string_1[1] + 1;
		string_1[2] = string_1[2] + 1;
		string_1[3] = string_1[3] + 1;
		string_1[4] = string_1[4] + 1;
		string_1[5] = string_1[5] + 1;
	}
	string_2 = malloc(7);
	for (int j = 0; j < 7; j = j + 1) {
		string_2[j] = string_1[j];
	}
	string_2[6] = '\0';

	puts(string_2);
	return 0;
}