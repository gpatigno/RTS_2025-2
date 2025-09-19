#!/bin/bash
rm sal.txt;
for i in {1..5000}; 
do
	./race3 >> sal.txt;
done
code sal.txt;
