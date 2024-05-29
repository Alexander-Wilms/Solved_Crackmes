#include <stdio.h>
#include <string.h>

int main(void) {
	int strings_differ;
	size_t valid_passwod_length;
	int i;
	char valid_password[32];
	char BYTE_encrypted_password[] = {
		0x2c, 0x3c, 0x23, 0x3b, 0x2c, 0x0b, 0x21, 0x3a, 0x2f, 0x3f, 0x65, 0x86,
		0xab, 0x79, 0x35, 0x24, 0x0b, 0xf9, 0x86, 0xf1, 0x06, 0x41, 0x00};

	strcpy(valid_password, BYTE_encrypted_password);

	printf("encrypted password: %s\n\n", BYTE_encrypted_password);

	i = 0;
	while (1) {
		valid_passwod_length = strlen(valid_password);
		if (valid_passwod_length <= i)
			break;
		valid_passwod_length = strlen("SCTL");
		valid_password[i] =
			valid_password[i] ^ "SCTL"[i % valid_passwod_length];
		i += 1;
	}

	printf("valid password: %s\n\n", valid_password);
}