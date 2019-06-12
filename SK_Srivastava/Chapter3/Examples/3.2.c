// Program of doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *prev;
    int info;
    struct node *next;
};
struct node *create_list(struct node *start);
void display(struct node *start);
// void count(struct node *start);
// void search(struct node *start, int data);
struct node *addtoempty(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
// struct node *addatpos(struct node *start, int data, int item);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);
int main()
{
    struct node *start = NULL;
    int choice, data, item, pos;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Display\n");
        // printf("3. Count\n");
        // printf("4. Search\n");
        printf("13. Add to empty\n");
        printf("5. Add at beginning\n");
        printf("6. Add at end\n");
        printf("7. Add after node\n");
        printf("8. Add before node\n");
        // printf("9. Add at position\n");
        printf("10. Delete\n");
        printf("11. Reverse\n");
        printf("12. Quit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                start = create_list(start);
                break;
            case 2:
                display(start);
                break;
            case 13:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start = addtoempty(start, data);
                break;
            // case 3:
            //     count(start);
            //     break;
            // case 4:
            //     printf("Enter the element to be searched : ");
            //     scanf("%d", &data);
            //     search(start, data);
            //     break;
            case 5:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                start = addatbeg(start, data);
                break;
            case 6:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                start = addatend(start, data);
                break;
            case 7:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the element after which to insert");
                scanf("%d", &item);
                start = addafter(start, data, item);
                break;
            case 8:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the element before which to insert");
                scanf("%d", &item);
                start = addafter(start, data, item);
                break;
            // case 9:
            //     printf("Enter the element to be inserted");
            //     scanf("%d", &data);
            //     printf("Enter the position at which to insert");
            //     scanf("%d", &item);
            //     start = addatpos(start, data, pos);
            //     break;
            case 10:
                printf("Enter the element to be deleted : ");
                scanf("%d", &data);
                start = del(start, data);
                break;
            case 11:
                start = reverse(start);
                break;
            case 12:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}

void display(struct node *start)
{
    struct node *p;
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("List is: \n");
    while(p != NULL)
    {
        printf("%d", p -> info);
        p = p -> next;
    }
    printf("\n");
}
struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    tmp -> prev = NULL;
    tmp -> next = start;
    start -> prev = tmp;
    start = tmp;
    return start;
}
struct node *addtoempty(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    tmp -> next = NULL;
    tmp -> prev = NULL;
    start = tmp;
    return start;
}
struct node *addatend(struct node *start, int data)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    p = start;
    while(p -> next != NULL)
        p = p -> next;
    p -> next = tmp;
    tmp -> next = NULL;
    tmp -> prev = p;
    return start;
}
struct node *addafter(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    p = start;
    while(p != NULL)
    {
        if(p -> info == item)
        {
            tmp -> prev = p;
            tmp -> next = p -> next;
            if(p -> next != NULL)
                p -> next -> prev = tmp;
            p -> next = tmp;
            return start;
        }
        p = p -> next;
    }
    printf("%d not present in the list\n", item);
    return start;
}