#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

DLList *dllcreate()
{
    DLList *l = (DLList *)malloc(sizeof(DLList));

    if (l != NULL)
    {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}

SLList *sllcreate()
{
    SLList *l = (SLList *)malloc(sizeof(SLList));

    if (l != NULL)
    {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}

CDLList *cdllcreate()
{
    CDLList *l = (CDLList *)malloc(sizeof(CDLList));

    if (l != NULL)
    {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}

CSLList *csllcreate()
{
    CSLList *l = (CSLList *)malloc(sizeof(CSLList));

    if (l != NULL)
    {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }

    return NULL;
}

// questão 1 letra a

// para lista encadeada simples
int sllInsertAsFirst(SLList *l, void *data)
{
    if (l != NULL)
    {
        SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));

        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }

    return FALSE;
}

// para lista duplamente encadeada
int dllInsertAsFirst(DLList *l, void *data)
{
    if (l != NULL)
    {
        DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
        DLNode *next;

        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = l->first;
            newnode->prev = NULL;
            next = l->first;
            if (next != NULL)
            {
                next->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }

    return FALSE;
}

// para lista circular simplesmente encadeada

int csllInsertAsFirst(CSLList *l, void *data)
{
    // tenho que fazer o next do novonode apontar para o primeiro, o l->first
    // apontar para o novonode e no prev do current last apontar para o novonode
    // caso especial, se não tiver nenhum elemento
    // caso especial, se tiver somente um elemento
    if (l != NULL)
    {
        CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
        CSLNode *current;

        if (newnode != NULL)
        {
            newnode->data = data;

            current = l->first;

            if (current == NULL)
            {
                newnode->next = newnode;
            }

            else
            {

                while (current->next != l->first)
                {
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

// para lista circular duplamente encadeada
int cdllInsertAsFirst(CDLList *l, void *data)
{

    if (l != NULL)
    {
        CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
        CDLNode *current;

        if (newnode != NULL)
        {
            newnode->data = data;

            current = l->first;

            if (current == NULL)
            {
                newnode->next = newnode;
                newnode->prev = newnode;
            }
            else
            {
                while (current->next != l->first)
                {
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

// questão 1 letra b

// para lista simplesmente encadeada
int sllInsertAsLast(SLList *l, void *data)
{
    if (l != NULL)
    {
        SLNode *current;
        current = l->first;

        SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));

        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = NULL;
            if (current == NULL)
            {
                l->first = newnode;
            }
            else
            {
                while (current->next != NULL)
                {
                    current = current->next;
                }

                current->next = newnode;
            }

            return TRUE;
        }
    }

    return FALSE;
}

// para lista duplamente encadeada

int dllInsertAsLast(DLList *l, void *data)
{
    if (l != NULL)
    {
        DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));

        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = NULL;

            DLNode *current = l->first;

            if (current == NULL)
            {
                l->first = newnode;
                newnode->prev = NULL;
            }
            else
            {
                while (current->next != NULL)
                {
                    current = current->next;
                }

                current->next = newnode;
                newnode->prev = current;
            }

            return TRUE;
        }
    }

    return FALSE;
}

// para lista circular simplesmente encadeada

int csllInsertAsLast(CSLList *l, void *data)
{
    if (l != NULL)
    {
        CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            CSLNode *current = l->first;

            if (current == NULL)
            {
                l->first = newnode;
                newnode->next = newnode;
            }

            else
            {
                while (current->next != l->first)
                {
                    current = current->next;
                }

                current->next = newnode;
                newnode->next = l->first;
            }

            return TRUE;
        }
    }

    return FALSE;
}

// para lista duplamente encadeada

int cdllInsertAsLast(CDLList *l, void *data)
{
    if (l != NULL)
    {
        CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            CDLNode *current = l->first;

            if (current == NULL)
            {
                newnode->next = newnode;
                newnode->prev = newnode;
            }

            else
            {
                while (current->next != l->first)
                {
                    current = current->next;
                }

                l->first->prev = newnode;
                current->next = newnode;
                newnode->prev = current;
                newnode->next = l->first;
            }

            return TRUE;
        }
    }

    return FALSE;
}

// questão 1 letra c

// para lista simplemente encadeada

int sllInsertKPosition(SLList *l, void *data, int k)
{
    if (l != NULL)
    {
        SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
        {
            newnode->data = data;

            SLNode *current = l->first;
            SLNode *last = NULL;

            int i = 0;
            while (current != NULL && i < k)
            {
                last = current;
                current = current->next;
                i += 0;
            }

            if (i == k)
            {
                newnode->next = current;

                if (last == NULL)
                {
                    l->first = newnode;
                }
                else
                {
                    last->next = newnode;
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

// para lista duplamente encadeada

int dllInsertKPosition(DLList *l, void *data, int k)
{
    if (l != NULL)
    {
        DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
        if (newnode != NULL)
        {
            newnode->data = data;

            DLNode *current = l->first;

            int i = 0;
            while (current != NULL && i < k)
            {
                current = current->next;
                i += 1;
            }

            if (i == k)
            {
                newnode->next = current;
                if (current == NULL)
                {
                    l->first = newnode;
                    newnode->prev = NULL;
                }
                else
                {
                    current->prev->next = newnode;
                    newnode->prev = current->prev;
                    current->prev = newnode;
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

// para lista circular simplesmente encadeada

int csllInsertKPosition(CSLList *l, void *data, int k)
{
    if (l != NULL)
    {
        CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));

        if (newnode != NULL)
        {
            CSLNode *current = l->first;
            CSLNode *last = NULL;

            if (current != NULL)
            {

                int i = 0;
                while (current->next != l->first && i < k)
                {
                    last = current;
                    current = current->next;
                    i += 1;
                }

                if (i == k)
                {
                    newnode->data = data;
                    newnode->next = current;
                    if (last == NULL)
                    {
                        l->first = newnode;
                    }
                    else
                    {
                        last->next = newnode;
                    }

                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

// para lista circular duplamente encadeada

int cdllInsertKPosition(CDLList *l, void *data, int k)
{
    if (l != NULL)
    {
        CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));

        if (newnode != NULL)
        {
            CDLNode *current = l->first;

            if (current != NULL)
            {

                int i = 0;

                while (current->next != l->first && i < k)
                {
                    current = current->next;
                    i += 1;
                }

                if (i == k)
                {
                    newnode->data = data;
                    newnode->next = current;
                    current->prev->next = newnode;
                    newnode->prev = current->prev;
                    current->prev = newnode;
                    if (current == l->first)
                    {
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int sllInsertAfterKey(SLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *cur = l->first;
            int stat = cmp(cur, key);
            while (stat != TRUE && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(cur, key);
            }

            if (stat)
            {
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = cur->next;
                    cur->next = newnode;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int dllInsertAfterKey(DLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *cur = l->first;
            int stat = cmp(cur, key);
            while (stat != TRUE && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(cur, key);
            }

            if (stat)
            {
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->prev = cur;
                    newnode->next = cur->next;
                    if (cur->next != NULL)
                    {
                        cur->next->prev = newnode;
                    }

                    cur->next = newnode;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int csllInsertAfterKey(CSLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *cur = l->first;

            int stat = cmp(cur, key);
            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur, key);
            }

            if (stat)
            {
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = cur->next;
                    cur->next = newnode;

                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int cdllInsertAfterKey(CDLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *cur = l->first;
            int stat = cmp(cur->data, key);

            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = cur->next;
                    newnode->prev = cur;
                    cur->next = newnode;
                    cur->next->prev = newnode;

                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int sllInsertBeforeKey(SLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                SLNode *newnode = (SLNode *)malloc(sizeof(DLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = cur;
                    if (prev != NULL)
                    {
                        prev->next = newnode;
                    }
                    else
                    {
                        l->first = newnode;
                    }

                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int dllInsertBeforeKey(DLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = cur;
                    newnode->prev = cur->prev;
                    if (cur->prev != NULL)
                    {
                        cur->prev->next = newnode;
                    }
                    else
                    {
                        l->first = newnode;
                    }

                    cur->prev = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int csllInsertBeforeKey(CSLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = cur;
                    if (prev != NULL)
                    {
                        prev->next = newnode;
                    }
                    else
                    {
                        l->first = newnode;
                    }

                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int cdllInsertBeforeKey(CDLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = cur;
                    newnode->prev = cur->prev;
                    cur->prev->next = newnode;
                    cur->prev = newnode;

                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int sllInsertOrdenedList(SLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            // A função passada verifica se key é menor que cur->data
            int stat = cmp(cur->data, key);
            // retorna true se key for menor que cur -> data
            while (stat != TRUE && cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if (newnode != NULL)
                {
                    newnode->data = key;
                    newnode->next = cur;
                    if (prev != NULL)
                    {
                        prev->next = newnode;
                    }
                    else
                    {
                        l->first = newnode;
                    }

                    return TRUE;
                }
            }
            else
            {
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if (newnode != NULL)
                {
                    newnode->data = key;
                    newnode->next = NULL;
                    cur->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int dllInsertOrdenedList(DLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *cur = l->first;

            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if (newnode != NULL)
                {
                    newnode->data = key;
                    newnode->next = cur;
                    newnode->prev = cur->prev;
                    if (cur->prev != NULL)
                    {
                        cur->prev->next = newnode;
                    }
                    else
                    {
                        l->first = newnode;
                    }

                    cur->prev = newnode;
                    return TRUE;
                }
            }

            else
            {
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if (newnode != NULL)
                {
                    newnode->data = key;
                    newnode->next = NULL;
                    newnode->prev = cur;
                    cur->next = newnode;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int csllInsertOrdenedList(CSLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;
            int stat = smp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if (newnode != NULL)
                {
                    newnode->data = key;
                    newnode->next = cur;
                    if (prev != NULL)
                    {
                        prev->next = newnode;
                    }
                    else
                    {
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
            else
            {
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if (newnode != NULL)
                {
                    newnode->data = key;
                    newnode->next = l->first;
                    cur->next = newnode;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

int cdllInsertOrdenedList(CDLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if (newnode != NULL)
                {
                    newnode->data = key;
                    newnode->next = cur;
                    newnode->prev = cur->prev;
                    if (cur->prev != NULL)
                    {
                        cur->prev->next = newnode;
                    }
                    else
                    {
                        l->first = newnode;
                    }

                    cur->prev = newnode;

                    return TRUE;
                }
            }

            else
            {
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if (newnode != NULL)
                {
                    newnode->data = key;
                    newnode->next = l->first;
                    newnode->prev = cur;
                    cur->next->prev = newnode;
                    cur->next = newnode;

                    return FALSE;
                }
            }
        }
    }

    return FALSE;
}

void *sllRemoveFirst(SLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *first = l->first;
            void *data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }

    return NULL;
}

void *dllRemoveFirst(DLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *first = l->first;
            void *data = first->data;
            l->first = first->next;
            if (first->next != NULL)
            {
                first->next->prev = NULL;
            }
            free(first);
            return data;
        }
    }

    return NULL;
}

void *csllRemoveFirst(CSLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *first = l->first;
            void *data = first->data;
            // verifico se tem mais de um elemento
            if (first->next != first)
            {
                // tenho que achar o último
                CSLNode *last = l->first;
                while (last->next != l->first)
                {
                    last = last->next;
                }
                last->next = first->next;
                l->first = first->next;
            }
            else
            {
                l->first = NULL;
            }

            free(first);
            return data;
        }
    }

    return NULL;
}

void *cdllRemoveFirst(CDLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *first = l->first;
            void *data = first->data;
            // verifico se tem somente um elemento
            if (first->next != first)
            {
                l->first = first->next;
                first->next->prev = first->prev;
                first->prev->next = first->next;
            }
            else
            {
                l->first = NULL;
            }

            free(first);
            return data;
        }
    }

    return NULL;
}

void *sllRemoveLast(SLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            while (cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
            }
            void *data = cur->data;
            if (prev != NULL)
            {
                prev->next = NULL;
            }
            else
            {
                l->first = NULL;
            }

            free(cur);
            return data;
        }
    }

    return NULL;
}

void *dllRemoveLast(DLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *cur = l->first;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            void *data = cur->data;

            if (cur->prev != NULL)
            {
                cur->prev->next = NULL;
            }
            else
            {
                l->first = NULL;
            }
            free(cur);
            return data;
        }
    }

    return NULL;
}

void *cdllRemoveLast(CDLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;
            while (cur->next != l->first)
            {
                prev = cur;
                cur = cur->next;
            }

            void *data = cur->data;
            if (prev != NULL)
            {
                prev->next = cur->next;
                l->first->prev = prev;
            }
            else
            {
                l->first = NULL;
            }

            free(cur);
            return data;
        }
    }

    return NULL;
}

void *cdllRemoveLast(CDLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *cur = l->first;
            while (cur->next != l->first)
            {
                cur = cur->next;
            }

            void *data = cur->data;
            if (cur != l->first)
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            else
            {
                l->first = NULL;
            }

            free(cur);
            return data;
        }
    }

    return NULL;
}

void *sllRemoveKPosition(SLList *l, int k)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            int i = 0;
            while (i < k && cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
                i++;
            }

            if (cur != NULL)
            {
                void *data = cur->data;
                if (prev != NULL)
                {
                    prev->next = cur->next;
                }
                else
                {
                    l->first = cur->next;
                }

                free(cur);
                return data;
            }
        }
    }

    return NULL;
}

void *dllRemoveKPosition(DLList *l, int k)
{
    if (l != NULL && l->first != NULL)
    {
        DLNode *cur = l->first;
        int i = 0; 
        while (i < k && cur->next != NULL)
        {
            cur = cur->next;
            i++;
        }

        if (i == k) 
        {
            void *data = cur->data;
            if (cur->prev != NULL)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                l->first = cur->next;
            }

            if (cur->next != NULL)
            {
                cur->next->prev = cur->prev;
            }

            free(cur);
            return data;
        }
    }

    return NULL;
}

void *csllRemoveKPosition(CSLList *l, int k)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;
            int i = 0;
            while (i < k && cur->next != l->first)
            {
                prev = cur;
                cur = cur->next;
                i++;
            }

            if (i == k)
            {
                void *data = cur->data;
                if (prev != NULL)
                {
                    prev->next = cur->next;
                }
                else
                {
                    
                    if(cur->next != cur){

                        CSLNode *last = l->first;
                        while (last->next != l->first)
                        {
                            last = last->next;
                        }
                        last->next = cur->next;
                        l->first = cur->next;
                    }

                    else{
                        l->first = NULL;
                    }
                    
                }

                free(cur);
                return data;
            }
        }
    }

    return NULL;
}

void *cdllRemoveKPosition(CDLList *l, int k)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *cur = l->first;
            int i = 0;
            while (i < k && cur->next != l->first)
            {
                cur = cur->next;
                i++;
            }

            if (i == k)
            {
                void *data = cur->data;
                if (cur->next != cur)
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    if (l->first == cur)
                    {
                        l->first = cur->next;
                    }
                }
                else
                {
                    l->first = NULL;
                }

                free(cur);
                return data;
            }
        }
    }

    return NULL;
}


void *sllRemoveByKey(SLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *current = l->first;
            SLNode *prev = NULL;
            int stat = cmp(current->data, key);
            while (stat != TRUE && current->next != NULL)
            {
                prev = current;
                current = current->next;
                stat = cmp(current->data, key);
            }

            if (stat)
            {
                void *data = current->data;
                if (prev != NULL)
                {
                    prev->next = current->next;
                }
                else
                {
                    l->first = current->next;
                }

                return data;
            }
        }
    }

    return NULL;
}

void *dllRemoveByKey(DLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                void *data = cur->data;
                DLNode *prevcur = cur->prev;
                DLNode *nextcur = cur->next;
                if (nextcur != NULL)
                {
                    nextcur->prev = prevcur;
                }

                if (prevcur != NULL)
                {
                    prevcur->next = nextcur;
                }

                if (prevcur == NULL)
                {
                    l->first = nextcur;
                }

                free(cur);
                return data;
            }
        }
    }

    return NULL;
}

void *csllRemoveByKey(CSLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                void *data = cur->data;
                if (prev != NULL)
                {
                    prev->next = cur->next;
                }
                else
                {
                    l->first = cur->next;
                }

                free(cur);
                return data;
            }
        }
    }

    return NULL;
}

void *cdllRemoveByKey(CDLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                void *data = cur->data;
                CDLNode *prevcur = cur->prev;
                CDLNode *nextcur = cur->next;
                nextcur->prev = prevcur;
                prevcur->next = nextcur;

                if (l->first == cur)
                {
                    if (nextcur == cur)
                    {
                        l->first = NULL;
                    }
                    else
                    {
                        l->first = nextcur;
                    }
                }

                free(cur);
                return data;
            }
        }
    }

    return NULL;
}

void *sllRemoveAfterKey(SLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                void *data = cur->next->data;
                SLNode *nextcur = cur->next;

                if (nextcur != NULL)
                {
                    cur->next = nextcur->next;

                    free(nextcur);
                    return data;
                }
            }
        }
    }

    return NULL;
}

