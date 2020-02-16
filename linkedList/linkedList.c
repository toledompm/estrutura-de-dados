#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val;
    struct node * next;
} llNode;


int getLast(llNode * header)
{
    llNode * cur = header;
    while(cur->next!=NULL)
    {
        cur = cur->next;
    } 
    return cur->val;
}

int get(llNode * header, int v)
{
    llNode * cur = header;
    for(int i=0;i<v;i++)
    {
        if(cur->next==NULL) return 0;
        cur = cur->next;
    }
    return cur->val;
}

void pushEnd(llNode * header, int v)
{
    llNode * pNode = malloc(sizeof(llNode));
    pNode->val = v;
    pNode->next = NULL;
    while(header->next!=NULL) header = header->next;
    header->next = pNode;
}

llNode * pushBeg(llNode * header, int v)
{
    llNode * pNode = malloc(sizeof(llNode));
    pNode->val = v;
    pNode->next = header;
    return pNode;
}

void pop(llNode * header)
{
    llNode * cur = header;
    while(cur->next->next!=NULL)cur = cur->next;
    cur->next = NULL;
}

void popIndex(llNode * header,int index)
{
    llNode * cur = header;
    for(int i=0;i<index-1;i++)
    {
        cur = cur->next;
    }
    cur->next = cur->next->next;
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
            h = pushBeg(h,v);
            break;
        case 2:
            scanf("%d",&v);
            pushEnd(h,v);
            break;
        case 3:
            printf("Last Val -> %d\n",getLast(h));
            break;
        case 4:
            scanf("%d",&v);
            printf("Val at: %d -> %d\n",v,get(h,v));
        case 5:
            scanf("%d",&v);
            popIndex(h,v);
        case 6:
            pop(h);    
        default:
            break;
        }
    }
}