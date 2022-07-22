




my_pushswap()
{
	echo
	echo "CASE : $i"
	echo ---------------------------
	./push_swap "$i"
	echo ---------------------------
	printf "Total : "
	./push_swap "$i" | wc -l
	printf "Check : "
	./push_swap "$i" | ./checker_linux $i

}
