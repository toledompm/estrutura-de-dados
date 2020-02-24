#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val;
    struct node * next;
} llNode;

void push(llNode** s, int data)
{
    llNode * newNode = malloc(sizeof(newNode));
    newNode->val = data;
    newNode->next = *s;
    *s = newNode;
}

int pop(llNode** s)
{
    int returnVal = (*s)->val;
    *s = (*s)->next;
    return returnVal;
}

int removeindex(llNode** s, int index)
{
    llNode * cur = *s;
    for(int i=1;i<index-1;i++)
    {
        cur = cur->next;
    }
    int returnVal = cur->next->val;
    cur->next=cur->next->next;
    return returnVal;
}

int main()
{
    int v, option = 1;
    llNode * s = malloc(sizeof(llNode));
    scanf("%d",&v);

    s->val=v;
    s->next=NULL;

    while(option != 0)
    {
        printf("first node val -> %d\n",s->val);
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            scanf("%d",&v);
            push(&s,v);
            break;
        case 2:
            printf("poped val: %d\n",pop(&s));
            break;
        case 3:
            scanf("%d",&v);
            printf("removed val: %d\n",removeindex(&s,v));
        default:
            break;
        }
    }
}