```
$ file license 
license: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=08b1ce949101670bed3f28545636027d81e3b636, not stripped
```

# Flags

Found with keygen.c:

`~~n000000`

`~~~k!!!!!`

In Bash, the exclamation marks have to be escaped, quoting the key is not enough:

`$ ./license ~~~k\!\!\!\!\!`

`~EAAAAAAA`

`zBBBBBBBB`

```
$ ./5c8d45c333c5d4776a837ec2/license ~~n000000
Good job!
```

# Steps

With the decompiled code, a keygen can be written to brute-force a key that satifies the condition `get_sum_of_products(key) == 52650`

To get to 50 keys, one can determine 50 distinct permutations with keygen.py. This is much faster than trying to find 50 distinct sets of characters.