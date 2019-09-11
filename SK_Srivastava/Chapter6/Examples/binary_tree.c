#include <stdio.h>
// #include <stdlib.h>
struct node {
    struct node *lchild;
    char data;
    struct node *rchild;
};

/*recursive functions for traversal */
void preorder(struct node *ptr)
{
    if(ptr == NULL)
        return;
    printf("%d ", ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(struct node *ptr)
{
    if(ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d ", ptr->data);
    inorder(ptr->rchild);
}

void postorder(struct node *ptr)
{
    if(ptr == NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ", ptr->data);
}