#!/bin/bash

./simulator 1 2 3 4 -
./simulator "-"
./simulator "-one"
./simulator " 1 one  2 3  4 "
./simulator 1 "  2 3  4 " 1
./simulator 2 +3  4- " "
./simulator 2147483648 +3  4- " "
./simulator +2147483648 +3  4- " "
./simulator -2147483649 " "
./simulator "" 33
