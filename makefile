# MakeFile - Linux
# Needs working g++, if not on path rename CC variable

PROGRAM_NAME = musicalbash

flags_all = -std=c++11 -g -O0 -Wall -Wextra -fsanitize=address,undefined,signed-integer-overflow
flags_fast = -std=c++11 -O2

INC_PARAMS = -Iinc/
SCR_PARAMS = main.cpp src/*.cpp
LIB_PARAMS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lmpg123

# make all creates sanitized binary, overflows, illegal memory accesses and undefined behaviour raise an exception
all: $(sources)
	g++ $(flags_all) $(INC_PARAMS) $(SCR_PARAMS) $(LIB_PARAMS) -o $(PROGRAM_NAME).out

# make fast compiles with -O2 flag
fast: $(sources)
	g++ $(flags_fast) $(INC_PARAMS) $(LIB_PARAMS) $(SCR_PARAMS) -o $(PROGRAM_NAME).out
	
# removes a.out file
clean:
	rm $(PROGRAM_NAME).out
	