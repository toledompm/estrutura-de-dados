#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int data;
    struct cel *left;
    struct cel *right;
}tree;

void sweepLeftRootRight (tree * root){
    if(root!=NULL){
        sweepLeftRootRight(root->left);
        printf("%d\n",root->data);
        sweepLeftRootRight(root->right);
    }
}

tree * createKnot(int data){
    tree * newKnot = malloc(sizeof(tree));
    newKnot->data = data;
    newKnot->left = newKnot->right = NULL;

    return newKnot;
}

void insert(tree ** root, tree * knot, int orientation){
    if(orientation == 1) (*root)->right = knot;
    else (*root)->left = knot;
}

int main(){
    tree * t = createKnot(1);

    printf("First Sweep\n");
    sweepLeftRootRight(t);
    
    tree * firstKnot = createKnot(2);
    insert(&t,firstKnot,1);

    printf("Second Sweep\n");
    sweepLeftRootRight(t);
}