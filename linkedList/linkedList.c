#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val;
    struct node * next;
} llNode;

void push(llNode** h, int data)
{
    llNode * newNode = malloc(sizeof(newNode));
    newNode->val = data;
    newNode->next = *h;
    *h = newNode;
}

int pop(llNode** h)
{
    int returnVal = (*h)->val;
    *h = (*h)->next;
    return returnVal;
}

int removeindex(llNode** h, int index)
{
    llNode * cur = *h;
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
    llNode * h = malloc(sizeof(llNode));
    scanf("%d",&v);

    h->val=v;
    h->next=NULL;

    while(option != 0)
    {
        printf("header val -> %d\n",h->val);
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            scanf("%d",&v);
            push(&h,v);
            break;
        case 2:
            printf("poped val: %d\n",pop(&h));
            break;
        case 3:
            scanf("%d",&v);
            printf("removed val: %d\n",removeindex(&h,v));
        default:
            break;
        }
    }
}