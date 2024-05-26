```
file ./sleighctl.exe                                                         1 ✘ 
./sleighctl.exe: PE32+ executable (console) x86-64 (stripped to external PDB), for MS Windows, 3 sections
```

* scanf() uses a string from the DATA segment for formatting
    * Select all chars in Listing window and right click > Data > string
* User input is compared to a string stored in the DATA segment, which is then encrypted:
```c
bool isSerialValid(char *user_input)

{
  int strings_differ;
  size_t valid_passwod_length;
  int i;
  char valid_password;
  
  strcpy(&valid_password,&BYTE_encrypted_password);
  i = 0;
  while( true ) {
    valid_passwod_length = strlen(&valid_password);
    if (valid_passwod_length <= (ulonglong)(longlong)i) break;
    valid_passwod_length = strlen(s_SCTL_0040201d);
    (&valid_password)[i] =
         (&valid_password)[i] ^ s_SCTL[(ulonglong)(longlong)i % valid_passwod_length];
    i += 1;
  }
  strings_differ = strcmp(&valid_password,user_input);
  return strings_differ == 0;
}
```
* Keygen doesn't produce a working password for some reason
* Patching with Oketa
    * change JZ to JNZ
        * `0F 84 05 00 00` -> `0F 85 05 00 00`
        * `0000:0350 | FF FF 83 F8  00 0F 84 05  00 00 00 E9  17 00 00 00 | ÿÿ.ø.......é....`
    * or change target of jump instruction:
        * `0F 84 05 00 00` -> `0F 84 1C 00 00`
        * `0000:0350 | FF FF 83 F8  00 0F 84 1C  00 00 00 E9  17 00 00 00 | ÿÿ.ø.......é....`
`
