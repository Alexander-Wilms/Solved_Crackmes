```
file mid 
mid: ELF 64-bit LSB executable, x86-64, version 1 (GNU/Linux), statically linked, BuildID[sha1]=ea27d51c361017ab0a725877aaede38257a9c786, for GNU/Linux 3.2.0, with debug_info, not stripped
```

Flag: `secretPassword123`

```c

void encryptInput(char *entered_password)
{
  size_t pw_length;
  int i;
  
  pw_length = strlen(entered_password);
  for (i = 0; i < (int)pw_length; i += 1) {
    entered_password[i] = entered_password[i] ^ 5;
  }
  return;
}

int main(void)
{
  int input_invalid;
  undefined8 expected_encrypted_password;
  undefined8 local_120;
  undefined2 local_118;
  char entered_password [256];
  
  printf("Enter password: ");
  __isoc99_scanf("%255s",entered_password);
  encryptInput(entered_password);
  expected_encrypted_password = L'\x77666076';
  local_120 = L'\x6a727676';
  local_118 = L'6';
  input_invalid = strcmp(entered_password,(char *)&expected_encrypted_password);
  if (input_invalid == 0) {
    puts("Access Granted!");
  }
  else {
    puts("Access Denied!");
  }
  return 0;
}
```

Three sequences of chars are stored in three variables:

```
        00401877 48 b8 76        MOV        RAX,"dUq`wf`v"
                 60 66 77 
                 60 71 55 64
        00401881 48 ba 76        MOV        RDX,"74awjrvv"
                 76 72 6a 
                 77 61 34 37
        0040188b 48 89 85        MOV        qword ptr [RBP + expected_encrypted_password],RAX
                 e0 fe ff ff
        00401892 48 89 95        MOV        qword ptr [RBP + local_120],RDX
                 e8 fe ff ff
        00401899 66 c7 85        MOV        word ptr [RBP + local_118],'6'
                 f0 fe ff 
                 ff 36 00
```

