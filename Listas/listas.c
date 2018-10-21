#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

dllist * dllcreate()
{
    dllist *l;

    l= (dllist*)malloc(sizeof(dllist));
    if (l!=NULL)
    {
        l->first=NULL;
        return l;
    }
    return NULL;

}

int dllinsertFirst (dllist *l, void *data)
{

    dlnode *newnode;
    if (l !=NULL)
    {
        newnode=(dlnode*)malloc(sizeof(dlnode));
        if (newnode!=NULL)
        {
            newnode->data= data;
            newnode->next= l->first;
            newnode->prev= NULL;
            l->first= newnode;
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

int dllinsertLast(dllist *l, void *data)
{
    dlnode *elem, *ult;

    if (l!= NULL)
    {
        elem = (dlnode*)malloc (sizeof (dlnode));
        if (elem != NULL)
        {

            if (l->first != NULL)
            {
                ult = l->first;
                while (ult->next != NULL)
                {
                    ult = ult->next;
                }
                elem->data = data;
                elem->next = NULL;
                ult->next = elem;
                elem->prev=ult;
            }

        }
    }
}

int dllremovespec (dllist *l, void *key,int (*cmp)(void*,void*))
{

    int stat;
    dlnode *cur;

    if (l!=NULL)
    {
        if(l->first!=NULL)
        {
            cur=l->first;
            stat=cmp(key,cur->data);
            while (stat!=TRUE && cur->next!=NULL)
            {
                cur=cur->next;
                stat=cmp(key,cur->data);
            }

            if (stat==TRUE)
            {
                if (cur->prev!=NULL)
                {
                    cur->prev->next=cur->next;

                }
                else
                {
                    l->first=cur->next;

                }

                free (cur);
                return TRUE;
            }
            return FALSE;

        }
        return FALSE;
    }
}

int dllquery (dllist *l,void *key,int (*cmp) (void*,void*))
{
    dlnode *cur;
    int stat;
    if (l!=NULL)
    {
        if (l->first !=NULL)
        {

            cur = l->first;
            stat=cmp(key,cur->data);
            while (stat!=TRUE && cur->next!=NULL)
            {
                printf("oi");
                cur=cur->next;
                stat=cmp(key,cur->data);
            }

            if (stat==TRUE )
            {

                return TRUE;

            }
            return FALSE;
        }
        return FALSE;
    }
    return FALSE;
}

int comp(void *a, void *b)
{
    int *key1;
    int *key2;

    key1= (int*)a;
    key2= (int*)b;

    if (key1 == key2 )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


dllist destroy( dllist *l)
{
    if (l!=NULL)
    {
        if(l->first==NULL)
        {
            free(l);
            printf(" A lista foi destruida...\n\n");
        }
        else
        {
            printf("ERRO ! A lista nao esta vazia...\n\n");
        }
    }
}

