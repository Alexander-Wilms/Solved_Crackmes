#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_rot(char *string, int rotation) {
	printf("_rot(\"%s\", %d)\n", string, rotation);
	size_t string_length;
	char *rotated_string;
	int i;
	int rotated_char;

	string_length = strlen(string);
	rotated_string = malloc(string_length + 1);
	for (i = 0; i < string_length; i = i + 1) {
		printf("char %d/%d: %c -> ", i, (int)string_length, string[i]);
		if ((string[i] < 'a') || ('z' < string[i])) {
			if ((string[i] < 'A') || ('Z' < string[i])) {
				printf("other -> no change\n");
				rotated_string[i] = string[i];
			} else {

				rotated_char = string[i] - 'A' + rotation;
				rotated_string[i] = rotated_char + (rotated_char / 26) * -26 + 'A';
				printf("upper case -> %c\n", rotated_string[i]);
			}
		} else {
			rotated_char = string[i] - 'a' + rotation;
			rotated_string[i] = rotated_char + (rotated_char / 26) * -26 + 'a';
			printf("lower case -> %c\n", rotated_string[i]);
		}
	}
	rotated_string[string_length] = 0;
	return rotated_string;
}

int main(void) {
	char *encrypted_key = "_Q3eM3tT1t6}";
	printf("%s\n", encrypted_key);

	char decrypted_key[strlen(encrypted_key)];
	strcpy(decrypted_key, _rot(encrypted_key, -6));
	printf("%s\n", decrypted_key);

	char re_encrypted_key[strlen(encrypted_key)];
	strcpy(re_encrypted_key, _rot("_K3yG3nN1n6", 6));
	printf("%s\n", re_encrypted_key);
}