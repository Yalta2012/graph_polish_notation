FLAGS = -Wall -Werror -Wextra -std=c11
POST_FLAGS = -lm
BUILD = ../build
all: graph

graph: graph.o stack.o stack_math.o
	gcc -g $(FLAGS) $(BUILD)/stack.o $(BUILD)/stack_math.o $(BUILD)/graph.o   -o $(BUILD)/graph $(POST_FLAGS)


graph.o: graph.c
	gcc -g -c $(FLAGS) graph.c -o $(BUILD)/graph.o $(POST_FLAGS)

stack.o: stack.c
	gcc -g -c $(FLAGS) stack.c -o $(BUILD)/stack.o $(POST_FLAGS)

stack_math.o: stack_math.c
	gcc -g -c $(FLAGS) stack_math.c -o $(BUILD)/stack_math.o $(POST_FLAGS)