#ifndef PILHAS_H
#define PILHAS_H
#define TRUE 1
#define FALSE 0
typedef struct _stack_
{
    int max;
    int top;
    int **elm;
} stack;

int *stkcreate(int max);
int stkdestroy (stack *s);
void *stkpop (stack *s);
int stkpush (stack *s, char *word);
void *stktop (stack *s);
int ALGORITIMO (stack *s);

#endif
