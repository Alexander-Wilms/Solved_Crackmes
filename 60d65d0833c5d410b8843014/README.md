```
file keygenme_1.exe 
keygenme_1.exe: PE32 executable (console) Intel 80386, for MS Windows, 6 sections
```

1) Use "Defined Strings" window

```
[...]
00466000	Check one failed.
	"Check one failed.\n"	ds
00466014	Check two failed.
	"Check two failed.\n"	ds
00466028	Check three failed.
	"Check three failed.\n"	ds
00466040	Welcome to KeygenMe 1 sir :)
Enter a key: 	"Welcome to KeygenMe 1 sir :)\nEnter a key: "	ds
0046606c	Key in correct format.
	"Key in correct format.\n"	ds
00466084	Congrats, you did it!
	"Congrats, you did it!\n"	ds
0046609c	Invalid key format, must be in the form XXXX-XXXX-XXXX.
	"Invalid key format, must be in the form XXXX-XXXX-XXXX.\n"	ds
004664da	abcdefghijklmnopqrstuvwxyz	"abcdefghijklmnopqrstuvwxyz"	ds
004664fa	ABCDEFGHIJKLMNOPQRSTUVWXYZ	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"	ds
00466789	abcdefghijklmnopqrstuvwxyz	"abcdefghijklmnopqrstuvwxyz"	ds
004667a9	ABCDEFGHIJKLMNOPQRSTUVWXYZ	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"	ds
[...]
```

2) Double-click on `00466084	Congrats, you did it!	"Congrats, you did it!\n"	ds`
3) In Listing window, double-click on function referencing the data: FUN_00406f40
4) Crackme consists of 4 parts:
    1) Check that input matches format XXXX-XXXX-XXXX
    2) Check 1: First 4 chars must be digits (i.e. ASCII code between '0' and '9' (inclusive))
    3) Check 2: Second block of chars must only consist of chars whose LSB of the ASCII code is 0. I.e. check with 4x one letter and if that doesn't work, use the next letter in the alphabet
    4) Check 3: 10th char (0-indexed) must be 'R'

Flag: 0000-XXXX-RXXXX