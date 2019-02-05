CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme:
	@gcc -o testme testme.c $(CFLAGS)

run: testme
	@./testme

coverage:
	@gcov testme.c -b >> coverageresults.out

clean:
	@rm -f *.o *.gcov *.gcda *.gcno testme *.out