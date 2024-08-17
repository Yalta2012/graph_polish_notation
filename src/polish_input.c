#include "polish_input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

struct node *translateToPolishAnn(struct node *queue, char *inputStr) {
    struct node *stack = init();
    for (int i = 0; i < (int)strlen(inputStr); i++) {
        if ((inputStr[i] > 47 && inputStr[i] < 58) || inputStr[i] == '.') {
            int lastPosNum = i;
            while ((inputStr[lastPosNum + 1] > 47 && inputStr[lastPosNum + 1] < 58) ||
                   inputStr[lastPosNum + 1] == '.') {
                lastPosNum++;
            }
            long double num;
            sscanf(&inputStr[i], "%Lf", &num);
            i = lastPosNum;
            queue = push_number_in_queue(queue, num);
        } else if (inputStr[i] == '+' || inputStr[i] == '-') {
            while (stack && stack->type == 0 && (strchr("+-*/", stack->value.symbol))) {
                queue = push_symbol_in_queue(queue, stack->value.symbol);
                stack = pop(stack);
            }
            stack = push_symbol(stack, inputStr[i]);
        } else if (inputStr[i] == '*' || inputStr[i] == '/') {
            while (stack && stack->type == 0 && (stack->value.symbol == '*' || stack->value.symbol == '/')) {
                queue = push_symbol_in_queue(queue, stack->value.symbol);
                stack = pop(stack);
            }
            stack = push_symbol(stack, inputStr[i]);
        } else if (inputStr[i] == '(') {
            stack = push_symbol(stack, inputStr[i]);
        } else if (inputStr[i] == ')') {
            while (stack->type == 0 && (stack->value.symbol != '(')) {
                queue = push_symbol_in_queue(queue, stack->value.symbol);
                stack = pop(stack);
            }
            stack = pop(stack);
            if (strchr("sctTqL", stack->value.symbol)) {
                queue = push_symbol_in_queue(queue, stack->value.symbol);
                stack = pop(stack);
            }
        } else if (strchr("~sctTqL", inputStr[i]))
            stack = push_symbol(stack, inputStr[i]);
        else if (inputStr[i] == 'x')
            queue = push_symbol_in_queue(queue, inputStr[i]);
    }
    while (stack && stack->type != -1) {
        queue = push_symbol_in_queue(queue, stack->value.symbol);
        stack = pop(stack);
    }
    queue = push_number_in_queue(queue, 0);
    queue->type = -1;
    destroy(stack);
    return queue;
}

char *input_formula() {
    int val = 1;
    char *string = NULL;
    int open_bracket = 0;
    string = input_string();
    char *cur = string;
    char *prev = string;
    trig_check(string);
    if (strlen(string) == 0) val = 0;
    for (int n = 0; val && *cur != '\0'; n++, cur++) {
        if (*cur == ' ') continue;
        if (!strchr("~+-*/sctTLxq.()1234567890 \t", *cur)) val = 0;
        if (*cur == '(') open_bracket++;
        if (*cur == ')') {
            open_bracket--;
            if (*prev == '(') val = 0;
        }
        if (open_bracket < 0) val = 0;
        if (n == 0 && *cur == '-')
            *cur = '~';
        else if (*cur == '-' && *prev == '(')
            *cur = '~';
        if ((cur != prev && strchr("+-*/", *cur) && strchr("~+-*/", *prev))) val = 0;
        prev = cur;
    }
    if (open_bracket) {
        val = 0;
    }
    if (!val) {
        free(string);
        string = NULL;
    }
    return string;
}

void trig_check(char *string) {
    char *temp = NULL;

    while ((temp = strstr(string, "sin")), temp) *(temp + 1) = *(temp + 2) = ' ';
    while ((temp = strstr(string, "cos")), temp) *(temp + 1) = *(temp + 2) = ' ';
    while ((temp = strstr(string, "tan")), temp) *(temp + 1) = *(temp + 2) = ' ';
    while ((temp = strstr(string, "ctg")), temp) {
        *temp = 'T';
        *(temp + 1) = *(temp + 2) = ' ';
    }

    while ((temp = strstr(string, "sqrt")), temp) {
        *temp = 'q';
        *(temp + 1) = *(temp + 2) = *(temp + 3) = ' ';
    }

    while ((temp = strstr(string, "ln")), temp) {
        *temp = 'L';
        *(temp + 1) = ' ';
    }
}
