#include <stdio.h>
#include <string.h>

int main(void) {
  // encrypted_key XOR password = solution

  // e_key | pw | sol
  // 0     | 0  | 0
  // 0     | 1  | 1
  // 1     | 0  | 1
  // 1     | 1  | 0

  // pw = e_key XOR sol

  char *key = "sup3r_s3cr3t_k3y_1337";
  int solution[21];
  solution[0] = 0b00110111;
  solution[1] = 0b00111111;
  solution[2] = 0b00101111;
  solution[3] = 0b01110110;
  solution[4] = 0b00101011;
  solution[5] = 0b01100010;
  solution[6] = 0b00101000;
  solution[7] = 0b00100001;
  solution[8] = 0b00110100;
  solution[9] = 0b00001111;
  solution[10] = 0b01110111;
  solution[11] = 0b01100010;
  solution[12] = 0b01001000;
  solution[13] = 0b00100111;
  solution[14] = 0b01110101;
  solution[15] = 0b00001000;
  solution[16] = 0b01010110;
  solution[17] = 0b01101010;
  solution[18] = 0b01101000;
  solution[19] = 0b01001110;
  solution[20] = 0b01101000;

  char encrypted_key[21];
  char password[21];
  for (int i = 0; i < strlen(key); i++) {
    encrypted_key[i] = key[i] - 34;
    password[i] = encrypted_key[i] ^ solution[i];
  }
  printf("%s\n", password);
}
