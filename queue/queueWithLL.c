#include <stdlib.h>
#include <stdio.h>

typedef struct NODE{
    int val;
    struct NODE* next;
}llNode;

typedef struct QUEUE{
    llNode * first;
    llNode * last;
}queue;

int isQueueEmpty(queue * q){
    return (q->last == NULL);
}

void insertIntoQueue(queue * q, int v)
{
    llNode * newNode = malloc(sizeof(llNode));
    newNode->val = v;
    newNode->next = NULL;

    if(isQueueEmpty(q)){
        q->first = q->last = newNode;
        return;
    }
    
    q->last->next = newNode;
    q->last = newNode;
}

void removeFromQueue(queue * q)
{
    if(isQueueEmpty(q)) return;
    q->first = q->first->next;
}

void display(llNode * f)
{
    for(llNode * cur = f;
        cur!=NULL;
        cur=cur->next)
    {
        printf("%d ",cur->val);
    }
    printf("\n");
}

int main()
{
    queue * q = malloc(sizeof(queue));
    q->first = NULL;
    q->last = NULL;

    insertIntoQueue(q,1);
    display(q->first);
    insertIntoQueue(q,2);
    insertIntoQueue(q,3);
    display(q->first);
    insertIntoQueue(q,1);
    insertIntoQueue(q,1);
    display(q->first);
    removeFromQueue(q);
    removeFromQueue(q);
    display(q->first);
    insertIntoQueue(q,3);
    display(q->first);
}