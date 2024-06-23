```
file crackme0x00
crackme0x00: Mach-O 64-bit x86_64 executable, flags:<NOUNDEFS|DYLDLINK|TWOLEVEL|PIE>
```

Flag: `NoxIsTheBest`

```c
  strcpy(correct_password,"NoxIsTheBest",0xd);
  printf("Crackme Level 0x00 (created by Nox)\n");
  printf("\nEnter the passphrase: ");
  scanf("%99s",user_input);
  password_incorrect = _strcmp(user_input,correct_password);
  if (password_incorrect == 0) {
    puts("\nCongrats on cracking the program!!");
```