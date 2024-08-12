#ifndef POLISH_INPUT_H
#define POLISH_INPUT_H

struct node *translateToPolishAnn(struct node *queue, char *inputStr);
char *input_formula(void);
void trig_check(char *string);
#endif