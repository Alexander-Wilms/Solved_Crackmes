Flag: 0000000000000000000000000000000

The entered password and the admin login (user id with uid 0 == admin) are stored in memory manually allocated using malloc().

For the password, only 16 bytes are allocated, but fgets() reads up to 160 input chars. The admin login var is apparently stored immediately afterwards in memory and thus overwritten if we enter more than 16 chars.

With a bit of trial & error, the necessary input to set `admin_login_failed` to 0 can be found.

```
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 0
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 7574
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 111111111
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                        ✔  17s   
enter password: 11111111111111111111111111111111111111111
uid: 825307441
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  3s   
enter password: 9999999999999999999999999999999999999999
uid: 960051513
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  5s   
enter password: 99999999999999999999999999999999999999999
uid: 960051513
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  7s   
enter password: 99999999999
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 9999999999999999999999
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
uid: 960051513
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  9s   
enter password: 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
uid: 960051513
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  9s   
enter password: 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
uid: 808464432
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
uid: 808464432
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  4s   
enter password: 1
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 12314134
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 1111111111
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 11111111111111111111
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 11111111111111111111111111111111111
uid: 170996017
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 111111111111111111111111111111111111
uid: 825307441
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  4s   
enter password: 111111111111111111111111111111111112
uid: 842084657
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  7s   
enter password: 1111111111111111111
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 1111111111111111111111111111
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 11111111111111111111111111111
uid: 1
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 11111111111111111111111111111111
uid: 10
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 11111111111111111111111111111111
uid: 10
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  4s   
enter password: 11111111111111111111111111111112
uid: 10
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  5s   
enter password: 21111111111111111111111111111111  
uid: 10
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  5s   
enter password: 111111111111111111111111111111111
uid: 2609
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  4s   
enter password: 222222222222222222222222222222222 
uid: 2610
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  4s   
enter password: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
uid: 2657
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  5s   
enter password: 111111111111111111111111111111111
uid: 2609
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  5s   
enter password: 000000000000000000000000000000000
uid: 2608
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                         ✔  5s   
enter password: 1111111111111111111111111111111111
uid: 667953
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 11111111111111111111111111111111
uid: 10
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: ^[[A^[[A^[[A^[[A^[[A^[[A^[[A^[[A^[[A^[[A^[[A^[[A^[[A^[[A^[[A
uid: 1096489793
you are logged in as user
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14  ./a.out                                 ✔ 
enter password: 0000000000000000000000000000000
uid: 0
you are logged in as admin
      ~/T/De/Crackmes/5f05ec3c33c5d42a7c66792b     master !9 ?14                                  ✔  6s   
```

```c++

void login(void)

{
  char *entered_password;
  uint *admin_login_failed;
  
  printf("enter password: ");
                    /* void *malloc( size_t size );
                         
                       Allocates size bytes of uninitialized storage. */
  entered_password = (char *)malloc(16);
  admin_login_failed = (uint *)malloc(8);
  *admin_login_failed = 1;
                    /* Reads at most count - 1 characters from the given file stream and stores them
                       in the character array pointed to by str */
  fgets(entered_password,160,stdin);
  printf("uid: %d\n",(ulong)*admin_login_failed);
  if (*admin_login_failed == 0) {
    puts("you are logged in as admin");
  }
  else {
    puts("you are logged in as user");
  }
  return;
}
```
