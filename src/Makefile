CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LINUX=-lsubunit -lrt -lpthread -lm
LIBS = -lcheck
CFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

all: clean s21_math.a test

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	cp s21_math.a libs21_math.a
	cp s21_math.a ls21_math.a
	ranlib libs21_math.a
	ranlib ls21_math.a

s21_math.o: s21_math.c
	$(CC) -c s21_math.c -o s21_math.o

test: s21_math.a
ifeq ($(OS), Darwin)
	$(CC) test.c s21_math.a -o test $(LIBS)
	./test
else
	$(CC) test.c s21_math.a -o test $(LIBS) $(LINUX)
	./test
endif

gcov_report: s21_math.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) test.c s21_math.c s21_math.a -o test $(LIBS)
else
	$(CC) $(CFLAGS) test.c s21_math.c s21_math.a -o test $(LIBS) $(LINUX)
endif
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

open:
	open report/index.html

rebuild: clean all

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
	CK_FORK=no leaks --atExit -- ./test
	make clean

clean:
	rm -rf *.gc* *.o *.a *.out *.info test
	rm -rf report

a:
	make all
	make gcov_report
	make open
	rm -rf *.gc* *.o *.a *.out *.info test


b: 
	gcc s21.c s21_math.c
	./a.out 