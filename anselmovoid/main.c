#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cofo.h"


int main()
 {
    int num,max,val,val2,val3,flag=1;
    int *elm,  stat ;
    void *aux;



    printf ("QUAL MAX DE ELEMENTOS DO COFO ?\n");
    scanf ("%i",&max);
    cofo* c= cfcreate(max);

    while (flag!=0){
    printf ("INSERIR [1]\nBUSCAR[2]\nREMOVER[3]\nDESTRUIR[4]\nSAIR[5]");
    scanf("%i",&num);
    switch(num){
        case 1:
        elm = (int*)malloc(sizeof(int));
        printf("QUAL VALOR VOCE QUER INSERIR?");
        scanf ("%d",&elm);
        cfinsertLast(c, (void*)(elm));

        break;

         case 2:

        printf("QUAL VALOR VOCE QUER BUSCAR?");
        scanf ("%d",&val2);

        cfquery(c, (void*)(&val2), cmpInt);


        break;

        case 3:

        printf("QUAL VALOR VOCE QUER REMOVER");
        scanf ("%d",&val3);
        cfremove(c, (void*)(&val3), cmpInt);
        break;

         case 4:

        cfdestroy(c);

        break;

        case 5:

        flag=0;

        break;

    }

    }

 }
