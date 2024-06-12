```
$ file rev03 
rev03: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=9d23fcc7b9cf9c42f809d46f50ccc249de567cc6, not stripped
```

```
$ ./rev03 
enter the magic string
ddddddcaaa
flag is flag{!#&*/5<DMW}
```

* Correct input discovered by decompiling with Ghidra, fixing code to be compilable and printing the sum of ASCII codes, which should be 1000
* A valid code can then be found using trial and error
* It was expected that 10x `d` (decimal ASCII code: 100) would be a valid code, but it resulted in the sum 1010
* Substituting chars led to the input `ddddddcaaa`