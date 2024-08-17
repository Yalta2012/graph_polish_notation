#include "stack_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

long double polish_calculation(struct node* line, long double x) {
    int flag = 1;

    if (line == 0) return 0;
    double res = x;
    struct node* stack = init();
    if (!stack) flag = 0;
    if (flag) {
        do {
            switch (line->type) {
                case 0:
                    if (line->value.symbol == 'x') {
                        stack = push_number(stack, x);
                    } else if (strchr("~sctTYqL+-*/", line->value.symbol)) {
                        stack = use_operator(stack, line->value.symbol, &flag);
                    } else if (line->value.symbol == ')') {
                    } else {
                        flag = 0;
                    }
                    break;
                case 1:
                    stack = push_number(stack, line->value.number);
                    break;
                case -1:
                    if (stack->type != -1) {
                        flag = 0;
                    }
                    break;
                default:
                    flag = 0;
                    break;
            }
            line = line->next;
        } while (line->type >= 0 && flag);
        if (flag && (stack->type == -1 || stack->next->type != -1)) {
            flag = 0;
        }
    }
    if (flag)
        res = stack->value.number;
    else
        res = NAN;
    destroy(stack);
    return res;
}

struct node* use_unary_operatop(struct node* stack, char operator, int * flag) {
    switch (operator) {
        case '~':
            stack->value.number = -(stack->value.number);
            break;
        case 's':
            stack->value.number = sinl(stack->value.number);
            break;
        case 'c':
            stack->value.number = cosl(stack->value.number);
            break;
        case 't':
            stack->value.number = tanl(stack->value.number);
            break;
        case 'T':
            stack->value.number = 1.0 / tanl(stack->value.number);
            break;
        case 'q':
            stack->value.number = sqrtl(stack->value.number);
            break;
        case 'L':
            stack->value.number = logl(stack->value.number);
            break;
        default:
            *flag = 0;
            break;
    }
    if (isnan(stack->value.number) || isinf(stack->value.number)) {
        *flag = 0;
    }
    return stack;
}

struct node* use_binary_operatop(struct node* stack, char operator, int * flag) {
    switch (operator) {
        case '+':
            stack->next->value.number = stack->value.number + stack->next->value.number;
            break;
        case '-':
            stack->next->value.number = stack->next->value.number - stack->value.number;
            break;
        case '*':
            stack->next->value.number = stack->value.number * stack->next->value.number;
            break;
        case '/':
            if (stack->value.number == 0) {
                *flag = 0;
            } else {
                stack->next->value.number = stack->next->value.number / stack->value.number;
            }
            break;
        default:
            *flag = 0;
            break;
    }
    if (*flag) {
        stack = pop(stack);
    }
    return stack;
}

struct node* use_operator(struct node* stack, char operator, int * flag) {
    if (flag == 0) return 0;
    if (stack == 0) {
        *flag = 0;
        return stack;
    }

    if (strchr("~sctTqL", operator)) {
        if (stack->type != 1) {
            *flag = 0;
        } else {
            stack = use_unary_operatop(stack, operator, flag);
        }
    } else if (strchr("+-*/", operator)) {
        if (stack->type != 1 || stack->next->type != 1) {
            *flag = 0;
        } else {
            stack = use_binary_operatop(stack, operator, flag);
        }
    }
    return stack;
}