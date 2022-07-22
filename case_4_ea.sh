#!/bin/bash


# ARG0=("9 8 7 0 1 2 3" "9 8 7 0 2 3 1" "9 8 7 0 3 1 2" "9 8 7 0 1 3 2" "9 8 7 0 2 1 3" "9 8 7 0 3 2 1")
# ARG1=("9 8 7 1 0 2 3" "9 8 7 1 0 3 2" "9 8 7 1 2 3 0" "9 8 7 1 2 0 3" "9 8 7 1 3 0 2" "9 8 7 1 3 2 0")
# ARG2=("9 8 7 2 0 1 3" "9 8 7 2 1 3 0" "9 8 7 2 3 0 1" "9 8 7 2 0 3 1" "9 8 7 2 1 0 3" "9 8 7 2 3 1 0")
# ARG3=("9 8 7 3 0 1 2" "9 8 7 3 1 2 0" "9 8 7 3 2 0 1" "9 8 7 3 0 2 1" "9 8 7 3 1 0 2" "9 8 7 3 2 1 0")

#ARG0=("0 1 2 3 9 8 7" "0 2 3 1 9 8 7" "0 3 1 2 9 8 7" "0 1 3 2 9 8 7" "0 2 1 3 9 8 7" "0 3 2 1 9 8 7")
#ARG1=("1 0 2 3 9 8 7" "1 0 3 2 9 8 7" "1 2 3 0 9 8 7" "1 2 0 3 9 8 7" "1 3 0 2 9 8 7" "1 3 2 0 9 8 7")
#ARG2=("2 0 1 3 9 8 7" "2 1 3 0 9 8 7" "2 3 0 1 9 8 7" "2 0 3 1 9 8 7" "2 1 0 3 9 8 7" "2 3 1 0 9 8 7")
#ARG3=("3 0 1 2 9 8 7" "3 1 2 0 9 8 7" "3 2 0 1 9 8 7" "3 0 2 1 9 8 7" "3 1 0 2 9 8 7" "3 2 1 0 9 8 7")

ARG_cnt_0=("0 1 2 3")
ARG_cnt_1=("1 0 2 3" "1 2 3 0" "3 0 1 2")
ARG_cnt_2=("0 2 3 1" "0 3 1 2" "2 1 3 0" "2 3 0 1" "3 1 0 2" )
ARG_cnt_3=("0 2 1 3" "1 3 0 2" "2 0 3 1" "2 3 1 0" "3 2 0 1" "3 1 2 0" )
ARG_cnt_4=( "1 2 0 3" "1 3 2 0" "2 0 1 3" "3 2 1 0" "3 0 2 1")
ARG_cnt_5=("0 3 2 1" "0 1 3 2" "2 1 0 3")
ARG_cnt_6=("1 0 3 2")

my_pushswap()
{
	echo
	echo "CASE : $i"
	echo ---------------------------
	./push_swap "$i"
	echo ---------------------------
	printf "Total : "
	./push_swap "$i" | wc -l
	printf "Sort : %s == %s\n" $(./push_swap "$i" | ./checker_Mac $i) $(./push_swap "$i" | ./checker $i)
}
# for i in "${ARG0[@]}"
# do
	# my_pushswap
# done

# for i in "${ARG1[@]}"
# do
	# my_pushswap
# done

# for i in "${ARG2[@]}"
# do
	# my_pushswap
# done

# for i in "${ARG3[@]}"
# do
	# my_pushswap
# done
#------------------

# printf "\n\n@@@@@@@ [Total = 0] @@@@@@@\n"
# for i in "${ARG_cnt_0[@]}"
# do
	# my_pushswap
# done

printf "\n\n@@@@@@@ [Total = 1] @@@@@@@\n"
for i in "${ARG_cnt_1[@]}"
do
	my_pushswap
done

printf "\n\n@@@@@@@ [Total = 2] @@@@@@@\n"
for i in "${ARG_cnt_2[@]}"
do
	my_pushswap
done

printf "\n\n@@@@@@@ [Total = 3] @@@@@@@\n"
for i in "${ARG_cnt_3[@]}"
do
	my_pushswap
done

printf "\n\n@@@@@@@ [Total = 4] @@@@@@@\n"
for i in "${ARG_cnt_4[@]}"
do
	my_pushswap
done

printf "\n\n@@@@@@@ [Total = 5] @@@@@@@\n"
for i in "${ARG_cnt_5[@]}"
do
	my_pushswap
done

printf "\n\n@@@@@@@ [Total = 6] @@@@@@@\n"
for i in "${ARG_cnt_6[@]}"
do
	my_pushswap
done
