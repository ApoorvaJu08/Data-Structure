#include <stdio.h>
#define MAX 50
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

/*Non-recursive traversals*/
struct node *stack[MAX];
int top = -1;
void push_stack(struct node *item)
{
    if(top == (MAX - 1))
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}

struct node *pop_stack()
{
    struct node *item;
    if(top == -1)
    {
        printf("Stack Underflow...\n");
        exit(1);
    }
    item = stack[top];
    top = top - 1;
    return item;
}

int stack_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void nrec_pre(struct node *root)
{
    struct node *ptr = root;
    if(ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    push_stack(ptr);
    while(!stack_empty())
    {
        ptr = pop_stack();
        printf("%d ", ptr -> data);
        if(ptr->rchild != NULL)
            push_stack(ptr -> rchild);
        if(ptr->lchild != NULL)
            push_stack(ptr -> lchild);
    }
    printf("\n");
}