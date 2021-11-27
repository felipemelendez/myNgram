make_test:
	echo "Makefile executed"

compile:
	gcc -Wall -Wextra -Werror my_ngram.c && ./a.out "Morgan & Felipe are working on my_ngram" "and makefile" " &&&&&"

conquer:
	gcc -Wall -Wextra -Werror my_ngram.c && ./a.out "Morgan & Felipe are working on my_ngram" "and makefile"cat -e -t -v
