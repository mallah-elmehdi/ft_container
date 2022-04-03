OUTPUT = ft

FLAG = -fsanitize=address #-std=c++98 #-Wall -Wextra -Werror

VECTOR_FILES = ./vector/*.cpp

all: vector

vector: $(VECTOR_FILES)
	@clang++-9 $(FLAG) $(VECTOR_FILES) -o $(OUTPUT)
