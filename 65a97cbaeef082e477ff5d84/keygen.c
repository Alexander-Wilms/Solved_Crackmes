#include <stdio.h>

int main(void) {
	char key[21];
	char key_2[21];
	char password[21];

	for (int i = 0; i < 21; i = i + 1) {
		key[i] = "sup3r_s3cr3t_k3y_1337"[i] - 34;
	}
	key_2[0] = 0x37;
	key_2[1] = 0x3f;
	key_2[2] = 0x2f;
	key_2[3] = 0x76;
	key_2[4] = 0x2b;
	key_2[5] = 0x62;
	key_2[6] = 0x28;
	key_2[7] = 0x21;
	key_2[8] = 0x34;
	key_2[9] = 0xf;
	key_2[10] = 0x77;
	key_2[11] = 0x62;
	key_2[12] = 0x48;
	key_2[13] = 0x27;
	key_2[14] = 0x75;
	key_2[15] = 8;
	key_2[16] = 0x56;
	key_2[17] = 0x6a;
	key_2[18] = 0x68;
	key_2[19] = 0x4e;
	key_2[20] = 0x68;

	printf("%s\n", key_2);

	for (int j = 0; j < 21; j = j + 1) {
		password[j] = key[j] ^ key_2[j];
	}

	printf("You found a flag! %s\n", password);
	return 0;
}