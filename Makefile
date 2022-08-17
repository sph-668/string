CC			= gcc -std=c11
CFLAGS			= 
EXTRA_CFLAGS		=
TEST_CFLAGS		= -I check/include -L check/Cellar/check/0.15.2/lib -lcheck
OUTPUT_NAME		= s21_string+
C_FILES			= s21_string.c s21_sprintf.c s21_legacy.c

all: fullclean s21_string.a test gcov_report

clean:
	rm -f *.o *.info *.gcno *.gcda gcov_report all

test:
	$(CC) -c $(CFLAGS) $(EXTRA_CFLAGS) $(TEST_CFLAGS) s21_string.c
	ar r s21_string.a s21_string.o
	$(CC) -L. -I. $(TEST_CFLAGS) -o s21_string+ s21_string.a *.c
	rm -f *.o all

s21_string.a:
	$(CC) -c $(CFLAGS) $(EXTRA_CFLAGS) $(TEST_CFLAGS) *.c
	ar rcs s21_string.a s21*.o
	ar rcs libs21_string.a s21*.o
	make clean

gcov_report:
	make fullclean
	$(CC) -c $(CFLAGS) $(EXTRA_CFLAGS) $(TEST_CFLAGS) s21_string.c
	ar r s21_string.a s21_string.o
	$(CC) -o s21_string+ --coverage $(CFLAGS) $(EXTRA_CFLAGS) $(TEST_CFLAGS) *.c -lcheck   
	./s21_string+
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	make clean

rebuild: 
	rm -f $(OUTPUT_NAME)
	make clean
	make all

fullclean:
	rm -f $(OUTPUT_NAME)
	rm -f *.o *.a *.info *.gcno *.gcda all
	rm -rf report

sscanf_test:
	$(CC) $(C_FILES) $(CFLAGS) -o scanf_test