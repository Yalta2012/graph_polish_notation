#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "stack_math.h"

int main() {
    struct node *nodes = init();
    char **graph = create_matrix(Y_SIZE, X_SIZE);
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

    // nodes = push_symbol(nodes, 't');
    // nodes = push_symbol(nodes, '-');
    // nodes = push_symbol(nodes, 'L');
    // nodes = push_symbol(nodes, 'x');
    // nodes = push_symbol(nodes, 'L');
    // nodes = push_number(nodes, 2);

    //  nodes = push_symbol(nodes, 's');
    //  nodes = push_symbol(nodes, 'c');
    //  nodes = push_symbol(nodes, '*');
    //  nodes = push_symbol(nodes, 'x');
    //  nodes = push_number(nodes, 2);

    // nodes = push_symbol(nodes,'t');
    // nodes = push_number(nodes,PI*4);
    // nodes = push_symbol(nodes,'x');

    // nodes = push_symbol(nodes,'q');
    // nodes = push_symbol(nodes,'-');
    // nodes = push_symbol(nodes,'s');
    // nodes = push_symbol(nodes,'x');
    // nodes = push_number(nodes,1);

    // nodes = push_symbol(nodes,'t');
    // nodes = push_symbol(nodes,'x');

    write_grapth(graph, nodes);
    print_graph(graph, Y_SIZE, X_SIZE);
    // output_function(nodes);
    // printf("%Lf", polish_calculation(nodes, 1));
    free_matrix(graph, Y_SIZE);
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

void write_grapth(char **matrix, struct node *line) {
    if (!matrix || !line) return;
    long double ys[X_SIZE];
    long double x_step = ((long double)RIGHT_BORDER - LEFT_BORDER) / (X_SIZE - 1);
    long double y_step = ((long double)UPPER_BORDER - LOWER_BORDER) / (Y_SIZE - 1);

    for (int i = 0; i < Y_SIZE; i++) {
        for (int j = 0; j < X_SIZE; j++) {
            matrix[i][j] = '.';
        }
    }
    for (int i = 0; i < X_SIZE; i++) {
        ys[i] = polish_calculation(line, i * x_step);
        if (!isnan(ys[i]) && ys[i] < UPPER_BORDER && ys[i] > LOWER_BORDER) {
            int y_coord = round((ys[i] - LOWER_BORDER - y_step) * (Y_SIZE / 2 + 1));
            if (y_coord >= 0 && y_coord < Y_SIZE) {
                matrix[y_coord][i] = '*';
            }
        }
    }
}
