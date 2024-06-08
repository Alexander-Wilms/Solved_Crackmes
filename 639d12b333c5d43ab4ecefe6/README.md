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