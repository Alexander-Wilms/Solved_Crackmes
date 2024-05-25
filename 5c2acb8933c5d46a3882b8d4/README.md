* Analyzed with all options enabled
* Functions > checkSerial contains algorithm
* Algorithm:
    * serial must be 16 characters
    * check every pair of characters:
        * Indices 0 & 1, 2 & 3, 4 & 5...
    * the ASCII code of the second char in each pair must be 1 higher than the one of the first char
    * checkSerial() returns 0x0 if the serial is valid and 0xffffffff if it is invalid
