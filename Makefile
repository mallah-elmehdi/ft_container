OUTPUT = ft

FLAG = -g -fsanitize=address -std=c++98 #-Wall -Wextra -Werror

VECTOR_FILES = ./vector/*.cpp

all: vector

vector: $(VECTOR_FILES)
	@clang++ $(FLAG) $(VECTOR_FILES) -o $(OUTPUT)