void *dllRemoveAfterKey(DLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {

                DLNode *nextcur = cur->next;

                if (nextcur != NULL)
                {
                    void *data = cur->next->data;
                    cur->next = nextcur->next;
                    if (nextcur->next != NULL)
                    {
                        nextcur->next->prev = cur;
                    }
                    free(nextcur);
                    return data;
                }
            }
        }
    }
}

void *csllRemoveAfterKey(CSLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                CSLNode *nextcur = cur->next;
                if (nextcur != l->first)
                {
                    void *data = nextcur->data;
                    cur->next = nextcur->next;

                    free(nextcur);
                    return data;
                }
            }
        }
    }

    return NULL;
}

void *cdllRemoveAfterKey(CDLList *l, void *key, int (*cmp)(void *, void *))
{

    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                CDLNode *nextcur = cur->next;
                if (nextcur != l->first)
                {
                    void *data = nextcur->data;
                    cur->next = nextcur->next;
                    if (nextcur->next != NULL)
                    {
                        nextcur->next->prev = cur;
                    }

                    free(nextcur);
                    return data;
                }
            }
        }
    }
}

void *sllRemoveBeforeKey(SLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            SLNode *prev2 = NULL;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != NULL)
            {
                prev2 = prev;
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                if (prev != NULL)
                {
                    void *data = prev->data;
                    if (prev2 != NULL)
                    {
                        prev2->next = cur;
                    }
                    else
                    {
                        l->first = cur;
                    }

                    free(prev);
                    return data;
                }
            }
        }
    }

    return NULL;
}

void *dllRemoveBeforeKey(DLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                DLNode *prev = cur->prev;
                if (prev != NULL)
                {
                    void *data = prev->data;
                    if (prev->prev != NULL)
                    {
                        prev->prev->next = cur;
                    }
                    else
                    {
                        l->first = cur;
                    }

                    cur->prev = prev->prev;

                    free(prev);
                    return data;
                }
            }
        }
    }

    return NULL;
}

void *csllRemoveBeforeKey(CSLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;
            CSLNode *prev2 = NULL;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                prev2 = prev;
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                if (prev != NULL)
                {
                    void *data = prev->data;
                    if (prev2 != NULL)
                    {
                        prev2->next = cur;
                    }
                    else
                    {
                        l->first = cur;
                        // tenho que fazer o ultimo apontar para o novo primeiro
                        CSLNode *aux = l->first;
                        while (aux->next != l->first)
                        {
                            aux = aux->next;
                        }
                        aux->next = cur;
                    }

                    free(prev);
                    return data;
                }
            }
        }
    }

    return NULL;
}

void *cdllRemoveBeforeKey(CDLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            CDLNode *cur = l->first;
            int stat = cmp(cur->data, key);
            while (stat != TRUE && cur->next != l->first)
            {
                cur = cur->next;
                stat = cmp(cur->data, key);
            }

            if (stat)
            {
                CDLNode *prev = cur->prev;
                if (prev != NULL)
                {
                    void *data = prev->data;
                    prev->prev->next = cur;
                    cur->prev = prev->prev;
                    if (prev == l->first)
                    {
                        l->first = cur;
                    }

                    free(prev);
                    return data;
                }
            }
        }
    }

    return NULL;
}

void *sllConcatenateLists(SLList *l, SLList *k)
{
    if (l != NULL && k != NULL)
    {
        if (l->first != NULL && k->first != NULL)
        {
            SLNode *cur = l->first;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }

            cur->next = k->first;

            return l;
        }

        return NULL;
    }
}

void *dllConcatenateLists(DLList *l, DLList *k)
{
    if (l != NULL & k != NULL)
    {
        if (l->first != NULL && k->first != NULL)
        {
            DLNode *cur = l->first;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }

            cur->next = k->first;
            k->first->prev = cur;

            return l;
        }
    }

    return NULL;
}

void *csllConcatenateLists(CSLList *l, CSLList *k)
{
    if (l != NULL && k != NULL)
    {
        if (l->first != NULL && k->first != NULL)
        {
            CSLNode *cur = l->first;
            while (cur->next != l->first)
            {
                cur = cur->next;
            }

            cur->next = k->first;

            cur = k->first;
            while (cur->next != k->first)
            {
                cur = cur->next;
            }

            cur->next = l->first;

            return l;
        }
    }

    return NULL;
}

void *cdllConcatenateLists(CDLList *l, CDLList *k)
{
    if (l != NULL && k != NULL)
    {
        if (l->first != NULL && k->first != NULL)
        {
            CDLNode *firstL = l->first;
            CDLNode *lastL = l->first->prev;
            CDLNode *firstK = k->first;
            CDLNode *lastK = k->first->prev;

            lastL->next = firstK;
            firstK->prev = lastK;
            firstL->prev = lastK;
            lastK->next = firstL;

            return l;
        }
    }

    return NULL;
}

int sllFreeNodes(SLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *cur = l->first;
            SLNode *aux = cur;
            while (cur != NULL)
            {
                aux = aux->next;
                free(cur);
                cur = aux;
            }

            l->first = NULL;
            return TRUE;
        }
    }

    return FALSE;
}

int dllFreeNodes(DLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            DLNode *cur = l->first;
            DLNode *aux = cur;
            while (cur != NULL)
            {
                aux = aux->next;
                free(cur);
                cur = aux;
            }

            l->first = NULL;
            return TRUE;
        }
    }

    return FALSE;
}



int csllFreeNodes(CSLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {   
            CSLNode *first = l->first;
            CSLNode *cur = l->first;
            CSLNode *aux = cur;
            while (cur -> next != first)
            {
                aux = aux->next;
                free(cur);
                cur = aux;
            }
            free(cur);
            l->first = NULL;
            return TRUE;
        }
    }

    return FALSE;
}


int cdllFreeNodes(CDLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {   
            CDLNode *first = l->first;
            CDLNode *cur = l->first;
            CDLNode *aux = cur;
            while (cur -> next != first)
            {
                aux = aux->next;
                free(cur);
                cur = aux;
            }

            free(cur);
            l->first = NULL;
            return TRUE;
        }
    }

    return FALSE;
}

void *sllInvertList(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *cur = l->first;
            SLNode *next;
            SLNode *prev = NULL;
            while(cur != NULL){
                next = cur->next;
                cur -> next = prev;
                prev = cur;
                cur = next;
            }

            l->first = prev;

            return l;
        }
    }

    return NULL;
}

void *dllInvertList(DLList *l){
    if(l != NULL){
        if(l->first != NULL){
            DLNode *cur = l->first;
            DLNode *next;
            DLNode *prev = NULL;
            while(cur != NULL){
                next = cur->next;
                cur -> next = prev;
                cur -> prev = next;
                prev = cur;
                cur = next;
                
            }

            l->first = prev;

            return l;
        }
    }

    return NULL;
}

void *csllInvertList(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){
            CSLNode *cur = l->first;
            while(cur -> next != l->first){
                cur = cur->next;
            }

            CSLNode *prev = cur;
            cur = l->first;
            CSLNode *next = NULL;
            while(next != l->first){
                next = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = next;
                
            }

            l->first = prev;
            return l;
        }

    }

    return NULL;
}

void *cdllInvertList(CDLList *l){
    if(l != NULL){
        if(l->first != NULL){
            CDLNode *cur = l->first;
            CDLNode *next;
            CDLNode *prev;
            do{
                next = cur->next;
                prev = cur->prev;
                cur -> next = prev;
                cur -> prev = next;
                cur = next;
                
            }while(cur != l->first);

            l->first = cur->prev;

            return l;
        }
    }

    return NULL;
}

void *sllCombineOrdenedLists(SLList *l, SLList *k, int(*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            SLNode *curL = l->first;
            SLNode *curK = k->first;
            int stat;
            SLList *newlist = sllcreate();
            if(newlist != NULL){
                while(curL != NULL && curK != NULL){
                    if(cmp(curL->data, curK->data) <= 0){
                        sllInsertAsLast(newlist, curL->data);
                        curL = curL -> next;
                    }
                    else{
                        sllInsertAsLast(newlist, curK->data);
                        curK = curK -> next;
                    }
                   
                }

                if(curL != NULL){
                    while(curL != NULL){
                        sllInsertAsLast(newlist, curL->data);
                        curL = curL->next;
                    }
                }

                else if(curK != NULL){
                    while(curK != NULL){
                        sllInsertAsLast(newlist, curK->data);
                        curK = curK -> next;
                    }
                }

                return newlist;


            }

        }
    }

    return NULL;
}



void *dllCombineOrdenedLists(DLList *l, DLList *k, int(*cmp)(void *, void *)){
    if(l!= NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            DLNode *curL = l->first;
            DLNode *curK = k->first;
            DLList *newlist = dllcreate();
            if(newlist != NULL){
                while(curL != NULL && curK != NULL){
                    if(cmp(curL->data, curK->data) <= 0){
                        dllInsertAsLast(newlist, curL->data);
                        curL = curL -> next;
                    }
                    else{
                        dllInsertAsLast(newlist, curK->data);
                        curK = curK -> data;
                    }
                }

                if(curL != NULL){
                    while(curL != NULL){
                        dllInsertAsLast(newlist, curL->data);
                        curL = curL -> next;
                    }
                }
                else if(curK != NULL){
                    dllInsertAsLast(newlist, curK -> data);
                    curK = curK->next;
                }

                return newlist;


            }
            
        }
    }

    return NULL;
}

void *csllCombinedOrdenedLists(CSLList *l, CSLList *k, int(*cmp)(void *, void*)){
    if(l!= NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            CSLNode *curL = l->first;
            CSLNode *curK = k->first;
            CSLList *newlist = csllcreate();
            if(newlist != NULL){
                do{

                    if(cmp(curL->data, curK->data) <= 0){
                        csllInsertAsLast(newlist, curL->data);
                        curL = curL->next;
                    }

                    else{
                        csllInsertAsLast(newlist, curK->data);
                        curK = curK -> next;
                    }

                }while(curL != l->first && curK != k->first);

                if(curL != NULL){
                    while(curL != l->first){
                        csllInsertAsLast(newlist, curL->data);
                        curL = curL -> next;
                    }

                }

                else if(curK != NULL){
                    while(curK != k->first){
                        csllInsertAsLast(newlist, curK -> data);
                        curK = curK -> next;
                    }
                }

                return newlist;
                
            }
        }
    }

    return NULL;
}

