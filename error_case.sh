#!/bin/bash

./checker 1 2 3 4 -
./checker "-"
./checker "-one"
./checker " 1 one  2 3  4 "
./checker 1 "  2 3  4 " 1
./checker 2 +3  4- " "
./checker 2147483648 +3  4- " "
./checker +2147483648 +3  4- " "
./checker +2147483648 "++3"  4- " "
./checker "++3" 4- " "
./checker -2147483649 " "
./checker " "
./checker "" 33
