//program of sorted linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *insert_s(struct node *start, int data);
void search(struct node *start, int data);
void display(struct node *start);
int main()
{
    int choice, data;
    //count
    struct node *start = NULL;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            start = insert_s(start, data);
            break;
        
        case 2:
            display(start);
            break;
        
        case 3:
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            search(start, data);
            break;

        case 4:
            exit(1);

        default:
            printf("Wrong choice\n");
        }
    }
}
struct node *insert_s(struct node *start, int data)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    /*list empty or new node to be added before first node */
    if(start == NULL || data < start -> info)
    {
        tmp -> link = start;
        start = tmp;
        return start;
    }
    else
    {
        p = start;
        while(p -> link != NULL && p -> link -> info < data)
            p = p -> link;
        tmp -> link = p -> link;
        p -> link = tmp;
    }
    return start;
}