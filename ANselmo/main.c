#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

 int main()
 {
    int num,max,val,val2,val3,flag=1;



    printf ("QUAL MAX DE ELEMENTOS DO COFO ?\n");
    scanf ("%i",&max);
    cofo* c= cfcreate(max);

    while (flag!=0){
    printf ("INSERIR [1]\nBUSCAR[2]\nREMOVER[3]\nDESTRUIR[4]\nSAIR[5]");
    scanf("%i",&num);
    switch(num){
        case 1:

        printf("QUAL VALOR VOCE QUER INSERIR?");
        scanf ("%i",&val);
        cfinsert(c,val);

        break;

         case 2:

        printf("QUAL VALOR VOCE QUER BUSCAR?");
        scanf ("%i",&val2);
        cfquery(c,val2);

        break;

        case 3:

        printf("QUAL VALOR VOCE QUER REMOVER");
        scanf ("%i",&val3);
        cfremove(c,val3);

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
