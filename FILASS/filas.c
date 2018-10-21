#include <stdio.h>
#include <stdlib.h>
#include "filas.h"
cqueue *cqcreate (int n)
{
    cqueue *cq;

    if (n>0)
    {
        cq=(cqueue*)malloc(sizeof(cqueue));
    }
    if (cq!=NULL)
    {
        cq->elm=(void**)malloc(sizeof(void*)*n);
        if (cq->elm!=NULL)
        {
            cq->max=n;
            cq->beg=0;
            cq->end=-1;
            cq->nelm=0;
            return cq;
        }
        free (cq);
    }
    return NULL;
}

int cqenqueue (cqueue *cq, void * elm)
{
    if (cq!=NULL)
    {
        if (cq->nelm <cq->max)
        {
            cq->end= IncreCircular(cq->end, cq->max);
            cq->elm[cq->end]=elm;
            cq->nelm++;
            return TRUE;

        }
    }
    return FALSE;
}

int *cqdequeue (cqueue *cq)
{
    void *elm;
    if (cq!=NULL)
    {
        if (cq->nelm >0)
        {
            elm=cq->elm[cq->end];
            cq->beg= IncreCircular(cq->beg, cq->max);

            cq->nelm--;
            return elm;

        }
    }
    return NULL;
}

int IncreCircular(int i, int max)
{
    if (i<max-1)
    {
        i++;
    }
    else
    {
        i=0;
    }
    return i;
}

int decrCircular(int i, int max)
{
    if (i>0)
    {
        i--;
    }
    else
    {
        i=max-1;
    }
    return i;
}

int cqdestroy(cqueue *cq)
{

    if (cq!=NULL)
    {
        if (cq->nelm==0)
        {
            free (cq->nelm);
            free (cq);

            return TRUE;
        }
    }
    return FALSE;

}
int cqPune(cqueue *cq, int n){
int i,aux;

    if (cq!=NULL)
    {
        if (cq->nelm>0)
        {
            for(i=0;i<n; i++){
                    aux=cq->elm[i];
                    cq->elm[i] = cq->elm[i+1];
                    cq->elm[i+1]=aux;
                }
        }
    }
}

int cqPromove(cqueue *cq, int n){
int i,aux;

    if (cq!=NULL)
    {
        if (cq->nelm>0)
        {
            for(i=0;i<n; i++){
                    aux=cq->elm[cq->end];
                    cq->elm[cq->end] = cq->elm[cq->end-1];
                    cq->elm[cq->end-1]=aux;
                }
        }
    }
}
