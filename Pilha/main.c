#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"
int main(void)
{
    char word[50];
    int tam,i,a=0,b=0,re;

    printf ("QUAL A PALAVRA E QUAL O TAMANHO DELA ?");
    scanf("%s",word);
    scanf("%d",&tam);
    stack *s=stkcreate(tam);


    for (i=0; i<s->max; i++)
    {
        stkpush (s,word);
    }
    re=ALGORITIMO (s);
    printf ("%i",re);



}
