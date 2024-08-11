#ifndef STACK_H
#define STACK_H

union data {
    char symbol;
    long double number;
};

// type -1 - end, 0 - char, else - int
struct node {
    union data value;
    char type;
    struct node* next;
};
struct node* init();
struct node* push_number(struct node* first, long double input);
struct node* push_symbol(struct node* first, char input);
struct node* pop(struct node* first);
void destroy(struct node* first);
void output_function(struct node* first);
#endif