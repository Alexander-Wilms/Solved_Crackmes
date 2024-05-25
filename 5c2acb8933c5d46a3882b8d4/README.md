```
file SimpleKeyGen 
SimpleKeyGen: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=4b657ffd4f43a704861b200c9f2235f8fe395e27, not stripped
```

* Analyzed with all options enabled
* Functions > checkSerial contains algorithm
* Algorithm:
    * serial must be 16 characters
    * check every pair of characters:
        * Indices 0 & 1, 2 & 3, 4 & 5...
    * the ASCII code of the second char in each pair must be 1 higher than the one of the first char
    * checkSerial() returns 0x0 if the serial is valid and 0xffffffff if it is invalid
