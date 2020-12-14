#!/bin/bash
for ((i=1;i<=$1;i++))
	do
		mkdir ./$i
		touch "./$i/input.txt"
		touch "./$i/output.txt"
		cat /home/abhi/Desktop/cppTemp.cpp >> "./$i/$i.cpp"
		echo "Creating Folder and coping file number $i..."
	done


