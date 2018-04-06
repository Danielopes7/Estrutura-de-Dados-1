#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cofo.h"


int main()
 {
    int num,num2,num3,max,val,val2,val3,flag=1,esc2;
    int *elm,  stat ;
    void *aux;
    Aluno *a, *pa;
    char buffer[50];



    printf ("QUAL MAX DE ALUNOS?\n");
    scanf ("%i",&max);
    cofo* c= cfcreate(max);

    while (flag!=0){
    printf ("INSERIR [1]\nBUSCAR[2]\nREMOVER[3]\nDESTRUIR[4]\nSAIR[5]");
    scanf("%i",&num);
    switch(num){

    //////////////////////////////////////////////////////////////////////// INSERIR
        case 1:
       a = (Aluno*)malloc(sizeof(Aluno));
       if(a!=NULL){
        printf("INSIRA OS DADOS DO ALUNO: ");
        scanf("%s %d %d", &(a->nome), &(a->cpf), &(a->idade));
        cfinsertLast(c, (void*)a);
       }
        break;

    ///////////////////////////////////////////////////////////////////////// BUSCAR
         case 2:

        printf("1 - PESQUISAR NOME\n2 - PESQUISAR CPF\n3 - PESQUISAR IDADE\n");
        scanf ("%i",&num2);

        switch (num2){
        case 1:
               printf("INSIRA NOME: ");
                    scanf("%s", &buffer);
                    elm=cfquery(c, (void*)buffer, cmpNome);

                    if (elm!=NULL){
                        pa = (Aluno*)elm;
                        printAluno(pa);

                    }
                      else
                    {
                        printf("\nNAO ENCONTRADO\n");
                    }

        break;

        case 2:
            printf("INSIRA CPF: ");
            scanf("%d", &aux);
            elm=cfquery(c, (void*)&aux, cmpCpf);

                    if (elm!=NULL){
                        pa = (Aluno*)elm;
                        printAluno(pa);

                    }
                    else
                    {
                        printf("\nNAO ENCONTRADO\n");
                    }
        break;



        case 3:

            printf("INSIRA IDADE: ");
            scanf("%d", &aux);
             elm=cfquery(c, (void*)&aux, cmpIdade);

                    if (elm!=NULL){
                        pa = (Aluno*)elm;
                        printAluno(pa);

                    }
                    else
                    {
                        printf("\nNAO ENCONTRADO\n");
                    }
        break;


        }
        break;
    ////////////////////////////////////////////////////////////////// REMOVER
        case 3:

        printf("1 - PESQUISAR NOME\n2 - PESQUISAR CPF\n3 - PESQUISAR IDADE\n");
        scanf("%d", &esc2);

        if(esc2==1){
                    printf("INSIRA NOME: ");
                    scanf("%s", &buffer);
                    elm = cfremove(c, (void*)buffer, cmpNome);
                    if(elm!=NULL){
                        pa = (Aluno*)elm;
                        printAluno(pa);
                        free(pa);
                        printf("ELEMENTO REMOVIDO\n\n");
                    }
                    else{
                        printf("ERRO - ELEMENTO NÃO REMOVIDO\n\n");
                    }
                }
                else if(esc2==2){
                    printf("INSIRA CPF: ");
                    scanf("%d", &aux);
                    elm = cfremove(c, (void*)&aux, cmpCpf);
                    if(elm!=NULL){
                        pa = (Aluno*)elm;
                        printAluno(pa);
                        free(pa);
                        printf("ELEMENTO REMOVIDO\n\n");
                    }
                    else{
                        printf("ERRO - ELEMENTO NÃO REMOVIDO\n\n");
                    }
                }
                else if(esc2==3){
                    printf("INSIRA IDADE: ");
                    scanf("%d", &aux);
                    elm = cfremove(c, (void*)&aux, cmpIdade);
                    if(elm!=NULL){
                        pa = (Aluno*)elm;
                        printAluno(pa);
                        free(pa);
                        printf("ELEMENTO REMOVIDO\n\n");
                    }
                    else{
                        printf("ERRO - ELEMENTO NÃO REMOVIDO\n\n");
                    }
                }

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

