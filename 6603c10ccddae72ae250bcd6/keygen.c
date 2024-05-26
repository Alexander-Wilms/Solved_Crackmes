#include <stdio.h>
#include <string.h>

void encryptInput(char *entered_password)
{
  size_t pw_length;
  int i;
  
  pw_length = strlen(entered_password);
  for (i = 0; i < (int)pw_length; i += 1) {
    entered_password[i] = entered_password[i] ^ 5;
  }
  return;
}

int main(void)
{
  int input_invalid;
  char local_128 [256];
  char local_120 [256];
  char local_118 [256];
  char entered_password [256];
  
  printf("Enter password: ");
  __isoc99_scanf("%255s",entered_password);
  encryptInput(entered_password);
  strcpy(local_128,"dUq`wf`v");
  //local_120 = 0x373461776a727676;
  //local_118 = 0x36;

  printf("Encrypted password: %s\n", entered_password);
  printf("Expected encrypted password: %s\n", (char *)&local_128);
  strcpy(local_120,local_128);
  encryptInput(local_120);
  printf("Expected decrypted password: %s\n", (char *)&local_120);

  input_invalid = strcmp(entered_password,(char *)&local_128);

  if (input_invalid == 0) {
    puts("Access Granted!");
  }
  else {
    puts("Access Denied!");
  }
  return 0;
}

