#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *lchild;
    int info;
    struct node *rchild;
};
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
main(){
    struct node *root=NULL, *ptr;
    int choice, k;
    while(1){
        printf("\n");
        printf("1.Recursive Preorder Traversal\n");
        printf("2.Recursive Inorder Traversal\n");
        printf("3.Recursive Postorder Traversal\n");
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
            exit(1);
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