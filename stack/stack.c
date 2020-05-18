#include <stdlib.h>
#include <stdio.h>

typedef struct NODE{
    int val;
    struct NODE* next;
}llNode;

void push(llNode * head, int val){
    llNode * newNode = malloc(sizeof(llNode));
    newNode->val = val;
    newNode->next = head->next;
    head->next = newNode;
}

int pop(llNode * head){
    if(head->next == NULL) return -1;
    llNode * tempNode = head->next;
    int returnVal = tempNode->val;

    head->next = head->next->next;
    free(tempNode);
    return returnVal;
}


int main()
{
    llNode * head = malloc(sizeof(llNode));
    head->next = NULL;
    printf("%d\n",pop(head));
    push(head,1);
    push(head,2);
    push(head,3);
    printf("%d\n",pop(head));
    printf("%d\n",pop(head));
    push(head,4);
    printf("%d\n",pop(head));
}