// Program of single linked list with header node
#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *create_list(struct node *head);
void display(struct node *head);
// void count(struct node *head);
// void search(struct node *head, int data);
// struct node *addatbeg(struct node *head, int data);
struct node *addatend(struct node *head, int data);
// struct node *addafter(struct node *head, int data, int item);
struct node *addbefore(struct node *head, int data, int item);
struct node *addatpos(struct node *head, int data, int pos);
struct node *del(struct node *head, int data);
struct node *reverse(struct node *head);
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head -> info = 0;
    head -> link = NULL;
    head = create_list(head);
    int choice, data, item, pos;
    while(1)
    {
        // printf("1. Create List\n");
        printf("2. Display\n");
        // printf("3. Count\n");
        // printf("4. Search\n");
        // printf("5. Add to empty list / Add at beginning\n");
        printf("6. Add at end\n");
        // printf("7. Add after node\n");
        printf("8. Add before node\n");
        printf("9. Add at position\n");
        printf("10. Delete\n");
        printf("11. Reverse\n");
        printf("12. Quit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {
            // case 1:
            //     head = create_list(head);
            //     break;
            case 2:
                display(head);
                break;
            // case 3:
            //     count(head);
            //     break;
            // case 4:
            //     printf("Enter the element to be searched : ");
            //     scanf("%d", &data);
            //     search(head, data);
            //     break;
            // case 5:
            //     printf("Enter the element to be inserted : ");
            //     scanf("%d", &data);
            //     head = addatbeg(head, data);
            //     break;
            case 6:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                head = addatend(head, data);
                break;
            case 7:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the element after which to insert");
                scanf("%d", &item);
                head = addafter(head, data, item);
                break;
            case 8:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the element before which to insert");
                scanf("%d", &item);
                head = addbefore(head, data, item);
                break;
            case 9:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the position at which to insert");
                scanf("%d", &pos);
                head = addatpos(head, data, pos);
                break;
            case 10:
                printf("Enter the element to be deleted : ");
                scanf("%d", &data);
                head = del(head, data);
                break;
            case 11:
                head = reverse(head);
                break;
            case 12:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}
struct node *create_list(struct node *head)
{
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        head = addatend(head, data);
    }
    return head;
}
void display(struct node *head)
{
    struct node *p;
    if(head -> link == NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = head -> link;
    printf("List is: \n");
    while(p != NULL)
    {
        printf("%d ", p -> info);
        p = p -> link;
    }
    printf("\n");
}
struct node *addatend(struct node *head, int data)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    p = head;
    while(p -> link != NULL)
        p = p -> link;
    p -> link = tmp;
    tmp -> link = NULL;
    return head;
}
struct node *addbefore(struct node *head, int data, int item)
{
    struct node *tmp, *p;
    p = head;
    while( p -> link != NULL)
    {
        if(p -> link -> info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp -> info = data;
            tmp -> link = p -> link;
            p -> link = tmp;
            return head;
        }
        p = p -> link;
    }
    printf("%d not present in the list\n", item);
    return head;
}
