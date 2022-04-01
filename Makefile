OUTPUT = ft

FLAG = -fsanitize=address #-Wall -Wextra -Werror

VECTOR_FILES = ./vector/*.cpp

all: vector

vector: $(VECTOR_FILES)
	@g++ -std=c++98 $(FLAG) $(VECTOR_FILES) -o $(OUTPUT)
