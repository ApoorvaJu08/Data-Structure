//Program of circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *create_list(struct node *last);
void display(struct node *last);
void count(struct node *last);
void search(struct node *last, int data);
struct node *addtoempty(struct node *last, int data);
struct node *addatbeg(struct node *last, int data);
struct node *addatend(struct node *last, int data);
struct node *addafter(struct node *last, int data, int item);
struct node *addbefore(struct node *last, int data, int item);
// struct node *addatpos(struct node *last, int data, int pos);
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
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Add at beginning\n");
        printf("6. Add at end\n");
        printf("7. Add after node\n");
        printf("8. Add before node\n");
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
                last = addbefore(last, data, item);
                break;
            // case 9:
            //     printf("Enter the element to be inserted");
            //     scanf("%d", &data);
            //     printf("Enter the position at which to insert");
            //     scanf("%d", &pos);
            //     last = addatpos(last, data, pos);
            //     break;
            case 10:
                printf("Enter the element to be deleted : ");
                scanf("%d", &data);
                last = del(last, data);
                break;
            // case 11:
            //     last = reverse(last);
            //     break;
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
void count(struct node *last)
{
    struct node *p;
    p = last;
    int cnt = 1;
    while(p -> link != last)
    {
        p = p -> link;
        cnt++;
    }
    printf("Number of elements are %d\n", cnt);
}
void search(struct node *last, int data)
{
    struct node *p = last -> link;
    int pos = 1;
    do
    {
        if(p -> info == data)
        {
            printf("Item %d found at position %d\n", data, pos);
            return;
        }
        p = p -> link;
        pos++;
    }while(p != last->link);
    printf("Item %d not found in the list\n", data);
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
struct node *addtoempty(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    last = tmp;
    last -> link = last;
    return last;
}
struct node *addatend(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    tmp -> link = last -> link;
    last -> link = tmp;
    last = tmp;
    return last;
}
struct node *addafter(struct node *last, int data, int item)
{
    struct node *tmp, *p;
    p = last -> link;
    do
    {
        if(p -> info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp -> info = data;
            tmp -> link = p -> link;
            p -> link = tmp;
            if(p == last)
                last = tmp;
            return last;
        }
        p = p -> link;
    } while (p != last-> link);
    printf("%d not present in the list\n", item);
    return last;
}
struct node *addbefore(struct node *last, int data, int item)
{
    struct node *tmp, *p;
    p = last -> link;
    do
    {
        if(p -> link -> info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp -> info = data;
            tmp -> link = p -> link;
            p -> link = tmp;
            return last;
        }
        p = p -> link;
    } while (p != last -> link);
    printf("Item %d not present in the list\n", item);
    return last;
}
struct node *create_list(struct node *last)
{
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    last = NULL;
    if(n == 0)
        return last;
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    last = addtoempty(last, data);
    for(i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        last = addatend(last, data);
    }
    return last;
}
struct node *del(struct node *last, int data)
{
    struct node *tmp, *p;
    if(last == NULL)
    {
        printf("List is empty\n");
        return last;
    }
    if(last -> link == last && last -> info == data) /*Deletion of the only node */
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    if(last -> link -> info == data) /*Deletion of first node */
    {
        tmp = last -> link;
        last -> link = tmp -> link;
        free(tmp);
        return last;
    }
    p = last -> link; /*Deletion in between */
    while(p -> link != last)
    {
        if(p -> link -> info == data)
        {
            tmp = p -> link;
            p -> link = tmp -> link;
            free(tmp);
            return last;
        }
        p = p -> link;
    }
    if(last -> info == data) /*Deletion of last node */
    {
        tmp = last;
        p -> link = last -> link;
        last = p;
        free(tmp);
        return last;
    }
    printf("Element %d not found\n", data);
    return last;
}