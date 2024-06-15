```
file level1
level1: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=89f40555f67806b4082e5785d91836bb6baaaa9d, for GNU/Linux 3.2.0, not stripped
```

Flag: `sudo0x18`

```c
char checkPass(char *input)

{
  char c;
  
  if (*input == 's') {
    c = input[1];
    if ((((c == 'u') && (c = input[2], c == 'd')) && (c = input[3], c == 'o')) &&
       (((c = input[4], c == '0' && (c = input[5], c == 'x')) &&
        ((c = input[6], c == '1' && (c = input[7], c == '8')))))) {
      c = '\x01';
    }
  }
  else {
    c = '\0';
  }
  return c;
}
```