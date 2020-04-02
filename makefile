# MakeFile - Linux
# Needs working g++, if not on path rename CC variable

PROGRAM_NAME = musicalbash

GXX = g++-8
CSTD = c++17

flags_all = -std=$(CSTD) -g -O0 -Wall -Wextra -fsanitize=address,undefined,signed-integer-overflow
flags_fast = -std=$(CSTD) -O2

INC_PARAMS = -Iinc/ -Iinc/*/ -Iinc/player/ -Iinc/command/
SCR_PARAMS = src/*.cpp src/*/*.cpp

LIB_PARAMS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lmpg123 -lstdc++fs

# make all creates sanitized binary, overflows, illegal memory accesses and undefined behaviour raise an exception
all: $(sources)
	$(GXX) $(flags_all) $(INC_PARAMS) $(SCR_PARAMS) $(LIB_PARAMS) -o $(PROGRAM_NAME).out

# make fast compiles with -O2 flag
fast: $(sources)
	$(GXX) $(flags_fast) $(INC_PARAMS) $(LIB_PARAMS) $(SCR_PARAMS) -o $(PROGRAM_NAME).out
	
# removes a.out file
clean:
	rm $(PROGRAM_NAME).out

run: $(sources)
	$(GXX) $(flags_all) $(INC_PARAMS) $(SCR_PARAMS) $(LIB_PARAMS) -o $(PROGRAM_NAME).out
	./musicalbash.out