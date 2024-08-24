SUCCESS=0
FAIL=0
VERDICT=""

for flag in -e -i -v -c -l -n -h -s -o
do
	./s21_grep $flag and test.txt > s21_grep.txt
	grep $flag and test.txt > grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done

for flag in -f
do
  ./s21_grep $flag text.txt test.txt > s21_grep.txt
  grep $flag text.txt test.txt > grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done


echo "passed $SUCCESS tests"
echo "failed $FAIL tests"
