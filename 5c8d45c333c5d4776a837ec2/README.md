```
$ file license 
license: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=08b1ce949101670bed3f28545636027d81e3b636, not stripped
```

# Flags

Found with keygen.c:

```
 0: ~~~k!!!!!
 1: ~~~f"""""
 2: ~~~a#####
 3: ~~~\$$$$$
 4: ~~~W%%%%%
 5: ~~~R&&&&&
 6: ~~~M'''''
 7: ~~~H(((((
 8: ~~~C)))))
 9: ~~~>*****
10: ~~~9+++++
11: ~~~4,,,,,
12: ~~~/-----
13: ~~z......
14: ~~t//////
15: ~~n000000
16: ~~h111111
17: ~~b222222
18: ~~\333333
19: ~~V444444
20: ~~P555555
21: ~~J666666
22: ~~D777777
23: ~~>888888
24: ~}9999999
25: ~v:::::::
26: ~o;;;;;;;
27: ~h<<<<<<<
28: ~a=======
29: ~Z>>>>>>>
30: ~S???????
31: ~L@@@@@@@
32: ~EAAAAAAA
33: zBBBBBBBB
34: rCCCCCCCC
35: jDDDDDDDD
36: bEEEEEEEE
37: ZFFFFFFFF
38: RGGGGGGGG
39: JHHHHHHHH
```

In Bash, the exclamation marks have to be escaped, quoting the key is not enough:

`$ ./license ~~~k\!\!\!\!\!`


```
$ ./5c8d45c333c5d4776a837ec2/license ~~n000000
Good job!
```

# Steps

With the decompiled code, a keygen can be written to brute-force a key that satifies the condition `get_sum_of_products(key) == 52650`

To get to 50 keys, one can determine 50 distinct permutations of one found key with keygen.py.