#ifndef GRAPTH_H
#define GRAPTH_H

#ifndef STACK_H
#include "stack.h"
#endif

#define Y_SIZE 25
#define X_SIZE 80
#define LEFT_BORDER 0
#define RIGHT_BORDER 4 * M_PI
#define UPPER_BORDER 1
#define LOWER_BORDER -1
#define PI acos(-1)

char *input_string();
char **create_matrix(int h, int w);
void free_matrix(char **matrix, int h);
void write_grapth(int ** matrix, struct node * line);
void print_graph(char **grapth, int h, int w);

#endif