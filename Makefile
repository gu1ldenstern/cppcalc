BASE=g++ -std=c++17 -Wall -Wextra -Werror
LIB_TARGERS=model/model.cc
TEST_TARGETS=tests/main.cc tests/test.cc
TEST_FLAG=-lgtest
GCOV_FLAG=--coverage

all: clean test

test: s21_calculator.a
	@echo "\033[0;32m Compiling...\033[0m"
	$(BASE)  $(TEST_TARGETS) s21_calculator.a $(TEST_FLAG)
	./a.out

leaks:
	$(BASE) $(LIB_TARGERS) $(TEST_TARGETS) $(TEST_FLAG)
	valgrind ./a.out

s21_calculator.a:
	@echo "\033[0;33m Preparing a static library\033[0m"
	g++ -g -c -Wall -Wextra -Werror model/model.cc
	ar rc s21_calculator.a *.o
	ranlib s21_calculator.a
	@echo "\033[0;32m Static library is ready to be used\033[0m"

build:
	@cd .. && cmake -B build "cppcalc/" && make -C build untitled
	@mv ../build/untitled calculator
	@rm -rf ../build
	@./calculator

gcov_report:
	@echo "\033[0;33m Compiling...\033[0m"
	@$(BASE) $(LIB_TARGERS) $(TEST_TARGETS) $(TEST_FLAG) $(GCOV_FLAG)
	@./a.out
	@echo "\033[0;33m Preparing coverage report...\033[0m"
	@lcov -capture --directory . --output-file main_coverage.info
	@genhtml *.info -o ./gcov_report
	@echo "\033[0;33m Removing excess files...\033[0m"
	@rm -rf *.gcda *.gcno
	@echo "\033[31m Go to gcov_report folder and open index.html file\033[0m"

dvi:
	@doxygen Doxyfile

clang:
	cp ../materials/linters/.clang-format .clang-format
	@echo "\033[0;33m TO BE FORMATTED: \033[0m"
	
	@clang-format -n model/*.cc model/*.h tests/*.cc 2> res.txt
	@cat res.txt
	@if [ -s res.txt ]; then\
		echo "\033[31m PERFORMING FORMATTING... \033[0m";\
		clang-format -i tmodel/*.cc model/*.h tests/*.c;\
		echo "\033[1;32m RESULTS: \033[0m";\
		clang-format -n model/*.cc model/*.h tests/*.c;\
	else\
		echo "\033[1;32m YOUR FILE IS ALREADY FORMATTED \033[0m";\
	fi
	@echo "\033[0;33m MOVING CLANG BACK \033[0m"
	@rm  .clang-format res.txt


clean:
	@rm -rf a.out model.o calculator s21_calculator.h.gch s21_calculator.o s21_calculator.a *.gcda *.gcno gcov_report *.info doxygen 2> /dev/null
	@echo "\033[0;32m All temporary files have been removed\033[0m"


# cd ../ && cmake -B build "cppcalc/" && make -C build untitled