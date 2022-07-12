#!/bin/bash

./pushswap 1 2 3 4 -
./pushswap "-"
./pushswap "-one"
./pushswap " 1 one  2 3  4 "
./pushswap 1 "  2 3  4 " 1
./pushswap 2 +3  4- " "
./pushswap 2147483648 +3  4- " "
./pushswap +2147483648 +3  4- " "
./pushswap -2147483649 " "
./pushswap "" 33
