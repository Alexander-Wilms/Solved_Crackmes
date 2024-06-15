#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

long get_sum_of_products(char *key) {
	long sum_of_products = 0;
	int i = 0;
	int pw_len;
	char current_char;
	pw_len = strlen(key);

	// printf("strlen(key) == %d\n", pw_len);

	for (int i = 0; i <= pw_len; i++) {
		current_char = key[i];

		sum_of_products += current_char * pw_len * pw_len;

#if 0
        printf("current_char == %c\n", current_char);
        printf("(int) current_char == %d\n", current_char);
        printf("\n");
#endif
	}

	// printf("sum_of_products == %ld\n", sum_of_products);
	return sum_of_products;
}

bool is_valid_key(char *key) {
	return get_sum_of_products(key) == 52650;
}

bool is_only_tildes(char *password) {

	for (int i = 0; i < strlen(password); i++) {
		if (password[i] != '~') {
			return false;
		}
	}

	return true;
}

void get_next_possible_password(char *password, char init_char) {
	// printf("get_next_possible_password()\n");
	char current_char;

	bool only_tildes = is_only_tildes(password);
	int i;
	// printf("only_tildes: %d\n", (int)only_tildes);
	if (only_tildes) {
		// printf("is only tildes\n");
		// printf("strlen(password) == %d", strlen(password));
		password[strlen(password)] = '!';
		password[strlen(password) + 1] = 0;

		for (i = 0; i < strlen(password); i++) {
			// so far, the first (and only) key found during each run depended on this initialization char
			password[i] = init_char;
		}
	}

	for (i = 0; i < strlen(password); i++) {
		current_char = password[i];
		if (current_char == '~') {
			continue;
		} else {
			password[i] += 1;
			break;
		}
	}
	// printf("%s\n", password);
}

int main(void) {
	// specify array size when you declare an array without initializer
	// https://stackoverflow.com/a/23000387/2278742
	char possible_password[100];
	int password_length = 1;
	bool key_found = false;

	assert(get_sum_of_products("0") == 48);
	printf("get_sum_of_products(\"0\") == %ld\n", get_sum_of_products("0"));

	strcpy(possible_password, "!");
	int number_of_found_keys = 0;
	char init_char = '!';
	while (number_of_found_keys < 50) {
		get_next_possible_password(possible_password, init_char);

		key_found = is_valid_key(possible_password);
		if (key_found) {
			printf("%2d: %s\n", number_of_found_keys, possible_password);
			number_of_found_keys++;
			strcpy(possible_password, "!");
			init_char++;
		}
	}
}
