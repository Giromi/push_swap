#!/bin/bash

#ARG0=("9 8 7 0 1 " "9 8 7 1 0")
#ARG1=("9 8 7 0 1 2" "9 8 7 0 2 1")
#ARG2=("9 8 7 1 0 2" "9 8 7 1 2 0")
#ARG3=("9 8 7 2 0 1" "9 8 7 2 1 0")

ARG1=("0 1 2 9 8 7" "0 2 1 9 8 7")
ARG2=("1 0 2 9 8 7" "1 2 0 9 8 7")
ARG3=("2 0 1 9 8 7" "2 1 0 9 8 7")

ARG_cnt_0=("0" "0 1" "0 1 2")
ARG_cnt_1=("1 0" "1 0 2" "1 2 0" "2 0 1")
ARG_cnt_2=("0 2 1" "2 1 0")

my_pushswap()
{
	echo
	echo
	echo
	echo "CASE : $i"
	./push_swap "$i"
}

# for i in "${ARG0[@]}"
# do
	# my_pushswap
# done

for i in "${ARG1[@]}"
do
	my_pushswap
done

for i in "${ARG2[@]}"
do
	my_pushswap
done

for i in "${ARG3[@]}"
do
	my_pushswap
done

# echo
# echo
# echo "@@@@@@@ [Total = 0] @@@@@@@"
# for i in "${ARG_cnt_0[@]}"
# do
	# my_pushswap
# done

# echo
# echo
# echo "@@@@@@@ [Total = 1t] @@@@@@@"
# for i in "${ARG_cnt_1[@]}"
# do
	# my_pushswap
# done

# echo
# echo
# echo "@@@@@@@ [Total = 2] @@@@@@@"
# for i in "${ARG_cnt_2[@]}"
# do
	# my_pushswap
# done




#not
#0 1 2



