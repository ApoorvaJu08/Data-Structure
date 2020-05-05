#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct node {
    struct node *lchild;
    int info;
    struct node *rchild;
};
struct node *stack[MAX];
int top = -1;
void push_stack(struct node *item);
struct node *pop_stack();
int stack_empty();
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
void preorder_nrec(struct node *ptr);
void inorder_nrec(struct node *ptr);
void postorder_nrec(struct node *ptr);
main(){
    struct node *root=NULL, *ptr;
    int choice, k;
    while(1){
        printf("\n");
        printf("1.Recursive Preorder Traversal\n");
        printf("2.Recursive Inorder Traversal\n");
        printf("3.Recursive Postorder Traversal\n");
        printf("4.Non-Recursive Preorder Traversal\n");
        printf("5.Non-Recursive Inorder Traversal\n");
        printf("6.Non-Recursive Postorder Traversal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            preorder_nrec(root);
            break;
        case 5: 
            inorder_nrec(root);
            break;
        case 6: 
            postorder_nrec(root);
            break;
        default:
            printf("Wrong choice\n");
        }
    }
}
void preorder(struct node *ptr){
    if(ptr == NULL) /*Base case*/
    {   printf("Tree is empty\n");
        return;
    }
    printf("%d", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct node *ptr){
    if(ptr == NULL) /*Base case*/
    {   printf("Tree is empty\n");
        return;
    }
    inorder(ptr->lchild);
    printf("%d", ptr->info);
    inorder(ptr->rchild);
}
void postorder(struct node *ptr){
    if(ptr == NULL) /*Base case*/
    {   printf("Tree is empty\n");
        return;
    }
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d", ptr->info);
}

void push_stack(struct node *item){
    if(top == (MAX - 1)){
        printf("Stack overflow\n");
        return;
    }
    top = top + 1;
    stack[top]=item;
}
struct node *pop_stack(){
    struct node *item;
    if(top==-1){
        printf("Stack Underflow\n");
        exit(1);
    }
    item = stack[top];
    top = top - 1;
    return item;
}
int stack_empty() {
    if(top == -1)
        return 1;
    else
        return 0;
}

void preorder_nrec(struct node *root){
    struct node *ptr=root;
    if(ptr== NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    push_stack(ptr);
    while(!stack_empty()){
        ptr = pop_stack();
        printf("%d", ptr->info);
        if(ptr->rchild != NULL)
            push_stack(ptr->rchild);
        if(ptr->lchild!= NULL)
            push_stack(ptr->lchild);
    }
    printf("\n");
}

void inorder_nrec(struct node *root){
    struct node *ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    while(1){
        while(ptr->lchild != NULL){
            push_stack(ptr);
            ptr = ptr->lchild;
        }
        while(ptr->rchild == NULL){
            printf("%d", ptr->info);
            if(stack_empty())
                return;
            ptr = pop_stack();
        }
        printf("%d", ptr->info);
        ptr = ptr->rchild;
    }
    printf("\n");
}

void postorder_nrec(struct node *root){
    struct node *q, *ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    q = root;
    while(1){
        while(ptr->lchild != NULL){
            push_stack(ptr);
            ptr = ptr-> lchild;
        }
        while(ptr->rchild == NULL || ptr->rchild == q){
            printf("%d", ptr->info);
            q = ptr;
            if(stack_empty())
                return;
            ptr = pop_stack();
        }
        push_stack(ptr);
        ptr = ptr->rchild;
    }
    printf("\n");
}