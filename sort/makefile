sort: sort.o mergesort.o
	gcc sort.o mergesort.o -o sort
sort.o: sort.c mergesort.h
	gcc -g -Wall -Werror -pedantic-errors -c sort.c
mergesort.o: mergesort.c mergesort.h 
	gcc -g -Wall -Werror -pedantic-errors -c mergesort.c
clean:
	rm -f *.o sort.exe