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
struct node *search(struct node *ptr, int skey);
struct node *insert(struct node *root, int ikey);
struct node *del(struct node *root, int dkey);
struct node *Min(struct node *ptr);
struct node *Max(struct node *ptr);
void push_stack(struct node *ptr);
struct node *pop_stack();
int is_empty();
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
int height(struct node *ptr);
int main(){
    struct node *root = NULL, *ptr;
    int choice, k;
    while (1)
    {
        printf("\n");
        printf("1. Search\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Height of tree\n");
        printf("8. Find minimum and maximum\n");
        printf("9. Quit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to be searched: ");
            scanf("%d", &k);
            ptr = search(root, k);
            if(ptr == NULL)
                printf("Key not present\n");
            else
                printf("Key present\n");
            break;
        case 2:
            printf("Enter the key to be inserted: ");
            scanf("%d", &k);
            root = insert(root,k);
            break;
        case 3:
            printf("Enter the key to be deleted: ");
            scanf("%d", &k);
            root = del(root, k);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case 7:
            printf("Height of tree is %d\n", height(root));
            break;
        case 8:
            ptr = Min(root);
            if(ptr != NULL)
                printf("Minimum key is %d\n", ptr->info);
            ptr = Max(root);
            if(ptr != NULL)
                printf("Maximum key is %d\n", ptr->info);
            break;
        case 9:
            exit(1);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}

struct node *search(struct node *ptr, int skey){
    if(ptr == NULL){
        printf("Key not found\n");
        return NULL;
    }
    else if(skey < ptr->info)
        return search(ptr->lchild, skey);
    else if(skey > ptr->info)
        return search(ptr->rchild, skey);
    else
        return ptr;
}

struct node *insert(struct node *root, int ikey){
    struct node *ptr, *par, *tmp;
    ptr = root;
    par = NULL;
    while(ptr != NULL){
        par = ptr;
        if(ikey < ptr->info)
            ptr = ptr->lchild;
        else if(ikey > ptr->info)
            ptr = ptr->rchild;
        else{
            printf("Duplicate Key\n");
            return root;
        }
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = ikey;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if(par == NULL)
        root = tmp;
    else if(ikey < par->info)
        par->lchild = tmp;
    else
        par->rchild = tmp;
    return root;
}

struct node *del(struct node *root, int dkey){
    struct node *par, *ptr, *parsucc, *succ, *child;
    ptr = root;
    par = NULL;
    while(ptr != NULL){
        if(dkey ==ptr->info)
            break;
        par = ptr;
        if(dkey < ptr->info)
            ptr = ptr -> lchild;
        else
            ptr = ptr -> rchild;
    }
    if(ptr == NULL){
        printf("dkey not present\n");
        return root;
    }
    if(ptr -> lchild != NULL && ptr -> rchild != NULL){
        parsucc = ptr;
        succ = ptr -> rchild;
        while(succ->lchild != NULL){
            parsucc = succ;
            succ = succ->lchild;
        }
        ptr->info = succ->info;
        ptr = succ;
        par = parsucc;
    }
    if(ptr -> lchild != NULL)
        child = ptr->lchild;
    else
        child = ptr -> rchild;
    if(par == NULL)
        root = child;
    else if(ptr == par->lchild)
        par->lchild = child;
    else
        par->rchild = child;
    free(ptr);
    return root; 
}

void push_stack(struct node *ptr){
    if(top == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top]=ptr;
}

struct node *pop_stack(){
    if(top == -1){
        printf("Stack underflow\n");
        exit(1);
    }
    struct node *item;
    item = stack[top];
    top = top - 1;
    return item;
}

int is_empty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

void preorder(struct node *root){
    struct node *ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    push_stack(ptr);
    while (!is_empty())
    {
        ptr = pop_stack();
        printf("%d", ptr->info);
        if(ptr->rchild != NULL)
            push_stack(ptr->rchild);
        if(ptr->lchild != NULL)
            push_stack(ptr->lchild);
    }
    printf("\n");
}

void inorder(struct node *root){
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
        while(ptr -> rchild == NULL){
            printf("%d", ptr->info);
            if(is_empty())
                return;
            ptr = pop_stack();
        }
        printf("%d", ptr->info);
        ptr = ptr->rchild;
    }
    printf("\n");
}