|Step|Result|
|-|-|
| Concatenate |674awjrvvdUq\`wf\`v|
| Bytewise XOR with 5 | 321drowssaPterces |
| Reversed | secretPassword123|

* XOR encryption
    * To perform the bytewise XOR with 5, keygen.c can be used, which is derived from the decompilation.
    * This initially lead to the decrypted password `aPterces`

* Concatenation

    * `int strcmp ( const char * str1, const char * str2 );`

    * This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ or __until a terminating null-character is reached__.

    * `strcmp()` is called with the address of the first char array, "dUq`wf`v", but continues to iterate over the bytes in memory until the first string is terminated with `0x00`

    * This was discovered by copying a larger sequence of bytes near the address of "dUq`wf`v" using Okteta and performing the bytewise XOR on it, which lead to the discovery of the string `ƻƥ++M21drowssǿMaPtercesǽMƺƺƺ[ƭƂ`
        * The spurious characters are the MOV instructions etc.
        * Just concatenating the char arrays and XOR'ing them resulted in the flag

```
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: v`fw`qUd
Encrypted password: secretPa
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: þà..H74awjrvvºHdUq`wf`v¸Hÿÿÿ^èÇ
Encrypted password: ƻƥ++M21drowssǿMaPtercesǽMƺƺƺ[ƭƂ
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: Çè^ÿÿÿH¸v`fw`qUdHºvvrjwa47H..àþ
Encrypted password: Ƃƭ[ƺƺƺMǽsecretPaMǿssword12M++ƥƻ
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password:...èH/..H...ÿÿÿH.Çè^ÿÿÿH¸v`fw`qUdHºvvrjwa47H..àþÿÿH..èþÿÿfÇ.ðþÿÿ6.H..àþÿÿH...ÿÿÿH.ÖH.Çèå÷ÿÿ.Àu.H..}Ç..H.Çè....ë.H..|Ç..H.Çè
Encrypted password: +++ƭM*++M+++ƺƺƺM+Ƃƭ[ƺƺƺMǽsecretPaMǿssword12M++ƥƻƺƺM++ƭƻƺƺcƂ+Ƶƻƺƺ3+M++ƥƻƺƺM+++ƺƺƺM+ƓM+ƂƭƠƲƺƺ+ƅp+M++xƂ++M+Ƃƭ++++Ʈ+M++yƂ++M+Ƃƭ
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: secretPassword
Encrypted password: v`fw`qUdvvrjwa
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: dUq`wf`v74awjrvv6
Encrypted password: aPterces21drowss3
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: 6vvrjwa47v`fw`qUd
Encrypted password: 3ssword12secretPa
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: dUq`wf`v
Encrypted password: aPterces
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: 74awjrvvdUq`wf`v
Encrypted password: 21drowssaPterces
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: 674awjrvvdUq`wf`v
Encrypted password: 321drowssaPterces
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> file 6603c10ccddae72ae250bcd6/mid 
6603c10ccddae72ae250bcd6/mid: ELF 64-bit LSB executable, x86-64, version 1 (GNU/Linux), statically linked, BuildID[sha1]=ea27d51c361017ab0a725877aaede38257a9c786, for GNU/Linux 3.2.0, with debug_info, not stripped
alexander@PC:~/Technik/Development/Crackmes> gcc -std=c99 6603c10ccddae72ae250bcd6/keygen2.c 
cc1: fatal error: 6603c10ccddae72ae250bcd6/keygen2.c: No such file or directory
compilation terminated.
alexander@PC:~/Technik/Development/Crackmes> gcc -std=c99 6603c10ccddae72ae250bcd6/keygen.c 
6603c10ccddae72ae250bcd6/keygen.c: In function ‘main’:
6603c10ccddae72ae250bcd6/keygen.c:25:3: warning: implicit declaration of function ‘__isoc99_scanf’ [-Wimplicit-function-declaration]
   25 |   __isoc99_scanf("%255s",entered_password);
      |   ^~~~~~~~~~~~~~
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: 0
Encrypted password: 5
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
alexander@PC:~/Technik/Development/Crackmes> ./a.out
Enter password: 674awjrvvdUq`wf`v
Encrypted password: 321drowssaPterces
Expected encrypted password: dUq`wf`v
Expected decrypted password: aPterces
Access Denied!
```

Before discovering that strcmp also reads the values of the variables following the one given as the second argument, I attempted to extract the value `expected_encrypted_password` using gdb, since `aPterces` did not grant access:

References:

Printing registers with `info regs`: https://stackoverflow.com/a/62861534/2278742

Setting a register value with `set $rdi = 0x8201010`: https://stackoverflow.com/a/70079455/2278742

Printing string in register with `print *(char**)$esp
`: https://stackoverflow.com/a/12760505/2278742
```
gdb ./mid                                                                                                                                                                                                                                                                             ✔  3m 4s   
GNU gdb (GDB; openSUSE Tumbleweed) 13.2
Copyright (C) 2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-suse-linux".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://bugs.opensuse.org/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./mid...
(gdb) b main
Downloading source file /home/zulfiqar/Desktop/RE/Mid-Term/mid.c
Download failed: Connection reset by peer.  Continuing without source file /home/zulfiqar/Desktop/RE/Mid-Term/mid.c.                                                                                                                                                                                                        
Breakpoint 1 at 0x401836: file mid.c, line 14.
(gdb) n
The program is not being run.
(gdb) run
Starting program: /home/alexander/Downloads/mid 
Downloading separate debug info for system-supplied DSO at 0x7ffff7ffd000
Download failed: Connection reset by peer.  Continuing without separate debug info for system-supplied DSO at 0x7ffff7ffd000.                                                                                                                                                                                               


Breakpoint 1, main () at mid.c:14
14      in mid.c
(gdb) n
15      in mid.c
(gdb) n
Enter password: 0
18      in mid.c
(gdb) i r
rax            0x1                 1
rbx            0x7fffffffd958      140737488345432
rcx            0x0                 0
rdx            0x0                 0
rsi            0xa                 10
rdi            0x7fffffffd120      140737488343328
rbp            0x7fffffffd780      0x7fffffffd780
rsp            0x7fffffffd660      0x7fffffffd660
r8             0x1                 1
r9             0x4bb500            4961536
r10            0x0                 0
r11            0x4bc980            4966784
r12            0x7fffffffd948      140737488345416
r13            0x4b7de8            4947432
r14            0x1                 1
r15            0x1                 1
rip            0x401868            0x401868 <main+61>
eflags         0x202               [ IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb) n
21      in mid.c
(gdb) set $rdi = 0
(gdb) set $rsi = 0
(gdb) n
25      in mid.c
(gdb) i r
rax            0x6455716077666076  7229809435947196534
rbx            0x7fffffffd958      140737488345432
rcx            0x0                 0
rdx            0x373461776a727676  3977911536389879414
rsi            0x0                 0
rdi            0x0                 0
rbp            0x7fffffffd780      0x7fffffffd780
rsp            0x7fffffffd660      0x7fffffffd660
r8             0x1                 1
r9             0x4bb500            4961536
r10            0x0                 0
r11            0x4bc980            4966784
r12            0x7fffffffd948      140737488345416
r13            0x4b7de8            4947432
r14            0x1                 1
r15            0x1                 1
rip            0x4018a2            0x4018a2 <main+119>
eflags         0x246               [ PF ZF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb) n
28      in mid.c
(gdb) i r
rax            0xffffffbf          4294967231
rbx            0x7fffffffd958      140737488345432
rcx            0x76                118
rdx            0x7fffffffd660      140737488344672
rsi            0x7fffffffd660      140737488344672
rdi            0x7fffffffd680      140737488344704
rbp            0x7fffffffd780      0x7fffffffd780
rsp            0x7fffffffd660      0x7fffffffd660
r8             0x1                 1
r9             0x4bb500            4961536
r10            0x0                 0
r11            0x4bc980            4966784
r12            0x7fffffffd948      140737488345416
r13            0x4b7de8            4947432
r14            0x1                 1
r15            0x1                 1
rip            0x4018d0            0x4018d0 <main+165>
eflags         0x282               [ SF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb) set $rdi = 0
(gdb) set $rsi = 0
(gdb) i r
rax            0xffffffbf          4294967231
rbx            0x7fffffffd958      140737488345432
rcx            0x76                118
rdx            0x7fffffffd660      140737488344672
rsi            0x0                 0
rdi            0x0                 0
rbp            0x7fffffffd780      0x7fffffffd780
rsp            0x7fffffffd660      0x7fffffffd660
r8             0x1                 1
r9             0x4bb500            4961536
r10            0x0                 0
r11            0x4bc980            4966784
r12            0x7fffffffd948      140737488345416
r13            0x4b7de8            4947432
r14            0x1                 1
r15            0x1                 1
rip            0x4018d0            0x4018d0 <main+165>
eflags         0x282               [ SF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb) n
Access Denied!
31      in mid.c
(gdb) i r
rax            0xf                 15
rbx            0x7fffffffd958      140737488345432
rcx            0x46da80            4643456
rdx            0x0                 0
rsi            0x4c4870            4999280
rdi            0x4bddc0            4971968
rbp            0x7fffffffd780      0x7fffffffd780
rsp            0x7fffffffd660      0x7fffffffd660
r8             0x1                 1
r9             0x4bb500            4961536
r10            0x0                 0
r11            0x202               514
r12            0x7fffffffd948      140737488345416
r13            0x4b7de8            4947432
r14            0x1                 1
r15            0x1                 1
rip            0x4018df            0x4018df <main+180>
eflags         0x202               [ IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
```