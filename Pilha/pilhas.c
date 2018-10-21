#include <stdio.h>
#include <stdlib.h>

#include "pilhas.h"

int *stkcreate(int n)
{
    stack *s;
    if (n>0)
    {
        s= (stack*)malloc(sizeof(stack));
        if (s!=NULL)
        {
            s->elm=(void**)malloc(sizeof(void*)*n);
            if (s->elm!=NULL)
            {
                s->max=n;
                s->top=-1;
                return s;
            }
        }
        free(s);

    }
    return NULL;
}

int stkpush (stack *s, char *word)
{
    int meio;
    void *elm;
    meio = floor(s->max/2);
    if (s!=NULL)
    {
        if (s->top<s->max-1)
        {
            s->top++;
            if (s->top==meio)
            {
                s->elm[s->top]='o';
            }
            else if (s->top<meio)
            {
                s->elm[s->top]='A';


            }
            else if (s->top>meio)
            {
                s->elm[s->top]='B';


            }

        }
    }
    return FALSE;
}
int ALGORITIMO (stack *s)
{
    int i,b=0,a=0;
    for (i=0; i<s->max; i++)
    {
        if (s->elm[i]=='B')
        {
            b++;
        }
        else if (s->elm[i]=='A')
        {
            a++;
        }

    }
    if (a==b)
    {
        return 0;
    }
    else if (a<b)
    {
        return -1;

    }
    else if (a>b)
    {
        return 1;
    }
}

void *stkpop (stack *s)
{
    void *top;
    if (s!=NULL)
    {
        if (s->top<s->max-1)
        {
            top=s->elm[s->top];
            s->top--;

        }
    }
}

void *stktop (stack *s )
{
    void *top;
    if (s!=NULL)
    {
        if (s->top >=0)
        {
            top = s->elm[s->top];
            return top;
        }
    }
    return NULL;
}
