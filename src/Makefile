FLAGS = -Wall -Werror -Wextra -std=c11
POST_FLAGS = -lm
BUILD = ../build
all: graph

graph: graph.o stack.o stack_math.o polish_input.o
	gcc $(BUILD)/graph.o $(FLAGS) $(BUILD)/stack.o $(BUILD)/stack_math.o    $(BUILD)/polish_input.o -o $(BUILD)/graph $(POST_FLAGS)

	
graph.o: graph.c
	gcc -c $(FLAGS) graph.c -o $(BUILD)/graph.o $(POST_FLAGS)

stack.o: stack.c
	gcc -c $(FLAGS) stack.c -o $(BUILD)/stack.o $(POST_FLAGS)

stack_math.o: stack_math.c
	gcc -c $(FLAGS) stack_math.c -o $(BUILD)/stack_math.o $(POST_FLAGS)

polish_input.o: polish_input.c
	gcc -c $(FLAGS) polish_input.c -o $(BUILD)/polish_input.o $(POST_FLAGS)
