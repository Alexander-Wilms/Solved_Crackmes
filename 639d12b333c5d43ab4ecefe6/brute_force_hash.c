#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint fnv_1a_32(char *param_1) {
	// https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
	char *pBuffer;
	uint hash;

	hash = 0x811c9dc5;
	for (pBuffer = param_1; *pBuffer != '\0'; pBuffer = pBuffer + 1) {
		hash = (hash ^ *pBuffer) * 0x1000193;
	}
	return hash;
}

int main(void) {
	char input[10];
	char copy[10];
	uint hash;

	input[9] = 0;

	for (int i_0 = '0'; i_0 <= '9'; i_0++) {
		printf(".\n");
		for (int i_1 = '0'; i_1 <= '9'; i_1++) {
			for (int i_2 = '0'; i_2 <= '9'; i_2++) {
				for (int i_3 = '0'; i_3 <= '9'; i_3++) {
					for (int i_4 = '0'; i_4 <= '9'; i_4++) {
						for (int i_5 = '0'; i_5 <= '9'; i_5++) {
							for (int i_6 = '0'; i_6 <= '9'; i_6++) {
								for (int i_7 = '0'; i_7 <= '9'; i_7++) {
									for (int i_8 = '0'; i_8 <= '9'; i_8++) {
										input[0] = (char)i_0;
										input[1] = (char)i_1;
										input[2] = (char)i_2;
										input[3] = (char)i_3;
										input[4] = (char)i_4;
										input[5] = (char)i_5;
										input[6] = (char)i_6;
										input[7] = (char)i_7;
										input[8] = (char)i_8;

										strncpy(copy, input, 9);
										//printf("%s\n", copy);
										hash = fnv_1a_32(copy);

										if (hash == 4189697893) {
											printf("cracked!\n");
											printf("The string '%s' results in the Fowler-Noll-Vo hash '%d'", input, hash);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}