void *cdllCombineOrdenedLists(CDLList *l, CDLList *k, int(*cpm)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            CDLNode *curL = l->first;
            CDLNode *curK = k->first;

            CDLList *newlist = cdllcreate();
            if(newlist != NULL){
                do{
                    if(cmp(curL->data, curK->data) <= 0){
                        cdllInsertAsLast(newlist, curL->data);
                        curL = curL -> next;
                    }
                    else{
                        cdllInsertAsLast(newlist, curK->data);
                        curK = curK -> next;
                    }
                }while(curL != l->first && curK != k->first);

                if(curL != NULL){
                    while(curL != l->first){
                        cdllInsertAsLast(newlist, curL->data);
                        curL = curL -> next;
                    }
                }
                else if(curK != NULL){
                    while(curK != k->first){
                        cdllInsertAsLast(newlist, curK->data);
                        curK = curK -> next;
                    }
                }

                return newlist;
            }
        }
    }

    return NULL;
}

void *sllJoinLists(SLList *l, SLList *k){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            SLList *newlist = sllcreate();
            if(newlist != NULL){
                SLNode *cur = l->first;
                while(cur != NULL){
                    sllInsertAsLast(newlist, cur->data);
                    cur = cur -> next;
                }

                cur = k->first;
                while(cur != NULL){
                    sllInsertAsLast(newlist, cur->data);
                    cur = cur->next;
                }

                return newlist;
            }
        }
    }

    return NULL;
}


void *dllJoinLists(DLList *l, DLList *k){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            DLList *newlist = dllcreate();
            if(newlist != NULL){
                DLNode *cur = l->first;
                while(cur != NULL){
                    dllInsertAsLast(newlist, cur->data);
                    cur = cur -> next;
                }

                cur = k->first;
                while(cur != NULL){
                    dllInsertAsLast(newlist, cur->data);
                    cur = cur->next;
                }

                return newlist;
            }
        }
    }
}

void *csllJoinLists(CSLList *l, CSLList *k){
     if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            CSLList *newlist = csllcreate();
            if(newlist != NULL){
                CSLNode *cur = l->first;
                do{
                    csllInsertAsLast(newlist, cur->data);
                    cur = cur -> next;
                }while(cur != l->first);

                cur = k->first;
                do{
                    csllInsertAsLast(newlist, cur->data);
                    cur = cur->next;
                }while(cur != k->first);

                return newlist;
            }
        }
    }
}

void *cdllJoinLists(CDLList *l, CDLList *k){
     if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            CDLList *newlist = cdllcreate();
            if(newlist != NULL){
                CDLNode *cur = l->first;
                do{
                    cdllInsertAsLast(newlist, cur->data);
                    cur = cur -> next;
                }while(cur != l->first);

                cur = k->first;
                do{
                    cdllInsertAsLast(newlist, cur->data);
                    cur = cur->next;
                }while(cur != k->first);

                return newlist;
            }
        }
    }
}

void *sllIntersectionLists(SLList *l, SLList *k, int(*cmp)(void *, void*)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            SLNode *curL = l->first;
            SLNode *curK;
            SLList *newlist = sllcreate();
            while(curL != NULL){
                curK = k->first;
                while(curK != NULL){
                    if(cmp(curL->data, curK->data)){
                        if(newlist -> first != NULL){
                            SLNode *newlistCur = newlist -> first;
                            int alreadyExists = FALSE;
                            while(newlistCur != NULL){
                                if(cmp(newlistCur->data, curL->data)){
                                    alreadyExists = TRUE;
                                    break;
                                }

                                newlistCur = newlistCur -> next;
                            }

                            if(alreadyExists == FALSE){
                                sllInsertAsLast(newlist, curL->data);
                            }
                        }
                    }

                    else{
                        sllInsertAsLast(newlist, curL->data);
                    }

                    curK = curK->next;
                }

                curL = curL->next;                

            }

            return newlist;
        }
    }

    return NULL;
}


void *dllIntersectionLists(DLList *l, DLList *k, int(*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            DLNode *curL = l->first;
            DLNode *curK;
            DLList *newlist = dllcreate();
            while(curL != NULL){
                curK = k->first;
                while(curK != NULL){
                    if(cmp(curL->data, curK->data)){
                        if(newlist -> first != NULL){
                            DLNode *newlistCur = newlist -> first;
                            int alreadyExists = FALSE;
                            while(newlistCur != NULL){
                                if(cmp(newlistCur->data, curL->data)){
                                    alreadyExists = TRUE;
                                    break;
                                }

                                newlistCur = newlistCur -> next;
                            }

                            if(alreadyExists == FALSE){
                                dllInsertAsLast(newlist, curL->data);
                            }
                        }
                    }

                    else{
                        dllInsertAsLast(newlist, curL->data);
                    }

                    curK = curK->next;
                }

                curL = curL->next;                

            }

            return newlist;
        }
    }

    return NULL;
}

void *csllIntersectionLists(CSLList *l, CSLList *k, int(*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            CSLNode *curL = l->first;
            CSLNode *curK;
            CSLList *newlist = csllcreate();
            if(newlist != NULL){
                do{

                    curK = k->first;

                    do{

                        if(cmp(curL->data, curK->data)){

                            CSLNode *newlistCur = newlist->first;
                            int alreadyExists = FALSE;
                            if(newlistCur != NULL){
                                do{ 
                                    if(cmp(curL->data, newlistCur -> data)){
                                        alreadyExists = TRUE;
                                        break;
                                    }

                                    newlistCur = newlistCur -> next;
                                    
                                }while(newlistCur = newlist -> first);

                            }

                            if(alreadyExists == FALSE){
                                csllInsertAsLast(newlist, curL->data);
                            }
                            
                        }

                        curK = curK -> next;
                    }while(curK != k->first);

                    curL = curL -> next;

                }while(curL != l->first);

                return newlist;


            }
            
        }
    }

    return NULL;
}


void *cdllIntersectionLists(CDLList *l, CDLList *k, int(*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            CDLNode *curL = l->first;
            CDLNode *curK;
            CDLList *newlist = cdllcreate();
            if(newlist != NULL){
                do{

                    curK = k->first;

                    do{

                        if(cmp(curL->data, curK->data)){

                            CDLNode *newlistCur = newlist->first;
                            int alreadyExists = FALSE;
                            if(newlistCur != NULL){
                                do{ 
                                    if(cmp(curL->data, newlistCur -> data)){
                                        alreadyExists = TRUE;
                                        break;
                                    }

                                    newlistCur = newlistCur -> next;
                                    
                                }while(newlistCur = newlist -> first);

                            }

                            if(alreadyExists == FALSE){
                                cdllInsertAsLast(newlist, curL->data);
                            }
                            
                        }

                        curK = curK -> next;
                    }while(curK != k->first);

                    curL = curL -> next;

                }while(curL != l->first);

                return newlist;


            }
            
        }
    }

    return NULL;

}


int sllSumList(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int soma = 0;
            SLNode *cur = l->first;
            while(cur != NULL){
                soma += (int)cur->data;
                cur = cur -> next;
            }

            return soma;
        }
    }

    return 0;
}

int dllSumList(DLList *l){

     if(l != NULL){
        if(l->first != NULL){
            int soma = 0;
            DLNode *cur = l->first;
            while(cur != NULL){
                soma += (int)cur->data;
                cur = cur -> next;
            }

            return soma;
        }
    }

    return 0;

}

int csllSumList(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int soma = 0;
            CSLNode *cur = l->first;
            do{
                soma += (int)cur->data;
                cur = cur -> next;
            }while(cur != l->first);

            return soma;
        }
    }

    return 0;
}


int cdllSumList(CDLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int soma = 0;
            CDLNode *cur = l->first;
            do{
                soma += (int)cur->data;
                cur = cur -> next;
            }while(cur != l->first);

            return soma;
        }
    }

    return 0;
}



int sllNumberElements(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int elementsNumber = 0;
            SLNode *cur = l->first;
            while(cur != NULL){
                elementsNumber++;
                cur = cur -> next;
            }

            return elementsNumber;
        }
    }

    return 0;
}


int dllNumberElements(DLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int elementsNumber = 0;
            DLNode *cur = l->first;
            while(cur != NULL){
                elementsNumber++;
                cur = cur -> next;
            }

            return elementsNumber;
        }
    }

    return 0;
}

int csllNumberElements(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){
            CSLNode *cur = l->first;
            int elementsNumber = 0;
            do{
                elementsNumber++;
                cur = cur->next;
            }while(cur != l->first);

            return elementsNumber;
        }
    }

    return 0;
}

int cdllNumberElements(CDLList *l){
    if(l != NULL){
        if(l->first != NULL){
            CDLNode *cur = l->first;
            int elementsNumber = 0;
            do{
                elementsNumber++;
                cur = cur->next;
            }while(cur != l->first);

            return elementsNumber;
        }
    }

    return 0;
}

void *sllCreateCopyList(SLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode *cur = l->first;
            SLList *copy = (SLList*)malloc(sizeof(SLList));
            if(copy != NULL){
                copy -> first = NULL;
                copy -> cur = NULL;
                while(cur != NULL){
                    SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                    if(newnode != NULL){
                        newnode -> data = cur -> data;
                        newnode -> next = NULL;
                        if(copy -> first != NULL){
                            l->first = newnode;
                            
                        }
                        else{
                            SLNode *copyNode = copy->first;
                            while(copyNode -> next != NULL){
                                copyNode = copyNode -> next;
                            }

                            copyNode -> next = newnode;
                        }
                    }

                    cur = cur->next;
                   
                }

                return copy;
            }

        }
    }

    return NULL;
}


void *dllCreateCopyList(DLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *cur = l->first;
            DLList *copy = (DLList*)malloc(sizeof(DLList));
            if(copy != NULL){
                copy -> first = NULL;
                copy -> cur = NULL;
                while(cur != NULL){
                    DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                    if(newnode != NULL){
                        newnode -> data = cur -> data;
                        newnode -> next = NULL;
                        if(copy -> first == NULL){
                            l->first = newnode;
                            newnode -> prev = NULL;
                            
                        }
                        else{
                            DLNode *copyNode = copy->first;
                            while(copyNode -> next != NULL){
                                copyNode = copyNode -> next;
                            }

                            copyNode -> next = newnode;
                            newnode -> prev = copyNode;
                        }
                    }

                    cur = cur->next;
                   
                }

                return copy;
            }

        }
    }

    return NULL;
}


void *csllCreateCopyList(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){
            CSLList *copyList = (CSLList *)malloc(sizeof(CSLList));
            if(copyList != NULL){
                copyList->first = NULL;
                copyList -> cur = NULL;
                CSLNode *cur = l->first;
                do{
                    CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                    newnode -> data = cur -> data;
                    if(copyList -> first == NULL){
                        copyList -> first = newnode;
                        newnode -> next = copyList -> first;
                    }
                    else{
                        CSLNode *copyNode = copyList -> first;
                        while(copyNode->next != copyList -> first){
                            copyNode = copyNode -> next;
                        }

                        copyNode -> next = newnode;
                        newnode -> next = copyList -> first;
                    }


                    cur = cur -> next;
                }while(cur != l->first);

                return copyList;
            }
        }
    }

    return NULL;
}

void *cdllCreateCopyList(CDLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            CDLList *copyList = (CDLList *)malloc(sizeof(CDLList));
            if(copyList != NULL){
                copyList -> first = NULL;
                copyList -> cur = NULL;
                CDLNode *cur = l->first;
                do{
                    CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                    if(newnode != NULL){
                        newnode -> data = cur -> data;
                        if(copyList -> first == NULL){
                            copyList->first = newnode;
                            newnode -> prev = copyList->first;
                            newnode -> next = copyList->first;
                        }
                        else{
                            CDLNode *copyNode = copyList -> first;
                            while (copyNode -> next != copyList -> first){
                                copyNode = copyNode -> next;
                            }

                            newnode -> next = copyNode -> next;
                            newnode -> prev = copyNode;
                            copyNode -> next = newnode;
                        }
                    }

                    cur = cur -> next;
                }while(cur != l->first);

                return copyList;
            }
        }
    }

    return NULL;
}


int sllVerifyEqualsLists(SLList *l, SLList *k, int(*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            SLNode *curL = l->first;
            SLNode *curK = k->first;

            while(curL != NULL && curK != NULL){
                if(cmp(curL -> data, curK -> data) != 0){
                    return FALSE;
                }

                curL = curL->next;
                curK = curK->next;
            }

            if(curL == NULL && curK == NULL){
                return TRUE;
            }
            else{
                return FALSE;
            }
        }
    }

    return FALSE;
}

int dllVerifyEqualsLists(DLList *l, DLList *k, int(*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            DLNode *curL = l->first;
            DLNode *curK = k->first;

            while(curL != NULL && curK != NULL){
                if(cmp(curL -> data, curK -> data) != 0){
                    return FALSE;
                }

                curL = curL->next;
                curK = curK->next;
            }

            if(curL == NULL && curK == NULL){
                return TRUE;
            }
            else{
                return FALSE;
            }
        }
    }

    return FALSE;
}

