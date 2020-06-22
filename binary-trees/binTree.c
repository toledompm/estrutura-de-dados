#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int data;
    struct cel *left;
    struct cel *right;
}tree;


void Erd (tree * right){
    if(right!=NULL){
        Erd(right->left);
        printf("%d\n",right->data);
        Erd(right->right);
    }
}

main(){
    tree *t;

}