# PUSH_SWAP

## OK without checker
```shell
./push_swap  -7 89 9 -2356 5 90 72  31
./push_swap "-7 89 9 -2356 5 90 72  31"
./push_swap  -7 89 9 "-2356" 5 90 "72 31"
./push_swap  -7 89 9 31 -2356 5 90 72 2147483647
```
## OK with checker
```shell
./push_swap  -7 89 9 -2356 5 90 72  31            |  ./checker_linux  -7 89 9 -2356 5 90 72 31 
./push_swap "-7 89 9 -2356 5 90 72  31"           |  ./checker_linux  -7 89 9 -2356 5 90 72 31
./push_swap  -7 89 9 "-2356" 5 90 "72 31"         |  ./checker_linux  -7 89 9 -2356 5 90 72 31
./push_swap  -7 89 9 31 -2356 5 90 72 2147483647  |  ./checker_linux  -7 89 9 31 -2356 5 90 72 2147483647
```
## OK with memory test
```shell
valgrind ./push_swap  -7 89 9 -2356 5 90 72  31 
valgrind ./push_swap "-7 89 9 -2356 5 90 72  31"
valgrind ./push_swap  -7 89 9 "-2356" 5 90 "72 31"
valgrind ./push_swap  -7 89 9 31 -2356 5 90 72 2147483647
```

### 100 Numbers
```shell
ARG="$(seq -888 888 | shuf -n 100)" valgrind ./push_swap $ARG
ARG="$(seq 0 500    | shuf -n 100)" valgrind ./push_swap $ARG
ARG="$(seq 0 500    | shuf -n 100)" valgrind ./push_swap $ARG
```

### 500 Numbers
```shell
ARG="$(seq -888 888 | shuf -n 100)" valgrind ./push_swap $ARG
ARG="$(seq 0 500    | shuf -n 100)" valgrind ./push_swap $ARG
ARG="$(seq 0 500    | shuf -n 100)" valgrind ./push_swap $ARG
```

## Error
repeated number:
```shell
./push_swap  -7 89 9 31 -2356 5 90 72 31
```
INT MIN -1:
```shell
./push_swap  -7 89 9 31 -2356 5 90 72 -2147483649
```
INT MAX +1:
```shell
./push_swap  -7 89 9 31 -2356 5 90 72 2147483648
```
repeated number on quotes:
```shell
./push_swap  -7 89 9 31 -2356 5 90 "72 5 2147483647"
```

### Error with memory check
repeated number:
```shell
valgrind ./push_swap  -7 89 9 31 -2356 5 90 72 31
```
INT MIN -1:
```shell
valgrind ./push_swap  -7 89 9 31 -2356 5 90 72 -2147483649
```
INT MAX +1:
```shell
valgrind ./push_swap  -7 89 9 31 -2356 5 90 72 2147483648
```
repeated number on quotes:
```shell
valgrind ./push_swap  -7 89 9 31 -2356 5 90 "72 5 2147483647"
```

## CHECKER

OK:
```shell
./push_swap -7 89 9 -2356 5 90 72 31   | valgrind ./checker -7 89 9 -2356 5 90 72 31 
./push_swap "-7 89 9 -2356 5 90 72 31" | valgrind ./checker "-7 89 9 -2356 5 90 72 31"
./push_swap -7 89 9 -2356 5 90 "72 31" | valgrind ./checker -7 89 9 -2356 5 90 "72 31"
```

KO:
```shell
./push_swap -7 89 9 -2356 5 90 72 31   | valgrind ./checker -7 89 9 -2356 5
./push_swap "-7 89 9 -2356 5 90 72 31" | valgrind ./checker "-7 89 9 -2356 5 90 72 31 78"
./push_swap -7 89 9 -2356 5 90 "72 31" | valgrind ./checker -7 89 9 -2356 5 90 "72 31 99 09"
```

TESTER:
```shell
#!/bin/bash
AMOUNT=30
SIZE=100
START=0
FINAL=500
MAX=0
ITERATIONS=0
LIMIT=700
FILE="above_limit_for_$SIZE"
SUM=0
SEQUENCE=$(seq $START $FINAL)

for i in $(seq 1 $AMOUNT)
do
        export ARG="$(echo $SEQUENCE |  tr ' ' '\n' | shuf -n $SIZE)"
        if ./push_swap $ARG | ./checker_linux $ARG | grep -q KO
        then
            echo "Error!"
            echo $ARG
            break
        fi
        NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
        if [ "$NUMBER" -gt "$LIMIT" ]
            then
            echo $NUMBER >> $FILE
            echo $ARG >> $FILE
        fi
        if [ "$NUMBER" -gt "$MAX" ]
            then
            MAX=$NUMBER;
        fi
        echo $i ":" $NUMBER
        let SUM+=$NUMBER;
        let ITERATIONS+=1
done

echo "AVG: $(($SUM / $ITERATIONS))"
echo "MAX: $MAX"
```