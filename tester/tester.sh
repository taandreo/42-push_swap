#!/bin/bash

AMOUNT=10
SIZE=500
MAX=0
ITERATIONS=0
LIMIT=5500
FILE="above_limit_for_$SIZE"
SUM=0

for i in $(seq 1 $AMOUNT)
do
        export ARG="$(seq 1 $SIZE | shuf -n $SIZE)"
        if ../push_swap $ARG | ../checker_linux $ARG | grep -q KO
        then
            echo "Error!"
            echo $ARG
            break
        fi
        NUMBER="$(../push_swap $ARG | wc -l | sed 's/ //g')"
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