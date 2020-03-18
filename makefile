# MakeFile - Linux
# Needs working g++, if not on path rename CC variable

sources = main.cpp console_manipulation.cpp sprite.cpp text_box.cpp
CC = g++
flags_all = -std=c++11 -g -O0 -Wall -Wextra -fsanitize=address,undefined,signed-integer-overflow
flags_fast = -std=c++11 -O2

# make all creates sanitized binary, overflows, illegal memory accesses and undefined behaviour raise an exception
all: $(sources)
	$(CC) $(flags_all) $(sources)

# make fast compiles with -O2 flag
fast: $(sources)
	$(CC) $(flags_fast) $(sources)
	
# removes a.out file
clean:
	rm a.out

