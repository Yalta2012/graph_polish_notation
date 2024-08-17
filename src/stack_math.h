#ifndef STMATH_H
#define STMATH_H

#ifndef STACK_H
#include "stack.h"
#endif

#define EPS 1e-9
long double polish_calculation(struct node* line, long double x);
struct node* use_binary_operator(struct node* stack, char operator, int * flag);
struct node* use_unary_operator(struct node* stack, char operator, int * flag);
struct node* use_operator(struct node* stack, char operator, int * flag);

#endif