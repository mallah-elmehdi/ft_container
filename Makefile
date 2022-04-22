OUTPUT = ft

FLAG = -std=c++98 -Wall -Wextra -Werror

VECTOR_FILES = vector/main.cpp

STACK_FILES = stack/main.cpp

MAP_FILES = map/main_tester.cpp

vector: $(VECTOR_FILES)
	@clang++ $(FLAG) $(VECTOR_FILES) -o $(OUTPUT)

stack: $(STACK_FILES)
	@clang++ $(FLAG) $(STACK_FILES) -o $(OUTPUT)

map: $(MAP_FILES)
	@clang++ $(FLAG) $(MAP_FILES) -o $(OUTPUT)

clear:
	@rm -f $(OUTPUT)