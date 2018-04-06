#ifndef COFO_H
#define COFO_H
#define TRUE 1
#define FALSE 0


typedef struct _cofo_{
    void **elmo;
    int max;
    int nelmo;

}cofo;

 cofo *cfcreate (int max);
    int cfdestroy (cofo *);
    int cfinsert(cofo* c, void* elm);
    void* cfremove(cofo* c, void* key, int(*cmp)(void*, void*));
    void* cfquery(cofo* c, void* key, int(*cmp)(void*, void*));
    int cmpInt(void* a, void* b);



    cofo *cfcreate (int max){
    cofo *c;

    if(max>0){
        c = (cofo*)malloc(sizeof(cofo));
        c->elmo = (void**) malloc(sizeof(void*)*max);
        c-> max = max;
        c->nelmo = 0;
        return c;
        }
    return NULL;


}
int cfdestroy(cofo* c){
   if(c != NULL){
        if(c->nelmo == 0){
                if(c->elmo != NULL){
                    free(c->elmo);
                    free (c);
        }

        return 1;
     }
    }
    return 0;

}
int cfinsertLast(cofo* c, void *elmo){
    if(c!=NULL){
        if(c->elmo!=NULL && c->nelmo < c->max){

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

void *cfquery (cofo *c,void *key, int(*cmp)(void*,void*)){
    int stat=FALSE, i=0;
    void *elm;

    if (c!=NULL && c->elmo!=NULL){
        if(c->nelmo>0){

            stat=cmp(key, c->elmo[i]);

            while(i<c->nelmo && stat!=TRUE){

                i++;
                stat=cmp(key, c->elmo[i]);


            }
            if(stat==TRUE){

                elm = c->elmo[i];
                return printf("ELEMENTO ACHADO");
            }
        }
    }
    return NULL;
}






void * cfremove (cofo*c, void* key, int(*cmp)(void*, void*)){
    int stat=FALSE, i=0;
    void *elm;

     if(c!=NULL && c->elmo!=NULL){
        if (c->nelmo>0){
            stat=cmp(key, c->elmo[i]);
            while(i<c->nelmo && stat!=TRUE){
                i++;
                stat=cmp(key, c->elmo[i]);
            }
        }
        if(stat==TRUE){
                elm = c->elmo[i];
                for( ;i<c->nelmo-1; i++){
                    c->elmo[i] = c->elmo[i+1];
                }
                c->nelmo--;
                return elm;
            }
        }

    return NULL;
}


int cmpInt(void* a, void* b){
    int *pa;
    int *pb;

    pa = (int*) a;
    pb = (int*) b;
    if(*pb == *pa){

        return TRUE;
    }
    else{
        return FALSE;
    }
}
#endif

