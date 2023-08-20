OK:
```
./push_swap -7 89 9 -2356 5 90 72 31   | valgrind ./checker -7 89 9 -2356 5 90 72 31 
./push_swap "-7 89 9 -2356 5 90 72 31" | valgrind ./checker "-7 89 9 -2356 5 90 72 31"
./push_swap -7 89 9 -2356 5 90 "72 31" | valgrind ./checker -7 89 9 -2356 5 90 "72 31"
```

KO:
```
./push_swap -7 89 9 -2356 5 90 72 31   | valgrind ./checker -7 89 9 -2356 5 90 72
./push_swap "-7 89 9 -2356 5 90 72 31" | valgrind ./checker "-7 89 9 -2356 5 90 72 31"
./push_swap -7 89 9 -2356 5 90 "72 31" | valgrind ./checker -7 89 9 -2356 5 90 "72 31"
```
