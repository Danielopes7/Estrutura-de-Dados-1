#ifndef COFO_H
#define COFO_H

typedef struct _cofo_{
    int *elmo;
    int max;
    int nelmo;

}cofo;

 cofo *cfcreate (int max);
    int cfdestroy (cofo *);
    int cfinsert (cofo*, int elmo);
    int cfquery (cofo *,int key);
    int cfremove (cofo*,int key);

    cofo *cfcreate (int max){
    cofo *c;

    if(max>0){
        c = (cofo*)malloc(sizeof(cofo));
        c->elmo = (int*) malloc(sizeof(int)*max);
        c-> max = max;
        c->nelmo = 0;
        return c;
        }
    return NULL;


}
int cfdestroy(cofo* c){
   if(c != NULL){
        if(c->nelmo <= 0){
                if(c->elmo != NULL){
                    free(c->elmo);
        }

        free (c);
        return 0;
     }
    }


}
int cfinsert(cofo* c, int elmo){
    if(c!=NULL){
        if(c->nelmo < c->max){

            c->elmo[c->nelmo] = elmo;
            c->nelmo++;

            return printf("\nELEMENTO INSERIDO\n");

        }
        else
        {
            printf("\n ------COFO LOTADO------\n");
        }

    }
    return printf("\n ------COFO LOTADO------\n");


}

int cfquery (cofo *c,int key){
    if (c!=NULL){

        int i;
        for(i=0;i<c->nelmo;i++) {

		if (c->elmo[i] == key){
            printf("POSICAO DA BUSCA : ");
            printf ("%i\n",i);
			return c->elmo[i];

		}
	}
    }
return printf("n tem");


}

int cfremove (cofo*c, int key){
    int i,elmo;

    if (c!=NULL){
        if (c->nelmo>0){
            i=0;
            while (i< c->nelmo && c->elmo[i] !=key){
            i++;
        }
        if (c->elmo[i]==key){
            elmo= c->elmo[i];
            for (i;i<c->nelmo-1;i++){
                c->elmo[i]=c->elmo[i+1];

            }
            c->nelmo--;
            return printf("\nELEMENTO REMOVIDO\n");
        }
    }
    return printf("\n ELEMENTO NAO EXISTE PARA SER REMOVIDO\n");

}

}
#endif