int csllVerifyEqualsLists(CSLList *l, CSLList *k, int (*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            CSLNode *curL = l->first;
            CSLNode *curK = k->first;

            do{

                if(cmp(curL -> data, curK -> data) != 0){
                    return FALSE;
                }

                curL = curL -> next;
                curK = curK -> next;

            }while(curL != l->first && curK != k->first);

            if(curL == NULL && curK == NULL){
                return TRUE;
            }
            else{
                return FALSE;
            }
        }
    }

    return FALSE;
}

int cdllVerifyEqualsLists(CDLList *l, CDLList *k, int (*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){
            CDLNode *curL = l->first;
            CDLNode *curK = k->first;

            do{

                if(cmp(curL -> data, curK -> data) != 0){
                    return FALSE;
                }

                curL = curL -> next;
                curK = curK -> next;

            }while(curL != l->first && curK != k->first);

            if(curL == NULL && curK == NULL){
                return TRUE;
            }
            else{
                return FALSE;
            }
        }
    }

    return FALSE;
}

void *sllSplitList(SLList *l, int k){
    if(l != NULL){
        if(l->first != NULL){
            int i = 0;
            SLNode *cur = l->first;
            while(i<k && cur != NULL){
                cur = cur -> next;
                i++;
            }

            if(cur != NULL){

                SLNode *aux = cur->next;
                cur -> next = NULL;
                SLList *newlist = sllcreate();
                if(newlist != NULL){
                    while(aux != NULL){
                        sllInsertAsLast(newlist, aux->data);
                        aux = aux -> next;
                    }

                    return newlist;
                }

                

            }

           
        }
    }

    return NULL;
}

void *dllSplitList(DLList *l, int k){

    if(l != NULL){
        if(l->first != NULL){
            int i = 0;
            DLNode *cur = l->first;
            while(i<k && cur->next != NULL){
                cur = cur -> next;
                i++;
            }

            if(i == k){
                DLNode *aux = cur -> next;
                cur -> next = NULL;
                DLList *newlist = dllcreate();
                if(newlist != NULL){
                    while(aux != NULL){
                        dllInsertAsLast(newlist, aux->data);
                        aux = aux -> next;
                    }

                    return newlist;
                }
            }
        }
    }

    return NULL;
}


void *csllSplitList(CSLList *l, int k){
    if(l != NULL){
        if(l->first != NULL){
            int i = 0;
            CSLNode *cur = l->first;
            while(i<k && cur->next != l->first){
                cur = cur -> next;
                i++;
               
            }

            if(i == k){
                CSLNode *aux = cur -> next;
                cur -> next = l->first;
                CSLList *newlist = csllcreate();
                if(newlist != NULL){
                    do{
                        csllInsertAsLast(newlist, aux->data);
                        aux = aux -> next;
                    }while(aux != l->first);

                    return newlist;
                }
            }
        }
    }

    return NULL;
}

void *cdllSplitList(CDLList *l, int k){
    if(l != NULL){
        if(l->first != NULL){
            int i = 0;
            CDLNode *cur = l->first;
            while(i<k && cur -> next != l->first){
                cur = cur -> next;
                i++;
            }

            if(i == k){
                CDLNode *aux = cur -> next;
                cur -> next = l->first;
                l->first->prev = cur;
                CDLList *newlist = csllcreate();
                if(newlist != NULL){
                    do{
                        cdllInsertAsLast(newlist, aux->data);
                        aux = aux -> next;
                    }while(aux != l->first);

                    return newlist;
                }
            }
        }
    }

    return NULL;
}

void *sllremoveNElements(SLList *l, int n){
    if(l != NULL){
        if(l -> first != NULL){
            int i = 0;
            SLNode *cur = l->first;
            SLNode *next = NULL;
            while(i <= n && cur != NULL){
                next = cur -> next;
                free(cur);
                cur = next;
                i++;
            }

            if(cur != NULL){
                l->first = cur;
            }
            else{
                l->first = NULL;
            }

            return l;
        }
    }

    return NULL;
}

void *dllRemoveNElements(DLList *l, int n){
    if(l != NULL){
        if(l -> first != NULL){
            int i = 0;
            DLNode *cur = l->first;
            DLNode *next = NULL;
            while(i <= n && cur != NULL){
                next = cur -> next;
                free(cur);
                cur = next;
                i++;
            }

            if(cur != NULL){
                l->first = cur;
                cur -> prev = NULL;
            }
            else{
                l->first = NULL;
            }

            return l;
        }
    }

    return NULL;
}


void *csllRemoveNElements(CSLList *l, int n){
    if(l != NULL){
        if(l -> first != NULL){
            
            CSLNode *cur = l->first;
            //tenho que pegar o número de elementos da lista, por que se eu fizer direto com o
            //while com a codicao cur != l->first, l->first já terá sido liberado
            int numeroElementos = 0;
            
            while(cur -> next != l->first){
                cur = cur -> next;
                numeroElementos++;
            }
            numeroElementos++;
            //guardo o ultimo elemento pq vai ser útil para depois faze-lo apontar para o novo primeiro
            CSLNode *last = cur;

            int i = 1;
            cur = l->first;
            CSLNode *next;
            while(i <= n && i <= numeroElementos){
                next = cur->next;
                free(cur);
                cur = next;
                i++;
            }

            if(n >= numeroElementos){
                l->first = NULL;
            }
            else{
                //tenho que fazer o último apontar para o novo primeiro, para isso guardei o último
                last -> next = cur;
            }

            return l;
        }
    }

    return NULL;
}

void *cdllRemoveNElements(CDLList *l, int n){
    if(l != NULL){
        if(l -> first != NULL){
            
            CDLNode *cur = l->first;
            //tenho que pegar o número de elementos da lista, por que se eu fizer direto com o
            //while com a codicao cur != l->first, l->first já terá sido liberado
            int numeroElementos = 0;
            
            while(cur -> next != l->first){
                cur = cur -> next;
                numeroElementos++;
            }
            numeroElementos++;
            //guardo o ultimo elemento pq vai ser útil para depois faze-lo apontar para o novo primeiro
            CDLNode *last = cur;

            int i = 1;
            cur = l->first;
            CDLNode *next;
            while(i <= n && i <= numeroElementos){
                next = cur->next;
                free(cur);
                cur = next;
                i++;
            }

            if(n >= numeroElementos){
                l->first = NULL;
            }
            else{
                //tenho que fazer o último apontar para o novo primeiro, para isso guardei o último
                last -> next = cur;
                cur -> prev = last;
            }

            return l;
        }
    }

    return NULL;
}

int sllDetectCycle(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            //algoritmo da tartaruga e da lebre

            SLNode *slow = l->first;
            SLNode *fast = l-> first;

            while (fast != NULL && fast -> next != NULL){
                slow = slow -> next;
                fast = fast -> next -> next;

                if(slow == fast){
                    return TRUE;
                }
            }

        }
    }

    return FALSE;
}

int dllDetectCycle(DLList *l){
     if(l != NULL){
        if(l->first != NULL){
            //algoritmo da tartaruga e da lebre

            DLNode *slow = l->first;
            DLNode *fast = l-> first;

            while (fast != NULL && fast -> next != NULL){
                slow = slow -> next;
                fast = fast -> next -> next;

                if(slow == fast){
                    return TRUE;
                }
            }

        }
    }

    return FALSE;
}


int csllDetectCycle(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){

            CSLNode *slow = l->first;
            CSLNode *fast = l->first;

            do{
                slow = slow -> next;
                fast = fast->next->next;
                if(slow == fast){
                    return TRUE;
                }
            }while(fast != l->first && fast -> next != l->first);
        }
    }

    return FALSE;
}

int cdllDetectCycle(CDLList *l){
    if(l != NULL){
        if(l->first != NULL){

            CDLNode *slow = l->first;
            CDLNode *fast = l->first;

            do{
                slow = slow -> next;
                fast = fast->next->next;
                if(slow == fast){
                    return TRUE;
                }
            }while(fast != l->first && fast -> next != l->first);
        }
    }

    return FALSE;
}


void *sllRemoveDuplicateData(SLList *l, int(*cmp)(void *, void*)){
    if(l != NULL){
        if(l -> first != NULL){

            SLNode *cur1 = l->first;
            SLNode *dup = NULL;
            while(cur1 != NULL){
                SLNode *prev = cur1;
                SLNode *cur2 = cur1->next;

                while(cur2 != NULL){
                    if(cmp(cur1->data, cur2->data) == 0){
                        dup = cur2;
                        prev->next = cur2->next;
                        free(dup);
                        cur2 = prev->next;

                    }
                    else{
                        prev = cur2;
                        cur2 = cur2 -> next;
                    }

                    
                    
                }

                cur1 = cur1->next;
            }

            return l;
        }


    return NULL;
    }

}


void *dllRemoveDuplicateData(DLList *l, int(*cmp)(void *, void*)){
    if(l != NULL){
        if(l -> first != NULL){

            DLNode *cur1 = l->first;
            DLNode *dup = NULL;
            while(cur1 != NULL){
                DLNode *prev = cur1;
                DLNode *cur2 = cur1->next;

                while(cur2 != NULL){
                    if(cmp(cur1->data, cur2->data) == 0){
                        dup = cur2;
                        prev->next = cur2->next;
                        free(dup);
                        cur2 = prev->next;

                    }
                    else{
                        prev = cur2;
                        cur2 = cur2 -> next;
                    }

                    
                    
                }

                cur1 = cur1->next;
            }

            return l;
        }


    return NULL;
    }
}

void *csllRemoveDuplicateData(CSLList *l, int(*cmp)(void *, void*)){
    if(l != NULL){
        if(l -> first != NULL){
            CSLNode *cur1 = l->first;
            CSLNode *dup = NULL;

            do{
                CSLNode *prev = cur1;
                CSLNode *cur2 = cur1 -> next;

                if(cur2 != l->first){
                    do{
                        if(cmp(cur1->data, cur2->data) == 0){
                            dup = cur2;
                            prev -> next = cur2 -> next;
                            free(dup);
                            cur2 = prev->next;
                        }
                        else{
                            prev = cur2;
                            cur2 = cur2 -> next;
                        }

                    
                    }while(cur2 != l->first);
                }

                cur1 = cur1 -> next;

            }while(cur1 != l->first);

            return l;
        }
    }

    return NULL;
}


void *cdllRemoveDuplicateData(CDLList *l, int(*cmp)(void *, void*)){
     if(l != NULL){
        if(l -> first != NULL){
            CDLNode *cur1 = l->first;
            CDLNode *dup = NULL;

            do{
                CDLNode *prev = cur1;
                CDLNode *cur2 = cur1 -> next;

                if(cur2 != l->first){
                    do{
                        if(cmp(cur1->data, cur2->data) == 0){
                            dup = cur2;
                            prev -> next = cur2 -> next;
                            cur2->next->prev = prev;
                            free(dup);
                            cur2 = prev->next;
                        }
                        else{
                            prev = cur2;
                            cur2 = cur2 -> next;
                        }

                    
                    }while(cur2 != l->first);


                }
                

                cur1 = cur1 -> next;

            }while(cur1 != l->first);

            return l;
        }
    }

    return NULL;
}

void *sllRemoveConsecutiveDuplicateData(SLList *l, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *prev = l->first;
            SLNode *cur = l->first->next;
            SLNode *dup = NULL;
            while(cur != NULL){
                if(cmp(prev->data, cur->data) == 0){
                    dup = cur;
                    prev->next = cur->next;
                    free(dup);
                    cur = prev->next;
                }
                else{
                    prev = cur;
                    cur = cur->next;
                }
            }

            return l;
        }
    }

    return NULL;
}


void *dllRemoveConsecutiveDuplicateData(DLList *l, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            DLNode *prev = l->first;
            DLNode *cur = l->first->next;
            DLNode *dup = NULL;
            while(cur != NULL){
                if(cmp(prev->data, cur->data) == 0){
                    dup = cur;
                    prev->next = cur->next;
                    if(cur -> next != NULL){
                        cur -> next -> prev = prev;
                    }
                    free(dup);
                    cur = prev->next;
                }
                else{
                    prev = cur;
                    cur = cur->next;
                }
            }

            return l;
        }
    }

    return NULL;
}


void *csllRemoveConsecutiveDuplicateData(CSLList *l, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            CSLNode *prev = l->first;
            CSLNode *cur = l->first->next;
            CSLNode *dup = NULL;
            while(cur != l->first){
                if(cmp(prev->data, cur->data) == 0){
                    dup = cur;
                    prev->next = cur->next;
                    free(dup);
                    cur = prev->next;
                }
                else{
                    prev = cur;
                    cur = cur->next;
                }
            }

            return l;
        }
    }

    return NULL;
}

void *cdllRemoveConsecutiveDuplicateData(CDLList *l, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            CDLNode *prev = l->first;
            CDLNode *cur = l->first->next;
            CDLNode *dup = NULL;
            while(cur != l->first){
                if(cmp(prev->data, cur->data) == 0){
                    dup = cur;
                    prev->next = cur->next;
                    cur -> next -> prev = prev;
                    free(dup);
                    cur = prev->next;
                }
                else{
                    prev = cur;
                    cur = cur->next;
                }
            }

            return l;
        }
    }

    return NULL;
}


void *sllReturnKFromLast(SLList *l, int k){
    if(l != NULL){
        if(l -> first != NULL){
            SLNode *cur1 = l->first;
            SLNode *cur2 = l->first;

            for(int i = 0; i < k; i++){
                if(cur1 == NULL){
                    return NULL;
                }

                cur1 = cur1 -> next;
            }

            while(cur1 != NULL){
                cur1 = cur1 -> next;
                cur2 = cur2 -> next;
            }

            return cur2;

        }
    }

    return NULL;
}

