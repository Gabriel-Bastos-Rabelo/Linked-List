#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0



DLList *dllcreate(){
    DLList *l = (DLList *)malloc(sizeof(DLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}


SLList *sllcreate(){
    SLList *l = (SLList *)malloc(sizeof(SLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}



CDLList *cdllcreate(){
    CDLList *l = (CDLList *)malloc(sizeof(CDLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}

CSLList *csllcreate(){
    CSLList *l = (CSLList *)malloc(sizeof(CSLList));

    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}


//questão 1 letra a

//para lista encadeada simples
int sllInsertAsFirst(SLList *l, void *data){
    if(l != NULL){
        SLNode *newnode = (SLNode*)malloc(sizeof(SLNode));

        if(newnode != NULL){
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }

    return FALSE;
}

//para lista duplamente encadeada
int dllInsertAsFirst(DLList *l, void *data){
    if(l != NULL){
        DLNode *newnode = (DLNode*)malloc(sizeof(DLNode));
        DLNode *next;

        if(newnode != NULL){
            newnode->data = data;
            newnode->next = l->first;
            newnode->prev = NULL;
            next = l->first;
            if(next != NULL){
                next->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }

    return FALSE;
}

//para lista circular simplesmente encadeada

int csllInsertAsFirst(CSLList *l, void *data){
    //tenho que fazer o next do novonode apontar para o primeiro, o l->first 
    //apontar para o novonode e no prev do current last apontar para o novonode
    //caso especial, se não tiver nenhum elemento
    //caso especial, se tiver somente um elemento
    if(l != NULL){
        CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
        CSLNode *current;

        if(newnode != NULL){
            newnode->data = data;
            
           

            current = l->first;

            if(current == NULL){
                newnode->next = newnode;
            }

            else{

                while(current->next != l->first){
                    current = current->next;
                }

                newnode->next = l->first;
                current->next = newnode;
            }

            l->first = newnode;

            return TRUE;

        }

    }

    return FALSE;
}


//para lista circular duplamente encadeada
int cdllInsertAsFirst(CDLList *l, void *data){

    if(l != NULL){
        CDLNode* newnode = (CDLNode*)malloc(sizeof(CDLNode));
        CDLNode *current;

        if(newnode != NULL){
            newnode->data = data;

            current = l->first;

            if(current == NULL){
                newnode->next = newnode;
                newnode->prev = newnode;
            }
            else{
                while(current->next != l->first){
                    current = current->next;
                }

                current->next = newnode;
                l->first->prev = newnode;
                newnode->next = l->first;
                newnode->prev = current;
            }

            l->first = newnode;

            return TRUE;

        }
    }

    return FALSE;
}

//questão 1 letra b

//para lista simplesmente encadeada
int sllInsertAsLast(SLList *l, void *data){
    if(l != NULL){
        SLNode *current;
        current = l->first;
        
        SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));


        if(newnode != NULL){
            newnode -> data = data;
            newnode -> next = NULL;
            if(current == NULL){
                l->first = newnode;
            }
            else{
                while(current->next != NULL){
                    current = current->next;
                }

                current->next = newnode;
            }

            return TRUE;
        }
    }

    return FALSE;
}

//para lista duplamente encadeada

int dllInsertAsLast(DLList *l, void *data){
    if(l != NULL){
        DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));

        if(newnode != NULL){
            newnode -> data = data;
            newnode -> next = NULL;

            DLNode *current = l->first;

            if(current == NULL){
                l->first = newnode;
                newnode -> prev = NULL;
            }
            else{
                while(current -> next != NULL){
                    current = current -> next;
                }

                current -> next = newnode;
                newnode -> prev = current;
            }

            return TRUE;
        }
    }

    return FALSE;
}


//para lista circular simplesmente encadeada

int csllInsertAsLast(CSLList *l, void *data){
    if(l != NULL){
        CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
        if(newnode != NULL){
            newnode->data = data;
            CSLNode *current = l->first;

            if(current == NULL){
                l->first = newnode;
                newnode -> next = newnode;
            }

            else{
                while(current->next != l->first){
                    current = current -> next;
                }

                current -> next = newnode;
                newnode -> next = l->first;
            }

            return TRUE;
        }
    }

    return FALSE;
}

//para lista duplamente encadeada

int cdllInsertAsLast(CDLList *l, void *data){
    if(l != NULL){
        CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
        if(newnode != NULL){
            newnode -> data = data;
            CDLNode *current = l->first;

            if(current == NULL){
                newnode -> next = newnode;
                newnode -> prev = newnode;
            }

            else{
                while(current -> next != l->first){
                    current = current -> next;
                }

                l->first->prev = newnode;
                current->next = newnode;
                newnode -> prev = current;
                newnode -> next = l->first;

            }

            return TRUE;
        }

    }

    return FALSE;
}

//questão 1 letra c

//para lista simplemente encadeada

int sllInsertKPosition(SLList *l, void *data, int k){
    if(l != NULL){
        SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
        if(newnode != NULL){
            newnode -> data = data;

            SLNode *current = l->first;
            SLNode *last = NULL;

            int i = 0;
            while(current != NULL && i < k){
                last = current;
                current = current -> next;
                i += 0;
            }

            if(i == k){
                newnode -> next = current;

                if(last == NULL){
                    l -> first = newnode;
                }
                else{
                    last -> next = newnode;
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

//para lista duplamente encadeada

int dllInsertKPosition(DLList *l, void *data, int k){
    if(l != NULL){
        DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
        if(newnode != NULL){
            newnode -> data = data;

            DLNode *current = l->first;

            int i = 0;
            while(current != NULL && i < k){
                current = current -> next;
                i += 1;

            }

            if(i == k){
                newnode -> next = current;
                if(current == NULL){
                    l->first = newnode;
                    newnode -> prev = NULL;
                }
                else{
                    current->prev->next = newnode;
                    newnode -> prev = current->prev;
                    current -> prev = newnode;
                }

                return TRUE;
            }


        }
    }

    return FALSE;
}

//para lista circular simplesmente encadeada

int csllInsertKPosition(CSLList *l, void *data, int k){
    if(l != NULL){
        CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));

        if(newnode != NULL){
            CSLNode *current =  l->first;
            CSLNode *last = NULL;

            if(current != NULL){

                int i = 0;
                while(current -> next != l->first && i < k){
                    last = current;
                    current = current -> next;
                    i += 1;
                }

                if(i == k){
                    newnode -> data = data;
                    newnode -> next = current;
                    if(last == NULL){
                        l->first = newnode;
                
                    }
                    else{
                        last->next = newnode;
                        
                    }

                    return TRUE;
                }
                
            }
        }
    }

    return FALSE;
}


//para lista circular duplamente encadeada

int cdllInsertKPosition(CDLList *l, void *data, int k){
    if(l != NULL){
        CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));

        if(newnode != NULL){
            CDLNode *current = l->first;

            if(current != NULL){
                
                int i = 0;

                while(current -> next != l->first && i < k){
                    current = current -> next;
                    i += 1;
                }

                if(i == k){
                    newnode -> data = data;
                    newnode -> next = current;
                    current -> prev -> next = newnode;
                    newnode -> prev = current -> prev;
                    current -> prev = newnode;
                    if(current == l->first){
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}



int sllInsertAfterKey(SLList *l, void *key, void *data, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode *cur = l -> first;
            int stat = cmp(cur, key);
            while(stat != TRUE && cur -> next != NULL){
                cur = cur->next;
                stat = cmp(cur, key);
            }

            if(stat){
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> next = cur -> next;
                    cur -> next = newnode;
                    return TRUE;
                }
                
            }
        }
    }

    return FALSE;
}


int dllInsertAfterKey(DLList *l, void *key, void *data, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *cur = l->first;
            int stat = cmp(cur, key);
            while(stat != TRUE && cur-> next != NULL){
                cur = cur->next;
                stat = cmp(cur, key);
            }

            if(stat){
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> prev = cur;
                    newnode -> next = cur -> next;
                    if(cur -> next != NULL){
                        cur -> next -> prev = newnode;
                    }
        
                    cur -> next = newnode;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int csllInsertAfterKey(CSLList *l, void *key, void *data, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            CSLNode *cur = l -> first;

            int stat = cmp(cur, key);
            while(stat != TRUE && cur -> next != l->first){
                cur = cur -> next;
                stat = cmp(cur, key);
            }

            if(stat){
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if (newnode != NULL){
                    newnode -> data = data;
                    newnode -> next = cur->next;
                    cur -> next = newnode;

                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int cdllInsertAfterKey(CDLList*l, void *key, void *data, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            CDLNode *cur = l -> first;
            int stat = cmp(cur->data, key);

            while(stat != TRUE && cur -> next != l->first){
                cur = cur -> next;
                stat = cmp(cur->data, key);
            }

            if(stat){
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> next = cur->next;
                    newnode -> prev = cur;
                    cur->next = newnode;
                    cur->next->prev = newnode;

                    return TRUE;
                }
            }
        }
    }
    return FALSE;    
}



int sllInsertBeforeKey(SLList *l, void *key, void *data, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            int stat = cmp(cur->data, key);
            while(stat != TRUE && cur -> next != NULL){
                prev = cur;
                cur = cur -> next;
                stat = cmp(cur->data, key);
            }

            if(stat){
                SLNode *newnode = (SLNode *)malloc(sizeof(DLNode));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> next = cur;
                    if(prev != NULL){
                        prev -> next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }

                    return TRUE;
                }
            }
            
        }
    }

    return FALSE;
}


int dllInsertBeforeKey(DLList *l, void *key, void *data, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while(stat != TRUE && cur -> next != NULL){
                cur = cur -> next;
                stat = cmp(cur -> data, key);
            }

            if(stat){
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> next = cur;
                    newnode -> prev = cur -> prev;
                    if(cur -> prev != NULL){
                        cur -> prev -> next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }

                    cur -> prev = newnode;
                    return TRUE;

                }
            }
        }
    }
    return FALSE;
}

int csllInsertBeforeKey(CSLList *l, void *key, void *data, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            CSLNode *cur = l -> first;
            CSLNode *prev = NULL;
            int stat = cmp(cur->data, key);
            while(stat != TRUE && cur -> next != l -> first){
                prev = cur;
                cur = cur -> next;
                stat = cmp(cur -> data, key);
            }

            if(stat){
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> next = cur;
                    if(prev != NULL){
                        prev -> next = newnode;
                    }
                    else{
                        l -> first = newnode;
                    }

                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int cdllInsertBeforeKey(CDLList*l, void *key, void *data, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            CDLNode *cur = l -> first;
            int stat = cmp(cur->data, key);
            while(stat != TRUE && cur -> next != l -> first){
                cur = cur -> next;
                stat = cmp(cur-> data, key);
            }

            if(stat){
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> next = cur;
                    newnode -> prev = cur->prev;
                    cur->prev->next = newnode;
                    cur -> prev = newnode;

                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int sllInsertOrdenedList(SLList *l, void *key, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode *cur = l -> first;
            SLNode *prev = NULL;
            //A função passada verifica se key é menor que cur->data
            int stat = cmp(cur->data, key);
            //retorna true se key for menor que cur -> data
            while(stat != TRUE && cur -> next != NULL){
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if(stat){
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if(newnode != NULL){
                    newnode -> data = key;
                    newnode -> next = cur;
                    if(prev != NULL){
                        prev->next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }

                    return TRUE;

                }
            }
            else{
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if(newnode != NULL){
                    newnode -> data = key;
                    newnode -> next = NULL;
                    cur->next = newnode;
                    return TRUE;
                }
            }



        }
    }
    return FALSE;
}

int dllInsertOrdenedList(DLList *l, void *key, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *cur = l->first;

            int stat = cmp(cur -> data, key);
            while(stat != TRUE && cur->next != NULL){
                cur = cur -> next;
                stat = cmp(cur -> data, key);
            }

            if(stat){
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if(newnode != NULL){
                    newnode -> data = key;
                    newnode -> next = cur;
                    newnode -> prev = cur->prev;
                    if(cur->prev != NULL){
                        cur->prev->next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }

                    cur -> prev = newnode;
                    return TRUE;
                }
            }

            else{
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if(newnode != NULL){
                    newnode -> data = key;
                    newnode -> next = NULL;
                    newnode -> prev = cur;
                    cur->next = newnode;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int csllInsertOrdenedList(CSLList *l, void *key, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l->first != NULL){
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;
            int stat = smp(cur->data, key);
            while(stat != TRUE && cur -> next != l->first){
                prev = cur;
                cur = cur -> next;
                stat = cmp(cur->data, key);
            }

            if(stat){
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if(newnode != NULL){
                    newnode -> data = key;
                    newnode -> next = cur;
                    if(prev != NULL){
                        prev -> next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
            else{
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if(newnode != NULL){
                    newnode -> data = key;
                    newnode -> next = l->first;
                    cur->next = newnode;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int cdllInsertOrdenedList(CDLList *l, void *key, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            CDLNode *cur = l -> first;
            int stat = cmp(cur->data, key);
            while(stat != TRUE && cur -> next != l->first){
                cur = cur -> next;
                stat = cmp(cur -> data, key);
            }

            if(stat){
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if(newnode != NULL){
                    newnode -> data = key;
                    newnode -> next = cur;
                    newnode -> prev = cur->prev;
                    if(cur->prev != NULL){
                        cur->prev->next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }

                    cur->prev = newnode;

                    return TRUE;
                }
            }

            else{
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if(newnode != NULL){
                    newnode -> data = key;
                    newnode -> next = l->first;
                    newnode -> prev = cur;
                    cur->next->prev = newnode;
                    cur->next = newnode;

                    return FALSE;
                }
            }
        }
    }

    return FALSE;
}


void *sllRemoveFirst(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *first = l->first;
            void *data = first -> data;
            l->first = first->next;
            free(first);
            return data;
        }
    }

    return NULL;
}

void *dllRemoveFirst(DLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *first = l->first;
            void *data = first->data;
            l->first = first->next;
            if(first -> next != NULL){
                first -> next -> prev = NULL;
            }
            free(first);
            return data;
        }
    }

    return NULL;
}


void *csllRemoveFirst(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){
            CSLNode *first = l->first;
            void *data = first->data;
            if(first->next != first){
                l->first = first->next;
            }
            else{
                l->first = NULL;
            }

            free(first);
            return data;
        }
    }

    return NULL;
}

void *cdllRemoveFirst(CDLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            CDLNode *first = l->first;
            void *data = first->data;
            if(first -> next != first){
                l->first = first -> next;
                first -> next -> prev = first -> prev;
                first -> prev -> next = first -> next;
            }
            else{
                l->first = NULL;
            }

            free(first);
            return data;
        }
    }

    return NULL;
}

void *sllRemoveLast(SLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            while(cur -> next != NULL){
                prev = cur;
                cur = cur->next;
            }
            void *data = cur->data;
            if(prev != NULL){
                prev -> next = NULL;
            }
            else{
                l->first = NULL;
            }

            free(cur);
            return data;


        }
    }

    return NULL;
}

void *dllRemoveLast(DLList *l){
    if(l != NULL){
        if(l->first != NULL){
            DLNode *cur = l->first;
            while(cur -> next != NULL){
                cur = cur -> next;
            }
            void *data = cur->data;

            if(cur -> prev != NULL){
                cur -> prev -> next = NULL;
            }
            else{
                l->first = NULL;
            }
            free(cur);
            return data;
        }
    }

    return NULL;
}

void *cdllRemoveLast(CDLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;
            while(cur -> next != l->first){
                prev = cur;
                cur = cur -> next;
            }

            void *data = cur->data;
            if(prev != NULL){
                prev -> next = cur->next;
            }
            else{
                l->first = NULL;
            }

            free(cur);
            return data;

        }
    }

    return NULL;
}


void *cdllRemoveLast(CDLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            CDLNode *cur = l->first;
            while(cur -> next != l->first){
                cur = cur->next;
            }

            void *data = cur -> data;
            if(cur != l->first){
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            else{
                l->first = NULL;
            }

            free(cur);
            return data;


        }
    }

    return NULL;
}

