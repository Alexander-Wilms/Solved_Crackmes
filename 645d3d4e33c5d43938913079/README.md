```
file a.out 
a.out: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=07adab7654c353add9669995f1587e01439c24db, for GNU/Linux 3.2.0, not stripped
```

Flag: `I_LOVE_YOU`, protected by the password `219283456`

The password is created with the product 2\*3\*4\*...\*19.

However, due to the integer overflow, the password is not equivalent to 19! (factorial).

Instead of of just copy-pasting the code to create the keygen, I first tried to determine the value of the password with a debugger.
But apparently, there's no equivalent to OllyDbg or x64dbg.
The closest alternatives are

* [PINCE](https://github.com/korcankaraokcu/PINCE) (Cheat Engine clone)
* [iaito](https://github.com/radareorg/iaito)
* [Ghidra](https://github.com/NationalSecurityAgency/ghidra)
* [gdbgui](https://github.com/cs01/gdbgui)
* [gdb-frontend](https://github.com/rohanrhu/gdb-frontend)

But none of them seemed to allow setting a breakpoint at a particular address and then just runnung the executable.