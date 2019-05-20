#!/bin/bash
# 统计词频

while read -r line;do
	 for word in $line;do
	 	echo -e  $word
	 done
done  < words.txt |  awk '{sum[$1]++} END{for (i in sum) print i, sum[i]}'  | sort -n -k2 -r










#sed 's/ /\n/g' words.txt | 








