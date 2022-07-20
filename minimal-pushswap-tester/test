executable_path=$2
count=$1
output="log_$count"
sh random $count | xargs $executable_path > $output
cat $output
echo "\ncount: $(wc -l < $output)"
