```
file CrackMe.exe 
CrackMe.exe: PE32 executable (console) Intel 80386, for MS Windows
```

* Static analysis:
    * Open CrackMe.exe in Ghidra
    * Defined Strings > "Congrats, You cracked it!" > Listing > XREF
    * The function referencing the string:
    ```c
        _generate_license();
        [...]
        _GetWindowTextA@12(_gLicenseEdit,aCStack_90,100);
        iVar2 = _strcmp(aCStack_90,_valid_license);
    ```
    * It compares the entered string withe the `_valid_string` variable
    * The global variable `_valid_license` is assigned in the `_generate_license()` function
    ```c
    void _generate_license(void)
    {
        uint random_value;
        time_t timestamp;
        undefined4 local_35;
        undefined4 local_31;
        undefined4 local_2d;
        undefined4 local_29;
        undefined4 local_25;
        undefined4 local_21;
        undefined4 local_1d;
        undefined4 local_19;
        undefined4 local_15;
        undefined local_11;
        int i;
        
        local_35 = 0x33323130;
        local_31 = 0x37363534;
        local_2d = 0x42413938;
        local_29 = 0x46454443;
        local_25 = 0x4a494847;
        local_21 = 0x4e4d4c4b;
        local_1d = 0x5251504f;
        local_19 = 0x56555453;
        local_15 = 0x5a595857;
        local_11 = 0;
        timestamp = _time(NULL);
        _srand(timestamp);
        for (i = 0; i < 10; i = i + 1) {
            random_value = _rand();
            (&_license.31810)[i] = *(&local_35 + random_value % 36);
        }
        DAT_0040802a = 0;
        _valid_license = &_license.31810;
        return;
    }
    ```
    * Ghidra showed several 4 bit local variables in `_generate_license()`, which C does not support
    * `_valid_license` depends on `time()`
    * The assumption that the code would select local_35 or one of the following variables turned out to be wrong
    * Copying the code to create a keygen only resulted in the key `0`
* Dynamic analysis:
    * Since the static analysis and the keygen didn't result in a valid key, the next approach was dynamic analysis in order to determine the valid key at runtime
    * Open CrackMe.exe using [x32dbg](https://x64dbg.com/)
    * Find address of assignment of `_valid_license`:
    ![alt text](<ghidra_assignment_valid_license.png>)
    * Find address in x32dbg (`0x00401508`), run program
        * When the program is started, the addresses change. Afterwards, they match the ones shown in Ghidra:
    * Click run a few times until the input window appears
    * Check the address `0x00401508` for the valid license key
    * Enter the key and click submit
    ![alt text](<x32dbg_valid_license.png>)
