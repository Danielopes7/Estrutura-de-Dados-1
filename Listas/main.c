#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main()
{
    int flag=0,flag2=0,num,esc=0,*elm,aux,resu;

    dllist *l1;
    while (esc==0)
    {
        printf("[1]CRIAR LISTA\n[2]INSERIR\n[3]REMOVER\n[4]BUSCAR\n[5]DESTRUIR\n[6]SAIR\n");
        scanf("%i",&num);
        switch (num)
        {
        case 1:
            if (flag==0)
            {
                l1=dllcreate();
                printf("--LISTA CRIADA--\n");
                flag++;

            }
            else
            {
                printf("--LISTA JÁ CRIADA--\n");
            }

            break;

        case 2:

            if (flag2==0)
            {
                printf("INSERIR O PRIMEIRO ELEMENTO:\n");
                scanf("%i",&elm);
                resu=dllinsertFirst (l1, elm);
                if (resu=TRUE)
                {
                    flag2++;
                    printf("\nELEMENTO INSERIDO\n");

                }
            }

            else
            {
                printf("INSERIR O ELEMENTO:");
                scanf("%i",&elm);
                resu=dllinsertFirst (l1, elm);
                if (resu=TRUE)
                {

                    printf("\nELEMENTO INSERIDO\n");
                }
            }




            break;

        case 3:
            printf ("QUAL ELEMENTO VOCE DESEJA REMOVER");
            scanf("%i",&elm);
            resu=dllremovespec (l1, elm,comp);
            if (resu==TRUE)
            {
                printf("FOI REMOVIDO");
            }
            else
            {
                printf("ERRO EM REMOVER");
            }
            break;

        case 4:
            printf ("QUAL ELEMENTO VOCE DESEJA BUSCAR");
            scanf("%i",&elm);
            resu=dllquery (l1, elm, comp);
            if (resu==TRUE)
            {
                printf("ELEMENTO ACHADO");
            }
            else
            {
                printf("ELEMENTO NAO ENCONTRADO");
            }
            break;

        case 5:
            destroy( l1);

            break;

        case 6:
            esc=1;
            break;
        }


    }

}