void *dllReturnKFromLast(DLList *l, int k){
    if(l != NULL){
        if(l -> first != NULL){
            DLNode *cur1 = l->first;
            DLNode *cur2 = l->first;

            for(int i = 0; i < k; i++){
                if(cur1 == NULL){
                    return NULL;
                }

                cur1 = cur1 -> next;
            }

            while(cur1 != NULL){
                cur1 = cur1 -> next;
                cur2 = cur2 -> next;
            }

            return cur2;

        }
    }

    return NULL;
}


void *csllReturnKFromLast(CSLList *l, int k){
    if(l != NULL){
        if(l->first != NULL){
            CSLNode *cur1 = l->first;
            CSLNode *cur2 = l->first;

            for(int i = 0; i<k; i++){
                cur1 = cur1 -> next;
                if(cur1 == l->first){
                    return NULL;
                }
            }

            do{
                cur1 = cur1 -> next;
                cur2 = cur2 -> next;
            }while(cur1 != l->first);

            return cur2;
        }
    }

    return NULL;
}

int sllIsPalindrome(SLList *l, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *cur = l->first;
            SLList *auxList = sllcreate();
            while(cur != NULL){
                sllInsertAsFirst(auxList, cur -> data);
                cur = cur -> next;
            }

            cur = l->first;
            SLNode *cur2 = auxList -> first;
            while(cur != NULL){
                if(cmp(cur->data, cur2 -> data) != 0){
                    return FALSE;
                }

                cur = cur -> next;
                cur2 = cur2 -> next;
            }

            sllFreeNodes(auxList);
            return TRUE;
        }
    }

    return FALSE;
}


int dllIsPalindrome(DLList *l, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            DLNode *cur = l->first;
            DLList *auxList = dllcreate();
            while(cur != NULL){
                dllInsertAsFirst(auxList, cur -> data);
                cur = cur -> next;
            }

            cur = l->first;
            DLNode *cur2 = auxList -> first;
            while(cur != NULL){
                if(cmp(cur->data, cur2 -> data) != 0){
                    return FALSE;
                }

                cur = cur -> next;
                cur2 = cur2 -> next;
            }

            fllFreeNodes(auxList);
            return TRUE;
        }
    }

    return FALSE;
}


int csllIsPalindrome(CSLList *l, int(*cmp)(void *, void*)){
    if(l != NULL){
        if(l->first != NULL){
            CSLNode *cur = l->first;
            CSLList *auxList = csllcreate();
            do{
                csllInsertAsFirst(auxList, cur->data);
                cur = cur -> next;
            }while(cur != l->first);

            cur = l->first;
            CSLNode *cur2 = auxList->first;

            do{
                if(cmp(cur->data, cur2->data) != 0){
                    return FALSE;
                }
                cur = cur -> next;
                cur2 = cur2 -> next;

            }while(cur != l->first);

            return TRUE;
        }
    }

    return FALSE;
}


int cdllIsPalindrome(CDLList *l, int(*cmp)(void*, void*)){
    if(l != NULL){
        if(l->first != NULL){
            CDLNode *cur = l->first;
            CDLList *auxList = cdllcreate();
            do{
                cdllInsertAsFirst(auxList, cur->data);
                cur = cur -> next;
            }while(cur != l->first);

            cur = l->first;
            CDLNode *cur2 = auxList->first;

            do{
                if(cmp(cur->data, cur2->data) != 0){
                    return FALSE;
                }
                cur = cur -> next;
                cur2 = cur2 -> next;

            }while(cur != l->first);

            return TRUE;
        }
    }

    return FALSE;
}

int sllSplitListAllocatingNodes(SLList *l, SLList *firstList, SLList *secondList){
    if(l != NULL){
        if(l->first != NULL){
            if(firstList != NULL && secondList != NULL){
                int putFirstList = TRUE;
                SLNode *cur = l->first;
                SLNode *aux = NULL;
                while(cur != NULL){
                    aux = cur->next;
                    if(putFirstList){
                        sllInsertAsLast(firstList, cur -> data);
                        putFirstList = FALSE;
                    }
                    else{
                        sllInsertAsLast(secondList, cur -> data);
                        putFirstList = TRUE;
                    }

                    free(cur);
                    cur = aux;
                    
                }
                free(l);
                return TRUE;
            }
        }
    }

    return FALSE;
}


int dllSplitListAllocatingNodes(DLList *l, DLList *firstList, SLList *secondList){
    if(l != NULL && firstList != NULL && secondList != NULL){
        if(l->first != NULL){
            int putFirstList = TRUE;
            DLNode *cur = l->first;
            DLNode *aux = NULL;
            while(cur != NULL){
                aux = cur->next;
                if(putFirstList){
                    dllInsertAsLast(firstList, cur -> data);
                    putFirstList = FALSE;
                }
                else{
                    dllInsertAsLast(secondList, cur -> data);
                    putFirstList = TRUE;
                }

                free(cur);
                cur = aux;
                
            }
            free(l);
            return TRUE;
            
        }
    }

    return FALSE;
}


int csllSplitListAllocatingNodes(CSLList *l, CSLList *firstList, CSLList *secondList){
    if(l != NULL && firstList != NULL && secondList != NULL){
        if(l->first != NULL){
            int putFirstList = TRUE;

            CSLNode *cur = l->first;
            CSLNode *aux = NULL;
            do{
                aux = cur -> next;
                if(putFirstList){
                    csllInsertAsLast(firstList, cur -> data);
                    putFirstList = FALSE;
                }
                else{
                    csllInsertAsLast(secondList, cur -> data);
                    putFirstList = TRUE;
                }

                free(cur);
                cur = aux;

            }while(cur != l->first);

            return TRUE;
        }
    }

    return FALSE;
}

int cdllSplitListAllocatingNodes(CDLList *l, CDLList *firstList, CDLList *secondList){


    if(l != NULL && firstList != NULL && secondList != NULL){
        if(l->first != NULL){
            int putFirstList = TRUE;

            CDLNode *cur = l->first;
            CDLNode *aux = NULL;
            do{
                aux = cur -> next;
                if(putFirstList){
                    cdllInsertAsLast(firstList, cur -> data);
                    putFirstList = FALSE;
                }
                else{
                    cdllInsertAsLast(secondList, cur -> data);
                    putFirstList = TRUE;
                }

                free(cur);
                cur = aux;

            }while(cur != l->first);

            return TRUE;
        }
    }

    return FALSE;


}

int sllSplitListNotAllocatingNodes(SLList *l, SLList *firstList, SLList *secondList){
    if(l != NULL && firstList != NULL && secondList != NULL){
        if(l->first != NULL){
            SLNode *cur = l->first;
            int putFirstList = TRUE;
            SLNode *curFirst = NULL;
            SLNode *curSec = NULL;
            while(cur != NULL){
                if(putFirstList){
                    if(firstList -> first != NULL){
                        curFirst->next = cur;
                        curFirst = cur;
                    }
                    else{
                        curFirst = cur;
                        firstList->first = curFirst;
                    }

                    putFirstList = FALSE;
                }

                else{
                    if(secondList -> first != NULL){
                        curSec->next = cur;
                        curSec = cur;
                    }
                    else{
                        curSec = cur;
                        secondList->first = curSec;
                    }

                    putFirstList = TRUE;
                }

                cur = cur -> next;
            }

            curFirst -> next = NULL;
            curSec -> next = NULL;

            return TRUE;
        }
    }

    return FALSE;
}


int dllSplitListNotAllocatingNodes(DLList *l, DLList *firstList, DLList *secondList){
    if(l != NULL && firstList != NULL && secondList != NULL){
        if(l->first != NULL){
            DLNode *cur = l->first;
            int putFirstList = TRUE;
            DLNode *curFirst = NULL;
            DLNode *curSec = NULL;
            while(cur != NULL){
                if(putFirstList){
                    if(firstList -> first != NULL){
                        curFirst->next = cur;
                        cur -> prev = curFirst;
                        curFirst = cur;
                    }
                    else{
                        curFirst = cur;
                        firstList->first = curFirst;
                        curFirst -> prev = NULL;
                    }

                    putFirstList = FALSE;
                }

                else{
                    if(secondList -> first != NULL){
                        curSec->next = cur;
                        cur -> prev = curSec;
                        curSec = cur;
                    }
                    else{
                        curSec = cur;
                        secondList->first = curSec;
                        curSec -> prev = NULL;
                    }

                    putFirstList = TRUE;
                }

                cur = cur -> next;
            }

            curFirst -> next = NULL;
            curSec -> next = NULL;

            return TRUE;
        }
    }

    return FALSE;
}

int csllSplitListNotAllocatingNodes(CSLList *l, CSLList *firstList, CSLList *secondList){
    if(l != NULL && firstList != NULL && secondList != NULL){
        if(l->first != NULL){
            CSLNode *cur = l->first;
            int putFirstList = TRUE;
            CSLNode *curFirst = NULL;
            CSLNode *curSec = NULL;
            do{
                if(putFirstList){
                    if(firstList -> first != NULL){
                        curFirst->next = cur;
                        curFirst = cur;
                    }
                    else{
                        curFirst = cur;
                        firstList->first = curFirst;
                    }

                    putFirstList = FALSE;
                }

                else{
                    if(secondList -> first != NULL){
                        curSec->next = cur;
                        curSec = cur;
                    }
                    else{
                        curSec = cur;
                        secondList->first = curSec;
                    }

                    putFirstList = TRUE;
                }

                cur = cur -> next;
            }while(cur != l->first);

            curFirst -> next = firstList -> first;
            curSec -> next = secondList -> first;

            return TRUE;
        }
    }

    return FALSE;
}


int cdllSplitListNotAllocatingNodes(CDLList *l, CDLList *firstList, CDLList *secondList){
    if(l != NULL && firstList != NULL && secondList != NULL){
        if(l->first != NULL){
            CDLNode *cur = l->first;
            int putFirstList = TRUE;
            CDLNode *curFirst = NULL;
            CDLNode *curSec = NULL;
            do{
                if(putFirstList){
                    if(firstList -> first != NULL){
                        curFirst->next = cur;
                        cur -> prev = curFirst;
                        curFirst = cur;
                    }
                    else{
                        curFirst = cur;
                        firstList->first = curFirst;
                        curFirst -> prev = NULL;
                    }

                    putFirstList = FALSE;
                }

                else{
                    if(secondList -> first != NULL){
                        curSec->next = cur;
                        cur -> prev = curSec;
                        curSec = cur;
                    }
                    else{
                        curSec = cur;
                        secondList->first = curSec;
                        curSec -> prev = NULL;
                    }

                    putFirstList = TRUE;
                }

                cur = cur -> next;
            }while(cur != l->first);

            curFirst -> next = firstList -> first;
            curSec -> next = secondList -> first;

            firstList -> first -> prev = curFirst;
            secondList -> first -> prev = curSec;

            return TRUE;
        }
    }

    return FALSE;
}


void *sllGetMiddleElement(SLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            int sizeList = 0;
            SLNode *cur = l->first;

            while(cur != NULL){
                sizeList++;
                cur = cur -> next;
            }

            if(sizeList %2 == 1){
                int middleElement = (sizeList - 1)/2;

                int i = 0;
                cur = l->first;
                while(i < middleElement){
                    cur = cur -> next;
                    i++;
                }

                return cur->data;
            }
        }
    }

    return NULL;
}


void *dllGetMiddleElement(DLList *l){

    if(l != NULL){
        if(l -> first != NULL){
            int sizeList = 0;
            DLNode *cur = l->first;

            while(cur != NULL){
                sizeList++;
                cur = cur -> next;
            }

            if(sizeList %2 == 1){
                int middleElement = (sizeList - 1)/2;

                int i = 0;
                cur = l->first;
                while(i < middleElement){
                    cur = cur -> next;
                    i++;
                }

                return cur->data;
            }
        }
    }

    return NULL;

}

void *csllGetMiddleElement(CSLList *l){
    if(l != NULL){
        if(l -> first != NULL){
            int sizeList = 0;
            CSLNode *cur = l->first;

            do{
                sizeList++;
                cur = cur -> next;
            }while(cur != l->first);

            if(sizeList %2 == 1){
                int middleElement = (sizeList - 1)/2;

                int i = 0;
                cur = l->first;
                while(i < middleElement){
                    cur = cur -> next;
                    i++;
                }

                return cur->data;
            }
        }
    }

    return NULL;
}


void *cdllGetMiddleElement(CDLList *l){
     if(l != NULL){
        if(l -> first != NULL){
            int sizeList = 0;
            CDLNode *cur = l->first;

            do{
                sizeList++;
                cur = cur -> next;
            }while(cur != l->first);

            if(sizeList %2 == 1){
                int middleElement = (sizeList - 1)/2;

                int i = 0;
                cur = l->first;
                while(i < middleElement){
                    cur = cur -> next;
                    i++;
                }

                return cur->data;
            }
        }
    }

    return NULL;
}


int sllInsertInMiddle(SLList *l, void *data){
    if(l != NULL){
        if(l->first != NULL){
            int numeroElementos = 0;
            SLNode *cur = l->first;
            while(cur != NULL){
                numeroElementos ++;
                cur = cur -> next;
            }

            int middleElement = numeroElementos / 2;

            cur = l->first;
            for(int i = 0; i < middleElement - 1; i++){ 
                cur = cur->next;
            }

            SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
            if(newnode != NULL){
                newnode->data = data;
                newnode->next = cur->next;
                cur->next = newnode;

                return TRUE;
            }
        }
    }

    return FALSE;
}

