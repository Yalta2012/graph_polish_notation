#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init() {
    struct node* res = malloc(sizeof(struct node));
    if (res) {
        res->value.number = 0;
        res->type = -1;
        res->next = 0;
    }
    return res;
}

struct node* push_number(struct node* first, long double input) {
    struct node* res = malloc(sizeof(struct node));
    if (res) {
        res->value.number = input;
        res->type = 1;
        res->next = first;
    } else {
        res = first;
    }
    return res;
}

struct node* push_symbol(struct node* first, char input) {
    struct node* res = malloc(sizeof(struct node));
    if (res) {
        res->value.number = 0;
        res->value.symbol = input;
        res->type = 0;
        res->next = first;
    } else {
        res = first;
    }
    return res;
}

struct node* pop(struct node* first) {
    struct node* res = first->next;
    free(first);
    return res;
}

void destroy(struct node* first) {
    struct node* index = first;
    while (index) {
        struct node* next = index->next;
        free(index);
        index = next;
    }
}

void output_function(struct node* first) {
    struct node* index = first;
    if (!first) return;

    do {
        if (index->type == 1) {
            printf("%Lf", index->value.number);
        } else if (index->type == 0) {
            printf("%c", index->value.symbol);
        }
        index = index->next;
        if (index->next) {
            printf(" ");
        }
    } while (index->next);
}