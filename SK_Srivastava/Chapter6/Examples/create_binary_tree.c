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
struct listnode *postptr = NULL;
struct treenode *create();
void display(struct listnode *start);
int count(struct listnode *start);
struct listnode *addatbeg(struct listnode *start, int data);
struct listnode *addatend(struct listnode *start, int data);
void preorder(struct treenode *root);
void inorder(struct treenode *root);
void postorder(struct treenode *root);
void push_stack(struct treenode *item);
struct treenode *pop();
int stack_empty();
struct treenode *construct_pre(struct listnode *inptr, struct listnode *preptr, int num);
int main() {
    struct treenode *root;
    struct treenode *root1;
    root = create();
    int num;
    printf("The preorder traversal for tree is: \n");
    preorder(root);
    printf("The inorder traversal for tree is: \n");
    inorder(root);
    printf("Linked List of preorder: \n");
    display(preptr);
    printf("Linked List of inorder: \n");
    display(inptr);
    num = count(preptr);
    printf("%d\n", num);
    printf("Created list from preorder and inorder traversals: \n");
    root1 = construct_pre(inptr, preptr, num);
}
struct treenode *create(){
    struct treenode *p;
    int x;
    printf("Enter data for tree(-1 for no data): \n");
    scanf("%d", &x);
    if(x == -1)
        return NULL;
    p = (struct treenode *)malloc(sizeof(struct treenode));
    p->info = x;
    printf("Enter left child of %d:\n", x);
    p->lchild = create();
    printf("Enter right child of %d:\n", x);
    p->rchild = create();
    return p;
}

void display(struct listnode *start){
    struct listnode *p;
    if(start == NULL){
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("List is: \n");
    while(p != NULL){
        printf("%d\n", p->info);
        p = p -> next;
    }
    printf("\n");
}

int count(struct listnode *start){
    struct listnode *p = start;
    int cnt = 0;
    while(p != NULL){
        p = p -> next;
        cnt++;
    }
    return cnt;
}

struct listnode *addatbeg(struct listnode *start, int data){
    struct listnode *tmp;
    tmp = (struct listnode *)malloc(sizeof(struct listnode));
    tmp->info = data;
    tmp->next = start;
    start = tmp;
    return start;
}
struct listnode *addatend(struct listnode *start, int data){
    struct listnode *tmp, *p;
    tmp = (struct listnode *)malloc(sizeof(struct listnode));
    tmp->info = data;
    p = start;
    while(p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->next = NULL;
    return start;
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
        printf("%d\n", ptr->info);
        if(preptr == NULL)
            preptr = addatbeg(preptr, ptr->info);
        else
            preptr = addatend(preptr, ptr->info);
        if(ptr->rchild != NULL)
            push_stack(ptr->rchild);
        if(ptr->lchild != NULL)
            push_stack(ptr->lchild);
    }
    printf("\n");
}

void inorder(struct treenode *root){
    struct treenode *ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    while(1){
        while(ptr->lchild != NULL){
            push_stack(ptr);
            ptr = ptr -> lchild;
        }
        while(ptr -> rchild == NULL){
            printf("%d\n", ptr->info);
            if(inptr == NULL)
                inptr = addatbeg(inptr, ptr->info);
            else
                inptr = addatend(inptr, ptr->info);
            if(stack_empty())
                return;
            ptr = pop();
        }
        printf("%d\n", ptr->info);
        if(inptr == NULL)
            inptr = addatbeg(inptr, ptr->info);
        else
            inptr = addatend(inptr, ptr->info);
        ptr = ptr->rchild;
    }
    printf("\n");
}

void postorder_nrec(struct treenode *root){
    struct treenode *q, *ptr = root;
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

struct treenode *construct_pre(struct listnode *inptr, struct listnode *preptr, int num){
    struct treenode *temp;
    struct listnode *q;
    int i, j;
    if(num == 0)
        return NULL;
    temp = (struct treenode *)malloc(sizeof(struct treenode));
    temp->info = preptr->info;
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(num == 1)
        return temp;
    q = inptr;
    for(i = 0; q->info != preptr->info; i++)
        q = q->next;
    /* Now q points to root node in inorder list and number of nodes in its leftsubtree is i*/
    temp->lchild = construct_pre(inptr, preptr->next, i);
    for(j = 1; j <= i+1; j++)
        preptr = preptr->next;
    temp->rchild = construct_pre(q->next, preptr, num-i-1);
    return temp;
}

struct treenode *construct_post(struct listnode *inptr, struct listnode *potptr, int num){
    struct treenode *temp;
    struct listnode *q, *ptr;
    int i, j;
    if(num == 0)
        return NULL;
    ptr = postptr;
    for(i = 1; i < num; i++)
        ptr = ptr->next;
    temp = (struct treenode *)malloc(sizeof(struct treenode));
    temp -> info = ptr->info;
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(num == 1)
        return temp;
    q = inptr;
    for(i = 0; q->info != ptr->info; i++)
        q = q->next;
    temp->lchild = construct_post(inptr, postptr, num);
    for(j = 1; j <= i; j++)
        postptr = postptr->next;
    temp->rchild = construct_post(q->next, postptr, num-i-1);
    return temp;
}