int dllInsertInMiddle(DLList *l, void *data){

    if(l != NULL){
        if(l->first != NULL){
            int numeroElementos = 0;
            DLNode *cur = l->first;
            while(cur != NULL){
                numeroElementos ++;
                cur = cur -> next;
            }

            int middleElement = numeroElementos / 2;

            cur = l->first;
            for(int i = 0; i < middleElement - 1; i++){ 
                cur = cur->next;
            }

            DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
            if(newnode != NULL){
                newnode->data = data;
                newnode->next = cur->next;
                newnode -> prev = cur;
                cur->next = newnode;

                return TRUE;
            }
        }
    }

    return FALSE;
}

int csllInsertInMiddle(CSLList *l, void *data){

    if(l != NULL){
        if(l->first != NULL){
            int numeroElementos = 0;
            CSLNode *cur = l->first;
            do{
                numeroElementos ++;
                cur = cur -> next;
            }while(cur != l->first);

            int middleElement = numeroElementos / 2;

            cur = l->first;
            for(int i = 0; i < middleElement - 1; i++){ 
                cur = cur->next;
            }

            CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
            if(newnode != NULL){
                newnode->data = data;
                newnode->next = cur->next;
                cur->next = newnode;

                return TRUE;
            }
        }
    }

    return FALSE;

}


int cdllInsertInMiddle(CDLList *l, void *data){
    if(l != NULL){
        if(l->first != NULL){
            int numeroElementos = 0;
            DLNode *cur = l->first;
            do{
                numeroElementos ++;
                cur = cur -> next;
            }while(cur != l->first);

            int middleElement = numeroElementos / 2;

            cur = l->first;
            for(int i = 0; i < middleElement - 1; i++){ 
                cur = cur->next;
            }

            DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
            if(newnode != NULL){
                newnode->data = data;
                newnode->next = cur->next;
                newnode -> prev = cur;
                cur->next = newnode;

                if(numeroElementos == 1){
                    cur -> prev = newnode;
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}


int sllListLength(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int length = 0;
            SLNode *cur = l->first;

            while(cur != NULL){
                length++;
                cur = cur -> next;
            }

            return length;
        }
    }

    return 0;
}

int dllListLength(DLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int length = 0;
            DLNode *cur = l->first;
            while(cur != NULL){
                length++;
                cur = cur -> next;
            }

            return length;
        }
    }

    return 0;
}


int csllListLength(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int length = 0;
            CSLNode *cur = l->first;

            do{
                length++;
                cur = cur -> next;
            }while(cur != l->first);

            return length;
        }
    }

    return 0;
}

int cdllListLength(CDLList *l){
     if(l != NULL){
        if(l->first != NULL){
            int length = 0;
            CDLNode *cur = l->first;

            do{
                length++;
                cur = cur -> next;
            }while(cur != l->first);

            return length;
        }
    }

    return 0;
}

int sllIsEquals(SLList *l, SLList *k, int(*cmp)(void*, void*)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){

            SLNode *curL = l->first;
            SLNode *curK = k->first;

            while(curK != NULL && curL != NULL){
                if(cmp(curL->data, curK->data) != 0){
                    return FALSE;
                }

                curL = curL -> next;
                curK = curK -> next;
            }

            if(curK == NULL && curL == NULL){
                return TRUE;
            }
        }
    }

    return FALSE;
}

int dllIsEquals(DLList *l, DLList *k, int(*cmp)(void*, void*)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){

            DLNode *curL = l->first;
            DLNode *curK = k->first;

            while(curK != NULL && curL != NULL){
                if(cmp(curL->data, curK->data) != 0){
                    return FALSE;
                }

                curL = curL -> next;
                curK = curK -> next;
            }

            if(curK == NULL && curL == NULL){
                return TRUE;
            }
        }
    }

    return FALSE;
}

int csllIsEquals(CSLList *l, CSLList *k, int(*cmp)(void*, void*)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){

            CSLNode *curL = l->first;
            CSLNode *curK = k->first;

            do{
                if(cmp(curL->data, curK->data) != 0){
                    return FALSE;
                }

                curL = curL -> next;
                curK = curK -> next;
            }while(curK != k->first && curL != l->first);

            if(curK == k->first && curL == l->first){
                return TRUE;
            }
        }
    }

    return FALSE;
}


int cdllIsEquals(CDLList *l, CDLList *k, int(*cmp)(void*, void*)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k->first != NULL){

            CDLNode *curL = l->first;
            CDLNode *curK = k->first;

            do{
                if(cmp(curL->data, curK->data) != 0){
                    return FALSE;
                }

                curL = curL -> next;
                curK = curK -> next;
            }while(curK != k->first && curL != l->first);

            if(curK == k->first && curL == l->first){
                return TRUE;
            }
        }
    }

    return FALSE;
}

void *sllReturnL2Copy(SLList *l1, SLList *l2){
    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL){

            SLNode *l1Cur = l1->first;
            SLNode *l2Cur = NULL;
            while(l1Cur != NULL){
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if(newnode != NULL){
                    newnode -> data = l1Cur -> data;
                    if(l2Cur != NULL){
                        l2Cur -> next = newnode;
                        l2Cur = newnode;
                    }
                    else{
                        l2->first = newnode;
                        l2Cur = newnode;
                    }
                }

                l1Cur = l1Cur -> next;
            }

            l2Cur -> next = NULL;

            return l2;
        }
    }

    return NULL;
}


void *dllReturnL2Copy(DLList *l1, DLList *l2){
     if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL){

            DLNode *l1Cur = l1->first;
            DLNode *l2Cur = NULL;
            while(l1Cur != NULL){
                DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                if(newnode != NULL){
                    newnode -> data = l1Cur->data;
                    if(l2Cur != NULL){
                        l2Cur->next = newnode;
                        newnode->prev = l2Cur;
                        l2Cur = newnode;
                    }
                    else{
                        l2->first = newnode;
                        l2Cur = newnode;
                        l2Cur -> prev = NULL;
                    }
                }
                

                l1Cur = l1Cur -> next;
            }

            l2Cur -> next = NULL;

            return l2;
        }
    }

    return NULL;
}


void *csllReturnL2Copy(CSLList *l1, CSLList *l2){
    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL){

            CSLNode *l1Cur = l1->first;
            CSLNode *l2Cur = NULL;
            do{
                CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                if(newnode != NULL){
                    newnode -> data = l1Cur->data;
                    if(l2->first != NULL){
                        l2Cur->next = newnode;
                        l2Cur = newnode;
                    }
                    else{
                        l2->first = newnode;
                        l2Cur = newnode;
                    }
                }
                

                l1Cur = l1Cur -> next;
            }while(l1Cur != l1->first);

            l2Cur -> next = l2->first;

            return l2;
        }
    }

    return NULL;
}

void *cdllReturnL2Copy(CDLList *l1, CDLList *l2){
    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL){

            CDLNode *l1Cur = l1->first;
            CDLNode *l2Cur = NULL;
            do{
                CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                if(newnode != NULL){
                    newnode -> data = l1Cur->data;
                    if(l2->first != NULL){
                        l2Cur -> next = newnode;
                        newnode -> prev = l2Cur;
                        l2Cur = newnode;
                    }
                    else{
                        l2->first = newnode;
                        l2Cur = newnode;
                    }

                }

                l1Cur = l1Cur -> next;
            }while(l1Cur != l1->first);

            l2Cur -> next = l2->first;
            l2->first->prev = l2Cur;

            return l2;
        }
    }

    return NULL;
}

void *sllReturnDifference(SLList *l, SLList *l1, SLList *l2, int(*cmp)(void *, void *)){
    if(l1 != NULL && l2 != NULL && l != NULL){
        if(l1->first != NULL && l2->first != NULL){
            SLNode *l1Cur = l1->first;
            SLNode *l2Cur;
            SLNode *lCur = NULL;
            while(l1Cur != NULL){
                int alreadyExistesInL2 = FALSE;
                
                l2Cur = l2 -> first;

                while(l2Cur != NULL){
                    if(cmp(l1Cur -> data, l2Cur->data) == 0){
                        alreadyExistesInL2 = TRUE;
                        break;
                    }

                    l2Cur = l2Cur -> next; 
                }

                if(alreadyExistesInL2 == FALSE){
                    SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                    if(newnode != NULL){
                        newnode -> data = l1Cur->data;
                        if(l -> first != NULL){
                            lCur -> next = newnode;
                            lCur = newnode;
                        }
                        else{
                            l->first = newnode;
                            lCur = newnode;
                        }
                    }
                   
                }

                l1Cur = l1Cur -> next;

                
            }

            if(lCur != NULL){
                lCur -> next = NULL;
            }

            return l;
        }
    }

    return NULL;
}


void *dllReturnDifference(DLList *l, DLList *l1, DLList *l2, int(*cmp)(void *, void *)){
     if(l1 != NULL && l2 != NULL && l != NULL){
        if(l1->first != NULL && l2->first != NULL){
            DLNode *l1Cur = l1->first;
            DLNode *l2Cur;
            DLNode *lCur = NULL;
            while(l1Cur != NULL){
                int alreadyExistesInL2 = FALSE;
                
                l2Cur = l2 -> first;

                while(l2Cur != NULL){
                    if(cmp(l1Cur -> data, l2Cur->data) == 0){
                        alreadyExistesInL2 = TRUE;
                        break;
                    }

                    l2Cur = l2Cur -> next; 
                }

                if(alreadyExistesInL2 == FALSE){
                    DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
                    if(newnode != NULL){
                        newnode -> data = l1Cur->data;
                        if(l -> first != NULL){
                            lCur -> next = newnode;
                            newnode -> prev = lCur;
                            lCur = newnode;
                        }
                        else{
                            l->first = newnode;
                            newnode -> prev = NULL;
                            lCur = newnode;
                        }
                    }
                   
                }

                l1Cur = l1Cur -> next;

                
            }

            if(lCur != NULL){
                lCur -> next = NULL;
            }

            return l;
        }
    }

    return NULL;
}

void *csllReturnDifference(CSLList *l, CSLList *l1, CSLList *l2, int(*cmp)(void *, void *)){
    if(l1 != NULL && l2 != NULL && l != NULL){
        if(l1->first != NULL && l2->first != NULL){
            CSLNode *l1Cur = l1->first;
            CSLNode *l2Cur;
            CSLNode *lCur = NULL;
            do{
                int alreadyExistesInL2 = FALSE;
                
                l2Cur = l2 -> first;

                do{
                    if(cmp(l1Cur -> data, l2Cur->data) == 0){
                        alreadyExistesInL2 = TRUE;
                        break;
                    }

                    l2Cur = l2Cur -> next; 
                }while(l2Cur != l2->first);

                if(alreadyExistesInL2 == FALSE){
                    CSLNode *newnode = (CSLNode *)malloc(sizeof(CSLNode));
                    if(newnode != NULL){
                        newnode -> data = l1Cur->data;
                        if(l -> first != NULL){
                            lCur -> next = newnode;
                            lCur = newnode;
                        }
                        else{
                            l->first = newnode;
                            lCur = newnode;
                        }
                    }
                   
                }

                l1Cur = l1Cur -> next;

                
            }while(l1Cur != l1->first);

            if(lCur != NULL){
                lCur -> next = l->first;
            }

            return l;
        }
    }

    return NULL;
}

void *cdllReturnDifference(CDLList *l, CDLList *l1, CDLList *l2, int(*cmp)(void *, void *)){
    if(l1 != NULL && l2 != NULL && l != NULL){
        if(l1->first != NULL && l2->first != NULL){
            CDLNode *l1Cur = l1->first;
            CDLNode *l2Cur;
            CDLNode *lCur = NULL;
            do{
                int alreadyExistesInL2 = FALSE;
                
                l2Cur = l2 -> first;

                do{
                    if(cmp(l1Cur -> data, l2Cur->data) == 0){
                        alreadyExistesInL2 = TRUE;
                        break;
                    }

                    l2Cur = l2Cur -> next; 
                }while(l2Cur != l2->first);

                if(alreadyExistesInL2 == FALSE){
                    CDLNode *newnode = (CDLNode *)malloc(sizeof(CDLNode));
                    if(newnode != NULL){
                        newnode -> data = l1Cur->data;
                        if(l -> first != NULL){
                            lCur -> next = newnode;
                            newnode -> prev = lCur;
                            lCur = newnode;
                        }
                        else{
                            l->first = newnode;
                            lCur = newnode;
                        }
                    }
                   
                }

                l1Cur = l1Cur -> next;

                
            }while(l1Cur != l1->first);

            if(lCur != NULL){
                lCur -> next = l->first;
                l2->first->prev = lCur;
            }

            return l;
        }
    }

    return NULL;
}

int sllNumberEqualValue(SLList *l, SLList *k, int(*cmp)(void *, void *)){

    if(l != NULL && k != NULL){
        if(l->first != NULL && k -> first != NULL){
            SLNode *lCur = l->first;
            SLNode *kCur;
            SLList *auxList = sllcreate();
            SLNode *auxCur;
            int cont = 0;
            while(lCur!= NULL){
                kCur = k->first;
                while(kCur != NULL){
                    if(cmp(lCur -> data, kCur -> data) == 0){
                        auxCur = auxList->first;
                        int alreadyContaded = FALSE;
                        while(auxCur != NULL){
                            if(cmp(kCur -> data, auxCur->data) == 0){
                                alreadyContaded = TRUE;
                                break;
                            }

                            auxCur = auxCur -> next;
                        }

                        if(alreadyContaded == FALSE){
                            cont++;
                            sllInsertAsLast(auxList, kCur -> data);
                        }
                        break;
                    }

                    kCur = kCur -> next;
                }

                lCur = lCur -> next;
            }

            return cont;
        }
    }

    return 0;
}


