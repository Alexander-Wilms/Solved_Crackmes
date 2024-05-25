```
file Yxupy\ Crackme/Crack\ Me.exe
Yxupy Crackme/Crack Me.exe: PE32 executable (GUI) Intel 80386, Mono/.Net assembly, for MS Windows, 3 sections
```

flag: 8103535

Found using Ghidra's "Window > Defined Strings" feature

```
[...]
0040590e	8103535					unicode
0040591e	Lel..					unicode
0040592a	316234					unicode
00405938	Hmm Not Quite Right..	unicode
00405964	426246					unicode
00405972	Sheesh.. No...			unicode
00405990	34624762				unicode
004059a2	Kinda Close Doe..		unicode
004059c6	47235423				unicode
004059d8	Bro..					unicode
004059e4	757457					unicode
004059f2	Ben?..					unicode
00405a00	135315					unicode
00405a0e	Hooogriiiderr....		unicode
[...]
```