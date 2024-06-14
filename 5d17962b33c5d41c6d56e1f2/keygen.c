#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void encr(char *name, char *key_for_given_name) {
	char key_char;
	size_t name_len;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (true) {
		name_len = strlen(name);
		if (name_len <= j)
			break;
		i += name[j];
		j += 1;
	}
	for (k = 0; k < 9; k += 1) {
		name_len = strlen(name);
		key_char = i / (name_len + k);
		i += i / key_char;
		*(k + key_for_given_name) = key_char;
	}
	return;
}

void main(void) {
	char name[] = "deckard";
	char key[10];

	encr(name, key);

	printf("name: %s\n", name);
	printf("key: %s\n", key);
}