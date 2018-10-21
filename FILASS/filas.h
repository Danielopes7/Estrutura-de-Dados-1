#ifndef FILAS_H
#define FILAS_H
#define TRUE 1
#define FALSE 0
typedef struct _cqueue_{
    int max;
    void **elm;
    int nelm;
    int beg;
    int end;

}cqueue;

cqueue *cqcreate (int );
int cqenqueue (cqueue *, void * );
int *cqdequeue (cqueue *);
 int IncreCircular(int i, int max);
int decrCircular(int i, int max);
int cqdestroy(cqueue *);
int cqPune(cqueue *, int);
int cqPromove(cqueue *cq, int n);

#endif
