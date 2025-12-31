#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node* left;
    struct node* right;
};

void preorder(struct node* root) {

    if(root != NULL) {
        printf( root -> data);
        preorder(root -> left);
        preorder(root -> left);
    }
}

int main() {

    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    return 0;
}