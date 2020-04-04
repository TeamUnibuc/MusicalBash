# Project Name (executable)
PROJECT = musicalbash.out
# Compiler
CPP = cpp
CXX = g++-8
CSTD = c++17

# Project options
SRC_FO = src

# Run Options       
COMMANDLINE_OPTIONS = 

# Compiler options during compilation
COMPILE_OPTIONS = -std=$(CSTD) -g -O0 -Wall -Wextra

#Header include directories
HEADERS = -Iinc/ -Iinc/player/ -Iinc/command/ -Iinc/application -Iinc/index -Iinc/ui
#Libraries for linking
LIBS = -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lmpg123

# Dependency options
DEPENDENCY_OPTIONS = -MM $(HEADERS) $(COMPILE_OPTIONS)

# Creating stats folder
# Stats part, kinda useless but hey
# Print how many files recalculated dependencies and how many recompiled
RESET_COMPILE = mkdir -p .stats; rm -f .stats/bash_count.txt; touch .stats/bash_count.txt
ADD_COMPILE = echo "X" >> .stats/bash_count.txt
SHOW_COMPILE = echo ""; echo Recompiled: $$(cat .stats/bash_count.txt)  ---  \
$$(cat .stats/bash_count.txt | wc -l)

SHELL_OUT := $(shell $(RESET_COMPILE))

#-- Do not edit below this line --

# Subdirs to search for additional source files
SUBDIRS := $(shell find $(SRC_FO) -type d )
DIRS := $(SUBDIRS)
SOURCE_FILES := $(foreach d, $(DIRS), $(wildcard $(d)/*.cpp))

# $(info DIRS = $(DIRS))
# $(info SRC = $(SOURCE_FILES))
# $(info SHOW = $(SHOW_HOW_MANY))

# Create an object file of every cpp file
OBJECTS = $(patsubst $(SRC_FO)/%.cpp, .dep/%.o, $(SOURCE_FILES))

# Dependencies
DEPENDENCIES = $(patsubst $(SRC_FO)/%.cpp, .dep/%.d, $(SOURCE_FILES))

# Create .d files
.dep/%.d: $(SRC_FO)/%.cpp | createDepFolder
	@echo Preprocess: $@
	@$(CPP) $(DEPENDENCY_OPTIONS) $< -MT ".dep/$*.o .dep/$*.d" -MF .dep/$*.d

# Make $(PROJECT) the default target
all: $(DEPENDENCIES) $(PROJECT)

$(PROJECT): $(OBJECTS)
	@printf "\nLinking $(PROJECT)\n"
	@$(CXX) -o $(PROJECT) $(OBJECTS) $(LIBS)
	@$(SHOW_COMPILE)

# $(info Before INCLUDE)

# Include dependencies (if there are any)
ifneq "$(strip $(DEPENDENCIES))" ""
 -include $(DEPENDENCIES)
endif

# Compile every cpp file to an object
.dep/%.o: $(SRC_FO)/%.cpp | createDepFolder # | resetCompile
	@echo Compile: $<
	@$(CXX) -c $(COMPILE_OPTIONS) $(HEADERS) -o $@ $< 
	@$(ADD_COMPILE)

# Build & Run Project
run: $(PROJECT)
	./$(PROJECT) $(COMMANDLINE_OPTIONS)

createDepFolder:
#	@echo Creating dependency folders
	@$(foreach folder,$(patsubst src/%,.dep/%,$(SOURCE_FILES)),\
 mkdir -p $(dir $(folder));)

# Clean & Debug
.PHONY: makefile-debug
makefile-debug:

.PHONY: clean
clean:
	rm -f $(PROJECT) $(OBJECTS)

.PHONY: depclean
depclean:
	rm -f $(DEPENDENCIES)

clean-all: clean depclean


.PHONY: resetCompile addCompile showCompile
resetCompile:
	$(RESET_COMPILE)

addCompile:
	$(ADD_COMPILE)

showCompile:
	@$(SHOW_COMPILE)

# MakeFile - Linux
# Needs working g++, if not on path rename CC variable

# PROGRAM_NAME = musicalbash.out

# CPP = cpp
# CSTD = c++17

# flags_all = -std=$(CSTD) -g -O0 -Wall -Wextra
# flags_fast = -std=$(CSTD) -O2

# src = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) 
# obj = $(src:src/%.cpp=$(objFO)/%.o)
# dep = $(src:src/%.cpp=$(depFO)/%.d)
# objFO = .obj
# depFO = .dep


# $(info SRC="$(objFO)")

# LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lmpg123
# INC_PARAMS = -Iinc/ -Iinc/player/ -Iinc/command/ -Iinc/application -Iinc/index -Iinc/ui
# SANITIZER = -fsanitize=address,undefined,signed-integer-overflow

# CFLAGS = $(flags_all) $(INC_PARAMS) $(SANITIZER)

# ifeq ($(shell echo $$USER), felix)
# 	GXX = g++-8
# 	lib_fs = -lstdc++fs
# else ifeq ($(shell $$USER), Constantin)
# 	GXX = g++-8
# 	lib_fs = -lstdc++fs
# else
# 	GXX = g++
# endif

# $(PROGRAM_NAME): $(obj)
# 	$(GXX) -o $@ $^ $(LDFLAGS) $(lib_fs) $(SANITIZER)

# # rule to generate a dep file by using the C preprocessor
# # (see man cpp for details on the -MM and -MT options)
# $(depFO)/%.d: src/%.cpp inc/%.hpp  
# 	@mkdir -p $(dir $@)
# 	@set -e; rm -f $@; \
# 	$(CPP) -MM $(CFLAGS) $< > $(depFO)/$*.d; \

# src/%.cpp inc/%.hpp:

# # $(objFO)/%.o: src/%.cpp $(depFO)/%.d
# # 	$(info Obj = $@)
# # 	@mkdir -p $(dir $@)
# # 	@$(GXX) $(CFLAGS) $(flags_all) -o $@ -c $<

# include $(src:src/%.cpp=$(depFO)/%.d)   # includes .o Recipes

# .PHONY: clean all cleandep
# clean:
# 	rm -f $(PROGRAM_NAME)
# 	rm -rf $(objFO)
# 	rm -rf $(depFO)

# cleandep:
# 	rm -rf $(depFO)

# all: $(PROGRAM_NAME)

# # INC_PARAMS = -Iinc/ -Iinc/player/ -Iinc/command/ -Iinc/application -Iinc/index -Iinc/ui
# # SCR_PARAMS = src/*.cpp src/*/*.cpp

# # LIB_PARAMS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lmpg123

# # # make all creates sanitized binary, overflows, illegal memory accesses and undefined behaviour raise an exception
# # all: $(sources)
# # 	g++ $(flags_all) $(INC_PARAMS) $(SCR_PARAMS) $(LIB_PARAMS) -o $(PROGRAM_NAME).out

# # # make fast compiles with -O2 flag
# # fast: $(sources)
# # 	g++ $(flags_fast) $(INC_PARAMS) $(LIB_PARAMS) $(SCR_PARAMS) -o $(PROGRAM_NAME).out
	
# # # removes a.out file
# # clean:
# # 	rm $(PROGRAM_NAME).out

# # run: $(sources)
# # 	g++ $(flags_all) $(INC_PARAMS) $(SCR_PARAMS) $(LIB_PARAMS) -o $(PROGRAM_NAME).out
# # 	./musicalbash.out