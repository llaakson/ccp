#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

declare -a input=(
	"1 2 +" "4 3 *" "8 9 * 9 - 9 - 9 - 4 - 1 + "  "7 7 * 7 -"
     "1 2 * 2 / 2 * 2 4 - +" "3 4 5 + *" "2 3 4 * +" "4 3 3 3 3 3 3 - - - - - -"
	)

for i in "${input[@]}"
do
	printf "input: %s\n" "$i"
    result=$(./RPN "$i" 2>&1)
    printf "result: ${GREEN}%s${NC}\n\n" "$result"
done

declare -a input2=(
	"10 2 /" "100 200 +" "-5 3 +" "" "                    "
    "3" "3 3" "3 3 3" "3 - -" "- - - - - -" "-2 -2 /" "4 0 /" "(1 + 1)" "Hellow World"
	)

for i in "${input2[@]}"
do
	printf "input: %s\n" "$i"
    result=$(./RPN "$i" 2>&1)
    printf "result: ${RED}%s${NC}\n\n" "$result"
done