int dllNumberEqualValue(DLList *l, DLList *k, int(*cmp)(void *, void *)){
     if(l != NULL && k != NULL){
        if(l->first != NULL && k -> first != NULL){
            DLNode *lCur = l->first;
            DLNode *kCur;
            DLList *auxList = dllcreate();
            DLNode *auxCur;
            int cont = 0;
            while(lCur!= NULL){
                kCur = k->first;
                while(kCur != NULL){
                    if(cmp(lCur -> data, kCur -> data) == 0){
                        auxCur = auxList->first;
                        int alreadyContaded = FALSE;
                        while(auxCur != NULL){
                            if(cmp(kCur -> data, auxCur->data) == 0){
                                alreadyContaded = TRUE;
                                break;
                            }

                            auxCur = auxCur -> next;
                        }

                        if(alreadyContaded == FALSE){
                            cont++;
                            dllInsertAsLast(auxList, kCur -> data);
                        }
                        break;
                    }

                    kCur = kCur -> next;
                }

                lCur = lCur -> next;
            }

            return cont;
        }
    }

    return 0;
}

int csllNumberEqualValue(CSLList *l, CSLList *k, int(*cmp)(void *, void *)){
     if(l != NULL && k != NULL){
        if(l->first != NULL && k -> first != NULL){
            CSLNode *lCur = l->first;
            CSLNode *kCur;
            CSLList *auxList = csllcreate();
            CSLNode *auxCur;
            int cont = 0;
            do{
                kCur = k->first;
                do{
                    if(cmp(lCur -> data, kCur -> data) == 0){
                        auxCur = auxList->first;
                        int alreadyContaded = FALSE;
                        do{
                            if(cmp(kCur -> data, auxCur->data) == 0){
                                alreadyContaded = TRUE;
                                break;
                            }

                            auxCur = auxCur -> next;
                        }while(auxCur != auxList -> first);

                        if(alreadyContaded == FALSE){
                            cont++;
                            csllInsertAsLast(auxList, kCur -> data);
                        }
                        break;
                    }

                    kCur = kCur -> next;
                }while(kCur != k->first);

                lCur = lCur -> next;
            }while(lCur!= l->first);

            return cont;
        }
    }

    return 0;
}


int cdllNumberEqualValue(CDLList *l, CDLList *k, int(*cmp)(void *, void *)){
    if(l != NULL && k != NULL){
        if(l->first != NULL && k -> first != NULL){
            CDLNode *lCur = l->first;
            CDLNode *kCur;
            CDLList *auxList = cdllcreate();
            CDLNode *auxCur;
            int cont = 0;
            do{
                kCur = k->first;
                do{
                    if(cmp(lCur -> data, kCur -> data) == 0){
                        auxCur = auxList->first;
                        int alreadyContaded = FALSE;
                        do{
                            if(cmp(kCur -> data, auxCur->data) == 0){
                                alreadyContaded = TRUE;
                                break;
                            }

                            auxCur = auxCur -> next;
                        }while(auxCur != auxList -> first);

                        if(alreadyContaded == FALSE){
                            cont++;
                            cdllInsertAsLast(auxList, kCur -> data);
                        }
                        break;
                    }

                    kCur = kCur -> next;
                }while(kCur != k->first);

                lCur = lCur -> next;
            }while(lCur!= l->first);

            return cont;
        }
    }

    return 0;
}

int sllRemoveEvenNodes(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int isEven = FALSE;
            SLNode *cur = l->first;
            SLNode *prev = cur;
            SLNode *aux;
            while(cur != NULL){
                if(isEven){
                    aux = cur;
                    prev -> next = cur -> next;
                    free(cur);
                    cur = aux;
                    isEven = FALSE;
                    
                }
                else{
                    isEven = TRUE;
                    prev = cur;
                }
                
                cur = cur -> next;

            }

            return TRUE;
        }
    }

    return FALSE;
}


int dllRemoveEvenNodes(DLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int isEven = FALSE;
            DLNode *cur = l->first;
            DLNode *prev = cur;
            DLNode *aux;
            while(cur != NULL){
                if(isEven){
                    DLNode *aux = cur->next;
                    free(cur);
                    prev->next = aux;
                    if(aux != NULL){
                        aux -> prev = prev;
                    }
                    cur = aux;
                    isEven = FALSE;
                    
                }
                else{
                    isEven = TRUE;
                    prev = cur;
                    cur = cur -> next;
                }
                
                

            }

            return TRUE;
        }
    }

    return FALSE;
}

int csllRemoveEvenNodes(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int isEven = FALSE;
            CSLNode *cur = l->first;
            CSLNode *prev = cur;
            CSLNode *aux;
            do{
                if(isEven){
                    aux = cur;
                    prev -> next = cur -> next;
                    free(cur);
                    cur = aux;
                    isEven = FALSE;
                    
                }
                else{
                    isEven = TRUE;
                    prev = cur;
                }
                
                cur = cur -> next;

            }while(cur != l->first);

            return TRUE;
        }
    }

    return FALSE;
}

int cdllRemoveEvenNodes(CDLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int isEven = FALSE;
            CDLNode *cur = l->first;
            CDLNode *prev = cur;
            do{
                if(isEven){
                    CDLNode *aux = cur->next;
                    free(cur);
                    prev->next = aux;
                    aux -> prev = prev;
                    cur = aux;
                    isEven = FALSE;
                    
                }
                else{
                    isEven = TRUE;
                    prev = cur;
                    cur = cur -> next;
                }
                
                

            }while(cur != l->first);

            return TRUE;
        }
    }

    return FALSE;
}



int sllRemoveOddNodes(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int isOdd = TRUE;
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            while(cur != NULL){ 
                if(isOdd){
                    SLNode *aux = cur -> next;
                    free(cur);
                    if(prev == NULL){
                        l->first = aux;
                    }
                    else{
                        prev -> next = aux;
                    }

                    cur = aux;
                    isOdd = FALSE;
                }
                else{
                    prev = cur;
                    cur = cur -> next;

                    isOdd = TRUE;
                }

               
            }

            return TRUE;
        }
    }

    return FALSE;
}


int dllRemoveOddNodes(DLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int isOdd = TRUE;
            DLNode *cur = l->first;
            DLNode *prev = NULL;

            while(cur != NULL){
                if(isOdd){
                    DLNode *aux = cur -> next;
                    free(cur);
                    if(prev == NULL){
                        l->first = aux;
                        if(aux != NULL){
                            aux->prev = NULL;
                        }
                    }
                    else{
                        prev->next = aux;

                        if(aux != NULL){
                            aux->prev = prev;
                        }
                       
                    }

                    cur = aux;
                    isOdd = FALSE;
                }
                else{
                    prev = cur;
                    cur = cur -> next;
                    isOdd = TRUE;
                }
            }

            return TRUE;
        }
    }

    return FALSE;
}


int csllRemoveOddNodes(CSLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int isOdd = TRUE;
            CSLNode *cur = l->first;
            CSLNode *prev = NULL;

            do{
                if(isOdd){
                    CSLNode *aux = cur -> next;
                    free(cur);
                    if(prev == NULL){
                        if(aux == l->first){
                            l->first = NULL;
                        }
                        else{
                            l->first = aux;

                            //tenho que achar o ultimo elemento e faze-lo apontar para o proximo do primeiro

                            SLNode *auxCur = l->first;
                            while(auxCur -> next != l->first){
                                auxCur = auxCur -> next;
                            }

                            auxCur -> next = aux;
                        }
                    
                    }

                    else{
                        prev -> next = aux;
                    }
                    
                    cur = aux;
                    isOdd = FALSE;
                }
                else{

                    prev = cur;
                    cur = cur -> next;

                    isOdd = TRUE;
                    
                }
            }while(cur != l->first);

            return TRUE;
        }
    }

    return FALSE;
}

int cdllRemoveOddNodes(CDLList *l){
    if(l != NULL){
        if(l->first != NULL){
            int isOdd = TRUE;
            CDLNode *cur = l->first;
            CDLNode *prev = NULL;
            do{
                if(isOdd){
                    CDLNode *aux = cur -> next;
                    if(prev == NULL){
                        if(aux == l->first){
                            l->first = NULL;
                        }
                        else{
                            cur -> prev -> next = aux;
                            l->first = aux;
                        }  
                    }
                    else{
                        prev -> next = aux;
                        aux -> prev = prev;
                    }

                    free(cur);
                    cur = aux;
                    isOdd = FALSE;

                }
                else{
                    prev = cur;
                    cur = cur -> next;
                    isOdd = TRUE;
                }
                
            }while(cur != l->first);
            
            return TRUE;
        }
    }

    return FALSE;
}


int sllSplitListInOddsAndEvens(SLList *l, SLList *l1, SLList *l2){
    if(l != NULL && l1 != NULL && l2 != NULL){
        if(l->first != NULL){
            SLNode *cur = l->first;
            int inList1 = TRUE;
            SLNode *lastl1 = NULL;
            SLNode *lastl2 = NULL;
            while(cur != NULL){
                if(inList1){
                    if(l1 -> first == NULL){
                        l1->first = cur;
                        lastl1 = cur;
                    }
                    else{
                        lastl1 -> next = cur;
                        lastl1 = cur;
                    }
                    inList1 = FALSE;
                }
                else{
                    if(l2->first == NULL){
                        l2->first = cur;
                        lastl2 = cur;
                    }
                    else{
                        lastl2->next = cur;
                        lastl2 = cur;
                    }

                    inList1 = FALSE;
                }
                

                cur = cur -> next;
            }

            lastl1->next = NULL;
            lastl2->next = NULL;

            l->first = NULL;
            return TRUE;
        }
    }

    return FALSE;
}

int dllSplitListInOddsAndEvens(DLList *l, DLList *l1, DLList *l2){
    if(l != NULL && l1 != NULL && l2 != NULL){
        if(l -> first != NULL){
            DLNode *cur = l->first;
            int inList1 = TRUE;
            DLNode *prevl1 = NULL;
            DLNode *prevl2 = NULL;
            while(cur != NULL){
                if(inList1){
                    if(l1->first == NULL){
                        l1->first = cur;
                        l1->first->prev = NULL;
                        prevl1 = cur;
                    }
                    else{
                        prevl1 -> next = cur;
                        cur -> prev = prevl1;
                        prevl1 = cur;
                    }

                    inList1 = FALSE;
                }
                else{
                    if(l2->first == NULL){
                        l2->first = cur;
                        l2->first->prev = NULL;
                        prevl2 = cur;
                    }
                    else{
                        prevl2 -> next = cur;
                        cur -> prev = prevl2;
                        prevl2 = cur;
                    }

                    inList1 = TRUE;
                }
            }

            prevl1->next = NULL;
            prevl2->next = NULL;
            l->first = NULL;
            return TRUE;
        }
    }

    return FALSE;
}

int csllSplitListInOddsAndEvens(CSLList *l, CSLList *l1, CSLList *l2){
    if(l != NULL && l1 != NULL && l2 != NULL){
        if(l -> first != NULL){
            CSLNode *cur = l->first;
            int inList1 = TRUE;
            CSLNode *prevl1 = NULL;
            CSLNode *prevl2 = NULL;

            do{
                if(inList1){
                    if(l1 -> first == NULL){
                        l1->first = cur;
                        prevl1 = cur;

                    }
                    else{
                        prevl1->next = cur;
                        prevl1 = cur;
                    }

                    inList1 = FALSE;
                }
                else{   
                    if(l2 -> first == NULL){
                        l2->first = cur;
                        prevl2 = cur;
                    }
                    else{
                        prevl2->next = cur;
                        prevl2 = cur;
                    }

                    inList1 = TRUE;
                }

                cur = cur -> next;
            }while(cur != l->first);

            prevl1->next = l1->first;
            prevl2->next = l2->first;
            l->first = NULL;
            return TRUE;
        }
    }

    return FALSE;
}

int cdllSplitListInOddsAndEvens(CDLList *l, CDLList *l1, CDLList *l2){
    if(l != NULL && l1 != NULL && l2 != NULL){
        if(l -> first != NULL){
            CDLNode *cur = l->first;
            int inList1 = TRUE;
            CDLNode *prevl1 = NULL;
            CDLNode *prevl2 = NULL;
            do{
                if(inList1){
                    if(l1->first == NULL){
                        l1->first = cur;
                        prevl1 = cur;
                    }
                    else{
                        prevl1->next = cur;
                        cur -> prev = prevl1;
                        prevl1 = cur;
                    }

                    inList1 = FALSE;
                }
                else{
                    if(l2 -> first == NULL){
                        l2->first = cur;
                        prevl2 = cur;
                    }
                    else{
                        prevl2->next = cur;
                        cur -> prev = prevl2;
                        prevl2 = cur;
                    }

                    inList1 = TRUE;
                }

                cur = cur -> next;

            }while(cur != l->first);

            if(prevl1 != NULL){
                prevl1 -> next = l1 -> first;
                l1->first->prev = prevl1;
            }

            if(prevl2 != NULL){
                prevl2 -> next = l2 -> first;
                l2->first->prev = prevl2;
            }

            l->first = NULL;

            return TRUE;

        }
    }

    return FALSE;
}

