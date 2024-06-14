```
$ file keygenme
keygenme: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=ece89e12348534ad785ad04de9a5f88b5295bb0b, for GNU/Linux 3.2.0, not stripped
```

```
$ ./keygenme
Enter name: deckard
Enter key: fZQJD?;85
Good job!
Now write keygen)
```

* Straightforward. `encr()` takes the name and creates a key, which is at most 10 chars.
* The decompiled code can just be copy-pasted to create a keygen