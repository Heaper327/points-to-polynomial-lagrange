CXX=clang++
INCLUDES=-Iincludes/
CXXEXTRAS=-Wall -Wextra -Werror -pedantic
CXXFLAGS=-std=c++2a -g -fstandalone-debug
ASANFLAGS=-fsanitize=address -fno-omit-frame-pointer

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./src/cord.cc ./src/cord-utilities.cc ./includes/cord.hpp ./includes/cord-utilities.hpp ./includes/cs128referencelist.hpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRAS) $(INCLUDES) ./src/* -o $@

bin/tests: ./tests/tests.cc obj/catch.o ./src/cord.cc ./src/cord-utilities.cc ./includes/cord.hpp ./includes/cord-utilities.hpp ./includes/cs128referencelist.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./tests/tests.cc obj/catch.o ./src/illini_book.cc ./src/utilities.cc -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*
