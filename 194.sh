
# 转制文本
#a b -> a\n b

colum=`head -n 1 file.txt | awk '{print NF}'`
for i in `seq 1 $colum`;do
	tmp=$(awk -v co=$i '{print $co}' file.txt)
	echo $tmp
done