int sllSwitchKeys(SLList *l, void *key1, void *key2, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            if(cmp(key1, key2) != 0){
                SLNode *curKey1 = l->first;
                SLNode *prevKey1 = NULL;
                while(curKey1 != NULL){
                    if(cmp(curKey1->data, key1) == 0){
                        break;
                    }
                    prevKey1 = curKey1;
                    curKey1 = curKey1 -> next;
                }

                SLNode *curKey2 = l->first;
                SLNode *prevKey2 = NULL;
                while(curKey2 != NULL){
                    if(cmp(curKey2->data, key2) == 0){
                        break;
                    }

                    prevKey2 = curKey2;
                    curKey2 = curKey2 -> next;
                }

                if(curKey1 != NULL && curKey2 != NULL){

                    if(prevKey1 != NULL){
                        prevKey1->next = curKey2;
                    }
                    else{
                        l->first = curKey2;
                    }

                    if(prevKey2 != NULL){
                        prevKey2 -> next = curKey1;
                    }
                    else{
                        l->first = curKey1;
                    }

                    SLNode *temp = curKey1->next;
                    curKey1->next = curKey2->next;
                    curKey2->next = temp;

                    return TRUE;
                }


            }   
            
        }
    }

    return FALSE;
}

int dllSwitchKeys(DLList *l, void *key1, void *key2, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            if(cmp(key1, key2) != 0){
               
                DLNode *curKey1 = l->first;
                while(curKey1 != NULL){
                    if(cmp(curKey1->data, key1) == 0){
                        break;
                    }
                    curKey1 = curKey1 -> next;
                }

                DLNode *curKey2 = l->first;

                while(curKey2 != NULL){
                    if(cmp(curKey2->data, key2) == 0){
                        break;
                    }
                    curKey2 = curKey2->next;
                }

                if(curKey1 != NULL && curKey2 != NULL){

                    if(curKey1 == l->first){
                        l->first = curKey2;
                    }
                    else if(curKey2 == l->first){
                        l->first = curKey1;
                    }

                    DLNode *temp = curKey1->next;
                    curKey1->next = curKey2->next;
                    curKey2->next = temp;

                    if(curKey2->next != NULL){
                        curKey2->next->prev = curKey2;
                    }

                    if(curKey1->next != NULL){
                        curKey1->next->prev = curKey1;
                    }

                    temp = curKey1->prev;
                    curKey1->prev = curKey2->prev;
                    curKey2->prev = temp;

                    if(curKey1->prev != NULL){
                        curKey1->prev->next = curKey1;
                    }

                    if(curKey2->prev != NULL){
                        curKey2->prev->next = curKey2;
                    }

                    return TRUE;


                }


            }   
            
        }
    }

    return FALSE;
}

int csllSwitchKeys(CSLList *l, void *key1, void *key2, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            if(cmp(key1, key2) != 0){
                CSLNode *curKey1 = l->first;
                CSLNode *prevKey1 = NULL;
                do{
                    if(cmp(curKey1->data, key1) == 0){
                        break;
                    }
                    prevKey1 = curKey1;
                    curKey1 = curKey1 -> next;
                } while(curKey1 != l->first);

                CSLNode *curKey2 = l->first;
                CSLNode *prevKey2 = NULL;
                do{
                    if(cmp(curKey2->data, key2) == 0){
                        break;
                    }

                    prevKey2 = curKey2;
                    curKey2 = curKey2 -> next;
                }while(curKey2 != l->first);

                if(curKey1 != NULL && curKey2 != NULL){

                    if(curKey1->next == curKey2){
                        curKey1->next = curKey2->next;
                        curKey2->next = curKey1;

                        if(prevKey1 != NULL){
                            prevKey1 -> next = curKey2;
                        }
                    }

                    else if(curKey2 -> next == curKey1){
                        curKey2->next = curKey1->next;
                        curKey1->next = curKey2;
                        if(prevKey2 != NULL){
                            prevKey2->next = curKey1;
                        }

                    }


                    else{

                        if(prevKey2 != NULL){
                            prevKey2 -> next = curKey1;
                        }
                        

                        if(prevKey1 != NULL){
                            prevKey1->next = curKey2;
                        }

                        CSLNode *temp = curKey1->next;
                        curKey1->next = curKey2->next;
                        curKey2->next = temp;





                    }
                    

                    if(prevKey1 == NULL){
                        l->first = curKey2;
                    }

                    if(prevKey2 == NULL){
                        l->first = curKey1;
                    }

                    return TRUE;
                }


            }   
            
        }
    }

    return FALSE;
}




int cdllSwitchKeys(CDLList *l, void *key1, void *key2, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            if(cmp(key1, key2) != 0){
               
                CDLNode *curKey1 = l->first;
                do{
                    if(cmp(curKey1->data, key1) == 0){
                        break;
                    }
                    curKey1 = curKey1 -> next;
                }while(curKey1 != l->first);

                CDLNode *curKey2 = l->first;

                do{
                    if(cmp(curKey2->data, key2) == 0){
                        break;
                    }
                    curKey2 = curKey2->next;
                }while(curKey2 != l->first);

                if(curKey1 != NULL && curKey2 != NULL){

                    CDLNode *temp = curKey1->next;
                    curKey1->next = curKey2->next;
                    curKey2->next = temp;

                    curKey1->next->prev = curKey1;
                    curKey2->next->prev = curKey2;

                    temp = curKey1->prev;
                    curKey1->prev = curKey2->prev;
                    curKey2->prev = temp;

                    curKey1->prev->next = curKey1;
                    curKey2->prev->next = curKey2;

                   
                    if (curKey1 == l->first) {
                        l->first = curKey2;
                    } 
                    else if (curKey2 == l->first) {
                        l->first = curKey1;
                    }

                    return TRUE;


                }


            }   
            
        }
    }

    return FALSE;
}


//questão 1 prova 2022.1

int ÉInversa(CDLList *l1, CDLList *l2){
    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL && l2->first != NULL){

            //primeiro vou achar o último elemento de l2

            CDLNode *lastl2 = l2->first;
            while(lastl2 -> next != l2->first){
                lastl2 = lastl2 -> next;
            }

            //agora devo comparar o primeiro de l1 com o ultimo de l2, segundo de l1 com penultimo de l2 e assim por diante
            
            CDLNode *curl1 = l1->first;
            CDLNode *curl2 = lastl2;
            do{
                if(curl1 -> data != curl2->data){
                    return -1;
                }

                curl1 = curl1 -> next;
                curl2 = curl2 -> prev;

            }while(curl1 != l1->first && curl2 != lastl2);

            if(curl1 == l1->first && curl2 == lastl2){
                return 1;
            }

            else if(curl1 == l1->first && curl2 != lastl2){
                return -1;
            }

            else{
                return 0;
            }
        }
    }
}


//questao 2 da prova 2022.1
void PegaElementosIguais(DLList *l1, DLList *l2, DLList *l3){
    if(l1 != NULL && l2 != NULL && l3 != NULL){
        if(l1->first != NULL && l2->first != NULL){

            DLNode *curl1 = l1->first;
            DLNode *lastl3 = NULL;
            while(curl1 != NULL){
                DLNode *curl2 = l2->first;
                while(curl2 != NULL){
                    if(curl1->data == curl2->data){
                        if(l3 -> first != NULL){
                            lastl3->next = curl1;
                            curl1 -> prev = lastl3;
                            lastl3 = curl1;
                        }
                        else{
                            l3->first = curl1;
                            curl1->prev = NULL;
                            lastl3 = curl1;
                        }
                    }

                    curl2 = curl2 -> next;
                }

                curl1 = curl1 -> next;
            }

            if(lastl3 != NULL){
                lastl3->next = NULL;
            }
            
        }
    }
}



//questao 1 da prova 2017.1
SLList *sllCumulativeSum(SLList *l1, int(*getValue)(void *)){
    if(l1 != NULL){
        if(l1->first != NULL){
            int soma = 0;
            SLList *newlist = sllcreate();
            if(newlist != NULL){
                SLNode *cur = l1->first;
                while(cur != NULL){
                    soma += getvalue(cur->data);
                    sllInsertAsLast(newlist, soma);

                    cur = cur -> next;
                }

                return newlist;
            }
        }
    }

    return NULL;
}

void *PegaElementosIguais(DLList *l1, DLList *l2, DLList *l3){
    if(l1 != NULL && l2  != NULL && l3 != NULL){
        if(l1->first != NULL && l2->first != NULL){

            DLNode *curl1 = l1->first;
            while(curl1 != NULL){
                DLNode *curl2 = l2->first;
                DLNode *lastl3 = NULL;
                DLNode *nextl1 = curl1->next;
                while(curl2 != NULL){
                    DLNode *nextl2 = curl2 -> next;
                    if(curl1->data == curl2->data){
                       //tenho que ver se já tem em l3

                        SLNode *curl3 = l3->first;
                        int jaTem = FALSE;
                        while(curl3 != NULL){
                            if(curl3->data == curl1->data){
                                jaTem = TRUE;
                                break;
                            }

                            curl3 = curl3 -> next;
                        }

                        if(jaTem == FALSE){

                            void *data = dllRemoveByKey(l1, curl1->data, funcaoComparacao);
                            void *data2 = dllRemoveByKey(l2, curl2->data, funcaoComparacao);
                            dllInsertAsLast(l3, data);

                        
                            /*curl1->prev->next = nextl1;
                            curl2->prev->next = nextl2;
                            nextl1->prev = curl1->prev;
                            nextl2->prev = curl2->prev;

                            free(curl1);
                            free(curl2);*/


                        }
                        

                    }
                    curl2 = nextl2;
                }

                curl1 = nextl1;
            }


        }
    }
}


int funcaoComparacao(){
    return 0;
}

int removeOCaraEOsVizinhos(CDLList *l, void *key, int(*cmp)(void *, void*)){
    if(l == NULL || l->first == NULL){
        return FALSE;
    }

    // Calculate the length of the list
    int contador = 0;
    CDLNode *spec = l->first;
    do {
        spec = spec->next;
        contador++;
    } while(spec != l->first);

    // If list has 3 or fewer nodes, clear it
    if(contador <= 3){
        CDLNode *temp;
        while (l->first != NULL) {
            temp = l->first;
            l->first = l->first->next;
            free(temp);
            if (l->first == spec) { // Break if we have come full circle
                break;
            }
        }
        l->first = NULL;
        return TRUE;
    }

    // Find the target node
    CDLNode *cur = l->first;
    do {
        if(cmp(cur->data, key) == 0){
            break;
        }
        cur = cur->next;
    } while(cur != l->first);

    // If key not found
    if(cur == l->first && cmp(cur->data, key) != 0){
        return FALSE;
    }

    // Remove the target node and its neighbors
    CDLNode *prevNode = cur->prev;
    CDLNode *nextNode = cur->next;

    prevNode->prev->next = nextNode->next;
    nextNode->next->prev = prevNode->prev;

    if (l->first == cur || l->first == prevNode || l->first == nextNode) {
        l->first = nextNode->next;
    }

    free(prevNode);
    free(nextNode);
    free(cur);

    return TRUE;
}

void *sllInverter(SLList *l){
    if(l != NULL){
        if(l->first != NULL){

            SLNode *cur = l->first;
            SLNode *prev = NULL;
            SLNode *aux = NULL;
            while(cur != NULL){
                aux = cur -> next;
                cur -> next = prev;
                prev = cur;
                l->first = cur;
                cur = aux;
            }
        }
    }
}


void *dllInverter(DLList *l){
    if(l != NULL){
        if(l->first != NULL){

            DLNode *cur = l->first;
            DLNode *aux = NULL;
            DLNode *prev = NULL;
            while(cur != NULL){

                aux = cur->next;
                cur -> prev = NULL;
                cur -> next = prev;
                if(prev != NULL){
                    prev->prev = cur;
                }
                prev = cur;
                l->first = cur;
                cur = aux;

            }
        }
    }
}


void *intercalarDuasListas(CSLList *l1, CSLList *l2){
    if(l1 != NULL && l2 != NULL){
        if(l1 -> first != NULL && l2 -> first != NULL){
            CSLNode *curl1 = l1->first;
            CSLNode *curl2 = l2->first;
            CSLNode *nextCurl1 = curl1->next;
            CSLNode *nextCurl2 = curl2->next;

            while(nextCurl1 != l1->first && nextCurl2 != l2->first){
                curl1->next = curl2;
                curl2->next = nextCurl1;
                
                curl1 = nextCurl1;
                curl2 = nextCurl2;
                nextCurl1 = curl1->next;
                nextCurl2 = curl2->next;
            }

            
            if (nextCurl1 == l1->first) {
                curl1->next = curl2;
                while(curl2->next != l2->first){
                    curl2 = curl2->next;
                }
                curl2->next = l1->first;
            } else {
                curl2->next = nextCurl1;
            }
        
        }
    }
}


int eliminarOrdemImpar(SLList *l){
    if(l != NULL){
        if(l->first != NULL){
            SLNode *cur = l->first;
            SLNode *prev = NULL;
            int ehOrdemImpar = TRUE;

            while(cur != NULL){
                if(ehOrdemImpar){
                    if(prev != NULL){
                        SLNode *aux = cur->next;
                        prev->next = cur -> next;
                        cur = aux;
                    }
                    else{
                        l->first = cur->next;
                        cur = cur -> next;
                    }

                    ehOrdemImpar = FALSE;
                }

                else{
                    prev = cur;
                    cur = cur -> next;
                    ehOrdemImpar = TRUE;
                }
            }

            return TRUE;
        }
    }

    return FALSE;
}






