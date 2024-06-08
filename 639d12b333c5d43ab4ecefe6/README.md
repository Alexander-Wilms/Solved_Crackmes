```
$ file ./keyGen.exe
./keyGen.exe: PE32 executable (console) Intel 80386, for MS Windows, 13 sections
```

Flags:

`Securinets{133745555_K3yG3nN1n6}`
or
`Securinets{806470850_K3yG3nN1n6}`

The flag is 32 chars long and consists of 3 parts:
* The string `Securinets{`
* A 9-digit decimal number whose [Fowler–Noll–Vo hash](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) is `0xf9b9b765`
* A string, that when shifted by 6 characters is `_Q3eM3tT1t6}`

# Caesar cipher
Since part of the user input is passed to `_rot(substring,6)`, the expected input can be recovered using `_rot("_Q3eM3tT1t6}",-6)`.
`keygen.c` was created from the pseudocode decompiled by Ghidra and simplified in the following ways to make it more readable:
* `*(i + rotated_string)` -> `rotated_string[i]`
* `0x41` -> `'A'`
* `0x1a` -> `26`
* `0x61` -> `'a'`
* `*(rotated_string + string_length)` -> `rotated_string[string_length]`

Decrypting the string in the decompiled code via `_rot("_Q3eM3tT1t6}", -6)` results in `_K3_G3nN1n6}`. Since `_rot("_K3_G3nN1n6}", 6)` did not result in the known encrypted string, it followed that the correct solution would be `_K3yG3nN1n6}`.

# FNV hash

The function name was not stripped, so searching for `_fnv_1a_32` lead to the article [Fowler–Noll–Vo hash](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function). The FNV hash parameters given for bit length 32 are
* FNV prime: 0x01000193
* FNV offset basis: 0x811c9dc5

These match the parameters in the decompiled code.

The decompiled code is used to brute force the correct input for the given hash.

Given that the entire password must be 32 chars long, `Securinets{` is 11 chars and `_Q3eM3tT1t6}` is 12 chars, the input to the hash function must be 9 chars.

The search space can be further reduced since each char may not be bigger than the ASCII code of the char `'9'`. Assuming that the input is a number, the hash can be cracked via brute forcing by nesting 9 for loops that each iterate of the ASCII codes between `'0'` and `'9'`. In the innermost loop, the hash input is created by setting each char of the string of length 9 (10 including the string-terminating `\0`).

The computed hash is then compared to the value given in the decompiled code.

Now the hash can be cracked in a few seconds:

```
$ gcc -O3 639d12b333c5d43ab4ecefe6/brute_force_hash.c 
$ ./a.out 
.
.
cracked!
The string '133745555' results in the Fowler-Noll-Vo hash '-105269403'.
.
.
.
.
.
.
cracked!
The string '806470850' results in the Fowler-Noll-Vo hash '-105269403'.
```

Note that `printf()` shows an incorrect value for the hash, since its type is `uint` and not `int`, which `%d` expects.