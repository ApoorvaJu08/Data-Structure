//Program of circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *create_list(struct node *last);
void display(struct node *last);
// void count(struct node *last);
// void search(struct node *last, int data);
struct node *addtoempty(struct node *last, int data);
struct node *addatbeg(struct node *last, int data);
struct node *addatend(struct node *last, int data);
struct node *addafter(struct node *last, int data, int item);
// struct node *addbefore(struct node *last, int data, int item);
// struct node *addatpos(struct node *last, int data, int item);
struct node *del(struct node *last, int data);
// struct node *reverse(struct node *last);
int main()
{
    struct node *last = NULL;
    int choice, data, item, pos;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Display\n");
        // printf("3. Count\n");
        // printf("4. Search\n");
        printf("5. Add at beginning\n");
        printf("6. Add at end\n");
        printf("7. Add after node\n");
        // printf("8. Add before node\n");
        // printf("9. Add at position\n");
        printf("10. Delete\n");
        // printf("11. Reverse\n");
        printf("12. Quit\n");
        printf("13. Add to empty\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                last = create_list(last);
                break;
            case 2:
                display(last);
                break;
            case 3:
                count(last);
                break;
            case 4:
                printf("Enter the element to be searched : ");
                scanf("%d", &data);
                search(last, data);
                break;
            case 5:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                last = addatbeg(last, data);
                break;
            case 6:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                last = addatend(last, data);
                break;
            case 7:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the element after which to insert");
                scanf("%d", &item);
                last = addafter(last, data, item);
                break;
            case 8:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the element before which to insert");
                scanf("%d", &item);
                last = addafter(last, data, item);
                break;
            case 9:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the position at which to insert");
                scanf("%d", &item);
                last = addafter(last, data, pos);
                break;
            case 10:
                printf("Enter the element to be deleted : ");
                scanf("%d", &data);
                last = del(last, data);
                break;
            case 11:
                last = reverse(last);
                break;
            case 12:
                exit(1);
            case 13:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                last = addtoempty(last, data);
                break;
            default:
                printf("Wrong choice\n");
        }
    }
}
void display(struct node *last)
{
    struct node *p;
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = last -> link;
    do
    {
        printf("%d", p -> info);
        p = p -> link;
    } while (p != last -> link);
    printf("\n");
}
struct node *addatbeg(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    tmp -> link = last -> link;
    last -> link = tmp;
    return last;
}