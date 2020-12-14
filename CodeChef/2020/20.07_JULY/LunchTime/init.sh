#!/bin/bash

#touch "./input.txt"
#touch "./output.txt"
		
for ((i=1;i<=$1;i++))
	do
		cat /home/abhi/Desktop/cppTemp.cpp >> "./$i.cpp"
		echo "Coping file number $i..."
	done


