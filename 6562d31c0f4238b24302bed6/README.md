```
file TASK\ 7                                                                   ✔ 
TASK 7: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=4b657ffd4f43a704861b200c9f2235f8fe395e27, not stripped
```

Flags: 
* 0101010101010101
* abababababababab

Pretty easy, since it contains debug symbols.

`checkSerial()`:
```c
  if (string_length == 16) {
    for (i = 0; string_length = strlen(serial), (ulong)(long)i < string_length; i += 2) {
      if ((int)serial[i] - (int)serial[(long)i + 1] != -1) {
        return 0xffffffff;
      }
    }
    serial_invalid = 0;
  }
  else {
    serial_invalid = 0xffffffff;
  }
```

Conditions for valid serial:
* 16 chars
* for each pair of chars 0 & 1, 2 & 3, 4 & 5 etc., the ASCII code of the second char has to be 1 bigger than that of the first char