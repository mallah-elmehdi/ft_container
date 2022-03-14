OUTPUT = ft

FLAG = #-Wall -Wextra -Werror

VECTOR_FILES = ./vector/*.cpp

all: vector

vector: $(VECTOR_FILES)
	@clang++ -std=c++98 $(FLAG) $(VECTOR_FILES) -o $(OUTPUT)
