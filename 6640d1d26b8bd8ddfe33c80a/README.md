```
file ./guess_the_password
./guess_the_password: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=4b5316bbef627d72efaa8d38723b2e9725065ec2, for GNU/Linux 3.2.0, not stripped
```

Flag: `1000900000`

* Check with `strings`:
```
strings ./guess_the_password | grep -v \\. | grep -v
mgUa
fgets
strcspn
puts
strlen
stdin
printf
PTE1
u+UH
What is the password:
Correct
Incorrect
9*3$"
main
check
```
* Decompile with Ghidra
* Password check:
```c
if ((((int)user_input_len == 10) && (*user_input == '1')) && (user_input[4] == '9')) {
password_valid = 1;
}
```