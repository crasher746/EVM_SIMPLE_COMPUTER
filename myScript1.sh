#!/bin/bash

printf "\E[H\E[J"
printf "\E[10;5H"
printf "\E(0"

printf "l"

for var_line in {6..14}
do
	printf "q"
done

printf "k"

for var_column in {11..18}
do
	printf "\E[$var_column;15H"
	printf "x"
done

printf "\E[18;15H"
printf "j"
printf "\E[18;6H"

for var_line1 in {6..14}
do	
	printf "q"
done

printf "\E[18;5H"
printf "m"

for var_column in {17..11}
do
	printf "\E[$var_column;5H"
	printf "x"
done

for upline_nine in {1..9}
do
	printf "a"
done

for rightline_nine in {11..17}
do 
	printf "\E[$rightline_nine;14H"
	printf "a"
done

printf "\E[17;6H"

for upline_nine in {1..9}
do
	printf "a"
done

printf "\E[1;6H"

for leftline_nine in {11..14}
do
	printf "\E[$leftline_nine;6H"
	printf "a"
done

for midline_nine in {1..8}
do
	printf "a"
done
printf "\E[14;17H"
printf "\E(B"
