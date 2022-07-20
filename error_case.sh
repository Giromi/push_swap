#!/bin/bash

./push_swap 1 2 3 4 -
./push_swap "-"
./push_swap "-one"
./push_swap " 1 one  2 3  4 "
./push_swap 1 "  2 3  4 " 1
./push_swap 2 +3  4- " "
./push_swap 2147483648 +3  4- " "
./push_swap +2147483648 +3  4- " "
./push_swap +2147483648 "++3"  4- " "
./push_swap "++3" 4- " "
./push_swap -2147483649 " "
./push_swap " "
./push_swap "" 33
