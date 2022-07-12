#!/bin/bash


ARG00=("0 1 2 3 4" "0 2 3 1 4" "0 3 1 2 4" "0 1 3 2 4" "0 2 1 3 4" "0 3 2 1 4")
ARG01=("0 1 2 4 3" "0 2 3 4 1" "0 3 1 4 2" "0 1 3 4 2" "0 2 1 4 3" "0 3 2 4 1")
ARG02=("0 1 4 2 3" "0 2 4 3 1" "0 3 4 1 2" "0 1 4 3 2" "0 2 4 1 3" "0 3 4 2 1")
ARG03=("0 4 1 2 3" "0 4 2 3 1" "0 4 3 1 2" "0 4 1 3 2" "0 4 2 1 3" "0 4 3 2 1")

ARG03=("1 0 2 3 4" "1 0 3 2 4" "1 2 3 0 4" "1 2 0 3 4" "1 3 0 2 4" "1 3 2 0 4")
ARG04=("1 0 2 4 3" "1 0 3 4 2" "1 2 3 4 0" "1 2 0 4 3" "1 3 0 4 2" "1 3 2 4 0")
ARG05=("1 0 4 2 3" "1 0 4 3 2" "1 2 4 3 0" "1 2 4 0 3" "1 3 4 0 2" "1 3 4 2 0")
ARG06=("1 4 0 2 3" "1 4 0 3 2" "1 4 2 3 0" "1 4 2 0 3" "1 4 3 0 2" "1 4 3 2 0")

ARG07=("2 0 1 3 4" "2 1 3 0 4" "2 3 0 1 4" "2 0 3 1 4" "2 1 0 3 4" "2 3 1 0 4")
ARG08=("2 0 1 4 3" "2 1 3 4 0" "2 3 0 4 1" "2 0 3 4 1" "2 1 0 4 3" "2 3 1 4 0")
ARG09=("2 0 4 1 3" "2 1 4 3 0" "2 3 4 0 1" "2 0 4 3 1" "2 1 4 0 3" "2 3 4 1 0")
ARG10=("2 4 0 1 3" "2 4 1 3 0" "2 4 3 0 1" "2 4 0 3 1" "2 4 1 0 3" "2 4 3 1 0")

ARG11=("3 0 1 2 4" "3 1 2 0 4" "3 2 0 1 4" "3 0 2 1 4" "3 1 0 2 4" "3 2 1 0 4")
ARG13=("3 0 1 4 2" "3 1 2 4 0" "3 2 0 4 1" "3 0 2 4 1" "3 1 0 4 2" "3 2 1 4 0")
ARG14=("3 0 4 1 2" "3 1 4 2 0" "3 2 4 0 1" "3 0 4 2 1" "3 1 4 0 2" "3 2 4 1 0")
ARG15=("3 4 0 1 2" "3 4 1 2 0" "3 4 2 0 1" "3 4 0 2 1" "3 4 1 0 2" "3 4 2 1 0")

ARG16=("4 1 0 2 3" "4 1 0 3 2" "4 1 2 3 0" "4 1 2 0 3" "4 1 3 0 2" "4 1 3 2 0")
ARG17=("4 2 0 1 3" "4 2 1 3 0" "4 2 3 0 1" "4 2 0 3 1" "4 2 1 0 3" "4 2 3 1 0")
ARG18=("4 3 0 1 2" "4 3 1 2 0" "4 3 2 0 1" "4 3 0 2 1" "4 3 1 0 2" "4 3 2 1 0")
ARG19=("4 0 1 2 3" "4 0 2 3 1" "4 0 3 1 2" "4 0 1 3 2" "4 0 2 1 3" "4 0 3 2 1")

# ARG_cnt_0=("0 1 2 3 4")
# ARG_cnt_1=("1 2 3 4 0" "4 0 1 2 3" "1 0 2 3 4")
# ARG_cnt_2=("2 1 3 4 0" "2 3 4 0 1" "0 1 3 4 0")
# ARG_cnt_3=("3 4 0 1 2")
# ARG_cnt_4=()
# ARG_cnt_2=("0 2 3 1" "0 3 1 2" "2 1 3 0" "2 3 0 1" "3 1 0 2" )
# ARG_cnt_3=("0 2 1 3" "1 3 0 2" "2 0 3 1" "2 3 1 0" "3 2 0 1" "3 1 2 0" )
# ARG_cnt_4=("0 1 3 2" "1 2 0 3" "2 0 1 3" "3 2 1 0" "3 0 2 1")
# ARG_cnt_5=("0 3 2 1" "1 3 2 0" "2 1 0 3")
# ARG_cnt_6=("1 0 3 2")

my_pushswap()
{
	echo
	echo "CASE : $i"
	./pushswap "$i"
}

for i in "${ARG00[@]}"
do
	my_pushswap
done

for i in "${ARG01[@]}"
do
	my_pushswap
done

for i in "${ARG02[@]}"
do
	my_pushswap
done

for i in "${ARG03[@]}"
do
	my_pushswap
done

for i in "${ARG04[@]}"
do
	my_pushswap
done

for i in "${ARG05[@]}"
do
	my_pushswap
done

for i in "${ARG06[@]}"
do
	my_pushswap
done

for i in "${ARG07[@]}"
do
	my_pushswap
done

for i in "${ARG08[@]}"
do
	my_pushswap
done

for i in "${ARG08[@]}"
do
	my_pushswap
done

for i in "${ARG09[@]}"
do
	my_pushswap
done

for i in "${ARG10[@]}"
do
	my_pushswap
done

for i in "${ARG11[@]}"
do
	my_pushswap
done

for i in "${ARG12[@]}"
do
	my_pushswap
done

for i in "${ARG13[@]}"
do
	my_pushswap
done

for i in "${ARG14[@]}"
do
	my_pushswap
done

for i in "${ARG15[@]}"
do
	my_pushswap
done

for i in "${ARG16[@]}"
do
	my_pushswap
done

for i in "${ARG17[@]}"
do
	my_pushswap
done

for i in "${ARG18[@]}"
do
	my_pushswap
done

for i in "${ARG19[@]}"
do
	my_pushswap
done
#------------------

