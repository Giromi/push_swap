count=$1
numbers=""
for ((i=1; i<$count; i++))
do
	if (($RANDOM%2)); then numbers+="-"; fi
	numbers+="$RANDOM "
done
echo $numbers$RANDOM
