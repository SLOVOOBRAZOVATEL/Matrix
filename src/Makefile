CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
SRCDIR = CORE
OBJDIR = obj

UNAME := $(shell uname -s)
ifeq ($(UNAME),Darwin) 
    CCFLAGS = $(shell pkg-config --cflags check) 
    LIBS = $(shell pkg-config --libs check)      
else
	CCFLAGS = -I/usr/include
    LIBS = -lcheck -lm -lsubunit 
endif

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

$(shell mkdir -p $(OBJDIR))

NAME = s21_matrix.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

# test: TESTS/asd.o s21_matrix.check
# 	$(CC) -o test TESTS/asd.o s21_matrix.check $(LIBS)
# 	./test

test: TESTS/asd.o s21_matrix.check
	$(CC) -o test TESTS/asd.o s21_matrix.check $(LIBS)
	./test

s21_matrix.check: $(OBJS)
	$(CC)  $(CCFLAGS) $(CFLAGS) $(SRCS) 
	ar rc s21_matrix.check $(OBJS) 
	ranlib s21_matrix.check

TESTS/asd.o: TESTS/asd.c
	$(CC) $(CFLAGS) $(CCFLAGS) -c TESTS/asd.c -o TESTS/asd.o

TESTS/asd.c:
	checkmk clean_mode=1 TESTS/asd.check > TESTS/asd.c

gcov_report: TESTS/asd.c $(SRCS)
	$(CC) --coverage $(SRCS) TESTS/asd.c -o s21_test $(CCFLAGS) $(LIBS)
	./s21_test
	gcov -l -p -c *.gcno
	-rm -rf s21_test-asd*
	gcovr --html --html-details -o gcov_report.html
	open gcov_report.html 


rebuild: clean all 

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $(SRCDIR)/*.c *.h
	-rm -rf .clang-format

clean:
	-rm -rf *.o *.gcno *.a *.check *.gcda *.info *.gcov ./test ./gcov_report
	-rm -rf ./report/
	-rm -rf obj
	-rm -rf s21_test
	-rm -rf TESTS/*.o TESTS/asd.c
	-rm -rf gcov*

.PHONY: clean clang all rebuild test
