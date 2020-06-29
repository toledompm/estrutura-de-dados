#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int key;
    struct cel *left;
    struct cel *right;
}knot;

knot * createKnot(int key){
    knot * newKnot = malloc(sizeof(knot));
    newKnot->key = key;
    newKnot->right = newKnot->left = NULL;

    return newKnot;
}

knot * insert(knot * root, knot * newKnot){
    if(root == NULL) return newKnot;
    
    if(newKnot->key < root->key) root->left = insert(root->left,newKnot);
    else if(newKnot->key > root->key) root->right = insert(root->right,newKnot);

    return root;
}

knot * search(knot * root, int key){
    if(root == NULL || root->key == key) return root;
    if(key > root->key) search(root->right,key);
    else if(key < root->key) search(root->left,key);
}

knot * getMinimumKnot(knot * k){
    if(k->left != NULL) return getMinimumKnot(k->left);
    return k;
}

void delete(knot * k){
    if(k->right == NULL && k->left == NULL){
        free(k);
    }else if(k->left == NULL && k->right != NULL){
        k->key = k->right->key;
        delete(k->right);
    }else if(k->right == NULL && k->left != NULL){
        k->key = k->left->key;
        delete(k->left);
    }else{
        k->key = getMinimumKnot(k->right)->key;
        delete(getMinimumKnot(k->right));
    }
}

void sweepLeftRootRight (knot * root){
    if(root!=NULL){
        sweepLeftRootRight(root->left);
        printf("%d\n",root->key);
        sweepLeftRootRight(root->right);
    }
}

int main(){
    knot * root = createKnot(12);

    insert(root,createKnot(5));
    insert(root,createKnot(3));
    insert(root,createKnot(1));
    insert(root,createKnot(7));
    insert(root,createKnot(9));
    insert(root,createKnot(8));
    insert(root,createKnot(11));
    insert(root,createKnot(17));
    insert(root,createKnot(13));
    insert(root,createKnot(14));
    insert(root,createKnot(20));
    insert(root,createKnot(18));

    printf("%d\n",search(root,17)->key);
    delete(search(root,17));
    printf("There should be an error after this:\n");
    printf("%d\n",search(root,17)->key);
}