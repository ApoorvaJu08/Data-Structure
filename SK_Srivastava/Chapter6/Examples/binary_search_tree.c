#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *lchild;
    int info;
    struct node *rchild;
};
struct node *search(struct node *ptr, int skey);
struct node *insert(struct node *ptr, int ikey);
struct node *del(struct node *ptr, int dkey);
struct node *Min(struct node *ptr);
struct node *Max(struct node *ptr);
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