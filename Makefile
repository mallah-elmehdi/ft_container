OUTPUT = ft

FLAG = -g -fsanitize=address #-std=c++98 #-Wall -Wextra -Werror

VECTOR_FILES = vector/*.cpp

STACK_FILES = stack/*.cpp

MAP_FILES = map/*.cpp

all: vector stack map

vector: $(VECTOR_FILES)
	@g++ $(FLAG) $(VECTOR_FILES) -o $(OUTPUT)

stack: $(STACK_FILES)
	@g++ $(FLAG) $(STACK_FILES) -o $(OUTPUT)

map: $(MAP_FILES)
	@g++ $(FLAG) $(MAP_FILES) -o $(OUTPUT)
