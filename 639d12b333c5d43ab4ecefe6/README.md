```
$ file ./keyGen.exe
./keyGen.exe: PE32 executable (console) Intel 80386, for MS Windows, 13 sections
```

Flags:

`Securinets{133745555_K3yG3nN1n6}`
or
`Securinets{806470850_K3yG3nN1n6}`

Flag consists of 3 parts:
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