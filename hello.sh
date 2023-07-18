#!/bin/bash 

echo hello

STR="Hello World"
NUM=5

echo $STR
echo $NUM

#ARITHMETIC
#$(( (math) ))
echo $(( (3+4) * NUM ))



# #CONDITIONAL
# if [[ condition ]]; then
# #
# #
# #
# else
# #
# #
# #
# fi

#ARRAY
arr=( 10 20 "new" "old")

for elem in ${arr[@]} ;do
    echo $elem
done

for index in ${!arr[@]} ; do
    echo $index ${arr[$index]}

done


echo ${arr[@]} #print elements
echo ${!arr[@]} #print indecies
echo ${#arr[@]} #print #of elem

echo {20..40}
echo {50..30}
echo {a..z}


function fname {
    echo $1
    echo $2
    echo $3
}

fname 20 "pass" 30