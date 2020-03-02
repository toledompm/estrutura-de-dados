#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int val;
    struct node * next;
}llNode;

void push(int val, llNode * h)
{
    llNode * newNode = malloc(sizeof(llNode));
    newNode->val = val;
    newNode->next = h->next;
    h->next = newNode;
}

int pop(llNode * h)
{
    llNode * tempNode = h->next;
    int popedVal = tempNode->val;
    h->next = tempNode->next;
    free(tempNode);
    return popedVal;
}

void display(llNode * h)
{
    llNode * curNode = h->next;
    printf("list: ");
    while(curNode)
    {
        printf("%d ",curNode->val);
        curNode = curNode->next;
    }
    printf("\n");
    free(curNode);
}

int removeByIndex(llNode * h, int index)
{
    if(index == 0) return pop(h);
    llNode * cur = h;
    
    for(int i=0;i<index;i++)
    {
        if(cur == NULL) return -1;
        cur = cur->next;
    }

    llNode * removedNode = cur->next;
    int removedVal = removedNode->val;
    cur->next = removedNode->next;
    free(removedNode);
    return removedVal;
}

int main()
{
    llNode * header = malloc(sizeof(llNode));
    header->next = NULL;

    push(2,header);
    display(header);
    push(3,header);
    display(header);
    push(4,header);
    display(header);
    printf("removed val: %d\n",removeByIndex(header,1));
    display(header);
    push(5,header);
    display(header);
    push(6,header);
    display(header);
    printf("poped val: %d\n",pop(header));
}