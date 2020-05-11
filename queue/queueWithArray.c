#include <stdlib.h>
#include <stdio.h>

typedef struct q{
    int first;
    int last;
    int *list;
} Queue;

int getListSize(int** lst)
{
    return sizeof(*lst)/sizeof(int);
}

int getQueueSize(Queue q)
{
    int qSize;

    if(q.first>q.last)
    {
        return getListSize(&q.list) - q.first + q.last;
    }
    return q.last-q.first;
}

//returns 0 for overflown, 1 for valid, 2 for empty
char* checkQueueStatus(Queue q)
{
    if (q.first == q.last) return "empty";
    if (getQueueSize(q) == getListSize(&q.list)) return "overflown";
    return "valid";
}

int realocQueue(Queue q)
{
    int listSizeInBytes = sizeof(q.list);
    int * newList = malloc(listSizeInBytes*2);

    for(int index = 0, qIndex = q.first;qIndex!=q.last;qIndex++,index++)
    {
        newList[index] = q.list[qIndex];
        if(qIndex == getListSize(&q.list)-1) qIndex = -1;
    }
}

void display(Queue q)
{
    for(int i=q.first;i!=q.last;i++)
    {
        printf("%d ",q.list[i]);
        if(i==getListSize(&q.list)-1) i = -1;
    }
    printf("\n");
}

void push(Queue q, int val)
{

}

int main()
{
    Queue q;
    int n = 5;
    q.list = malloc(5 * sizeof(int));
    q.first = -1;
    q.last = -1;

    printf("%s\n",checkQueueStatus(q));
    q.list[q.last++] = 1;
    display(q);
    printf("%s\n",checkQueueStatus(q));
    q.list[q.last++] = 2;
    q.list[q.last++] = 3;
    q.list[q.last++] = 4;
    q.list[q.last++] = 5;
    q.first++;
    display(q);
    printf("%s\n",checkQueueStatus(q));



}