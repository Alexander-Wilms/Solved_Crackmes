```
file ./tryme
./tryme: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, not stripped
```

Flag: `_y0u_f0und_key_`

* Try `strings`
```
strings tryme | grep -v \\. | grep -v _
puts
printf
strlen
u/UH
Wrong flag
You found a flag! %s
;*3$"
main
```
* Decompiled code XOR-encrypts `local_88` with `key`
    ```c
    if (password_length == 21) {
      for (i = 0; i < 21; i = i + 1) {
        key[i] = "sup3r_s3cr3t_k3y_1337"[i] - 34;
      }
      local_88[0] = 0x37;
      local_88[1] = 0x3f;
      local_88[2] = 0x2f;
      local_88[3] = 0x76;
      local_88[4] = 0x2b;
      local_88[5] = 0x62;
      local_88[6] = 0x28;
      local_88[7] = 0x21;
      local_88[8] = 0x34;
      local_88[9] = 0xf;
      local_88[10] = 0x77;
      local_88[0xb] = 0x62;
      local_88[0xc] = 0x48;
      local_88[0xd] = 0x27;
      local_88[0xe] = 0x75;
      local_88[0xf] = 8;
      local_88[0x10] = 0x56;
      local_88[0x11] = 0x6a;
      local_88[0x12] = 0x68;
      local_88[0x13] = 0x4e;
      local_88[0x14] = 0x68;
      for (j = 0; j < 21; j = j + 1) {
        if ((int)(char)(key[j] ^ *(byte *)((long)j + *(long *)(argv + 8))) != local_88[j]) {
          puts("Wrong flag");
          uVar1 = 1;
          goto wrong_password;
        }
      }
      printf("You found a flag! %s\n",*(undefined8 *)(argv + 8));
      uVar1 = 0;
    ```
* `*(byte *)((long)j + *(long *)(argv + 8))` can be simplified as `password[j]`
* `[...] != local_88` can be adapted to `password = [...]`