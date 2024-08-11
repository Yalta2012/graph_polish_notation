#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_math.h"
#include "stack.h"

int main() {
    struct node *nodes = init();
    // nodes = push_symbol(nodes, 's');
    // nodes = push_number(nodes, PI/2);
    // nodes = push_number(nodes, 5);

    // nodes = push_symbol(nodes, '+');
    // nodes = push_symbol(nodes, '*');
    // nodes = push_number(nodes, 4);
    // nodes = push_symbol(nodes, '-');
    // nodes = push_number(nodes, 2);
    // nodes = push_number(nodes, 5);
    // nodes = push_number(nodes, 7);

    nodes = push_symbol(nodes, 't');
    nodes = push_symbol(nodes, '-');
    nodes = push_symbol(nodes, 'L');
    nodes = push_symbol(nodes, 'x');
    nodes = push_symbol(nodes, 'L');
    nodes = push_number(nodes, 2);

    output_function(nodes);
    printf("%Lf", polish_calculation(nodes, 1));

    destroy(nodes);
    return 0;
}

char *input_string() {
    int result_len = 32;
    int len = 0;
    char *result_buffer;
    char *result = malloc(result_len * sizeof(char));
    char c;
    while (scanf("%c", &c), c != '\n') {
        if (len == result_len) {
            result_len *= 2;
            result_buffer = result;
            result = realloc(result, result_len * sizeof(char));
            if (!result) {
                result = result_buffer;
                len--;
            }
        }
        result[len] = c;
        len++;
    }
    result[len] = 0;
    result = realloc(result, (len + 1) * sizeof(char));
    return result;
}

void print_graph(char **grapth, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%c", grapth[i][j]);
        }
        if (i < h - 1) {
            printf("\n");
        }
    }
}

char **create_matrix(int h, int w) {
    int flag = 1;
    char **result = malloc(sizeof(char *) * h);
    if (!result) {
        flag = 0;
    }
    if (flag) {
        for (int i = 0; i < h && flag; i++) {
            result[i] = malloc(sizeof(char) * w);
            if (!result[i]) {
                flag = 0;
                break;
            }
            for (int j = 0; j < w; j++) {
                result[i][j] = 0;
            }
        }
    }
    if (!flag) {
        result = 0;
    }
    return result;
}

void free_matrix(char **matrix, int h) {
    if (matrix) {
        for (int i = 0; i < h; i++) {
            if (matrix[i]) {
                free(matrix[i]);
            }
        }

        free(matrix);
    }
}

void write_grapth(int ** matrix, struct node * line){
    for (int i = 0; i<X_SIZE; i++){
        
    }
}
