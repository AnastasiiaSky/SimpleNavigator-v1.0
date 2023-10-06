CC = g++
CFLAGS=-lstdc++ -std=c++17
TFLAGS=-g -c -Wall -Werror -Wextra -g -lstdc++ -std=c++17 -lgtest -Wuninitialized -pedantic
GTEST=-lgtest -lgtest_main -pthread
ASAN=-fsanitize=address
COVER=-fprofile-arcs -ftest-coverage
COVFLAGS = -fprofile-arcs -ftest-coverage
# TARGET=./tests/mazeTest
VGFLAGS=--trace-children=yes --track-fds=all  --leak-check=full --show-leak-kinds=all --track-origins=yes
VAR = $(shell pkg-config --cflags --libs check)

.PHONY: all clean s21_graph.a s21_graph_algorithms.a tests leaks gcov_report stylecheck

all: clean s21_graph.a s21_algorithms.a

s21_graph.a:
	$(CC) $(TFLAGS) ./s21_graph/s21_graph.cc
	ar rcs s21_graph.a *.o
	ranlib s21_graph.a
	rm -rf *.o *.dSYM


s21_graph_algorithms.a:
	$(CC) $(TFLAGS) ./s21_algorithms/s21_graph_algorithms.cc
	ar rcs s21_algorithms.a *.o
	ranlib s21_algorithms.a
	rm -rf *.o *.dSYM

tests: clean
	@ g++ $(CFLAGS) $(COVER) tests.cc -o navigator_tests $(GTEST)
	./navigator_tests

stylecheck:
	cp ../materials/linters/.clang-format .clang-format 
	clang-format -style=Google -i *.cc s21_algorithms/*.cc s21_algorithms/*.h s21_graph/*.cc s21_graph/*.h
	clang-format -style=Google -n *.cc s21_algorithms/*.cc s21_algorithms/*.h s21_graph/*.cc s21_graph/*.h
	rm -rf .clang-format

clean:
	@rm -rf *.out
	@rm -rf navigator_tests
	@rm -rf ./s21_graph/*.dot
	@rm -rf *.a






# gcov_report: tests
# 	geninfo --ignore-errors mismatch . -b . -o ./coverage.info --no-external 
# 	genhtml coverage.info -o ./coverage
# 	open coverage/index.html
# 	@rm -rf *.gcda
# 	@rm -rf *.gcno

# leaks: tests
# 	leaks -atExit -- ./mazeTest
# #	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.cc *.h model/*.cc model/*.h ../view/*.cc ../view/*.h 

