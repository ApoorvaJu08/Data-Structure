// Creation of binary tree from inorder and preorder
// inorder traversal will be required in the form of linkedlist
// preorder traversal will be required in the form of linkedlist
// one structure for tree type
// For creating inorder or preorder list we can just go through the inoorder traversals and
// store the output in linked list one by one
// adding in a linked list would require addatbeg and addAtEnd functions
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct listnode {
    int info;
    struct listnode *next;
};
struct treenode {
    struct treenode *lchild;
    int info;
    struct treenode *rchild;
};
struct treenode *stack[MAX];
int top = -1;
struct listnode *preptr = NULL;
struct listnode *inptr = NULL;
struct listnode *addatbeg(struct listnode *root, int data);
struct listnode *addatend(struct listnode *root, int data);
void preorder(struct treenode *root);
void inorder(struct treenode *root);
void postorder(struct treenode *root);
void push_stack(struct treenode *item);
struct treenode *pop();
int stack_empty();
main() {
    struct listnode *root;
}
struct listnode *addatbeg(struct listnode *root, int data){
    struct listnode *tmp;
    tmp = (struct listnode *)malloc(sizeof(struct listnode));
    tmp->info = data;
    tmp->next = root;
    root = tmp;
    return root;
}
struct listnode *addatend(struct listnode *root, int data){
    struct listnode *tmp, *p;
    tmp = (struct listnode *)malloc(sizeof(struct listnode));
    tmp->info = data;
    p = root;
    while(p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->next = NULL;
    return root;
}

void push_stack(struct treenode *item){
    if(top == (MAX - 1)){
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}

struct treenode *pop(){
    struct treenode *item;
    if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    item = stack[top];
    top = top - 1;
    return item;
}

int stack_empty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

void preorder(struct treenode *root){
    struct treenode *ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    push_stack(ptr);
    while(!stack_empty()){
        ptr = pop();
        printf("%d", ptr->info);
        if(preptr == NULL)
            addatbeg(root, ptr->info);
        else
            addatend(root, ptr->info);
        if(ptr->rchild != NULL)
            push_stack(ptr->rchild);
        if(ptr->lchild != NULL)
            push_stack(ptr->lchild);
    }
    printf("\n");
}

void inorder(struct treenode *root){

}