#!/bin/bash


ARG_cnt_0=("0" "0 1" "0 1 2")
ARG_cnt_1=("1 0 2" "1 2 0" "2 0 1")
ARG_cnt_2=("0 2 1" "2 1 0")

my_pushswap()
{
	echo
	echo "CASE : $i"
	./pushswap "$i"
}

echo
echo
echo "@@@@@@@ [Total = 0] @@@@@@@"
for i in "${ARG_cnt_0[@]}"
do
	my_pushswap
done

echo
echo
echo "@@@@@@@ [Total = 1t] @@@@@@@"
for i in "${ARG_cnt_1[@]}"
do
	my_pushswap
done

echo
echo
echo "@@@@@@@ [Total = 2] @@@@@@@"
for i in "${ARG_cnt_2[@]}"
do
	my_pushswap
done




#not
#0 1 2



