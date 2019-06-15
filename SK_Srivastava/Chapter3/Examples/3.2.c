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
void count(struct node *start);
void search(struct node *start, int data);
struct node *addtoempty(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *addatpos(struct node *start, int data, int pos);
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
        printf("3. Count\n");
        printf("4. Search\n");
        printf("13. Add to empty\n");
        printf("5. Add at beginning\n");
        printf("6. Add at end\n");
        printf("7. Add after node\n");
        printf("8. Add before node\n");
        printf("9. Add at position\n");
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
            case 3:
                count(start);
                break;
            case 4:
                printf("Enter the element to be searched : ");
                scanf("%d", &data);
                search(start, data);
                break;
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
                start = addbefore(start, data, item);
                break;
            case 9:
                printf("Enter the element to be inserted");
                scanf("%d", &data);
                printf("Enter the position at which to insert");
                scanf("%d", &pos);
                start = addatpos(start, data, pos);
                break;
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
struct node *addatpos(struct node *start, int data, int pos)
{
    int i;
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    if(pos == 1)
    {
        tmp -> next = start;
        // tmp -> prev = NULL;
        start = tmp;
        return start;
    }
    p = start;
    for(i = 1; i < pos - 1 && p != NULL; i++)
        p = p -> next;
    if(p == NULL)
        printf("There are less than %d elements\n", pos);
    else
    {
        tmp -> next = p -> next;
        // tmp -> prev = p;
        p -> next = tmp;
    }
    return start;
}
void count(struct node *start)
{
    struct node *p = start;
    int cnt = 0;
    while(p != NULL)
    {
        p = p -> next;
        cnt++;
    }
    printf("The number of elements are: %d\n", cnt);
}
void search(struct node *start, int data)
{
    struct node *p = start;
    int pos = 1;
    while(p != NULL)
    {
        if(p -> info == data)
        {
            printf("Item found at position %d: \n", pos);
            return;
        }
        p = p -> next;
        pos++;
    }
    printf("Item not found in the list\n");
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
struct node *addbefore(struct node *start, int data, int item)
{
    struct node *tmp, *q;
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(start -> info == item)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp -> info = data;
        tmp -> prev = NULL;
        tmp -> next = start;
        start -> prev = tmp;
        start = tmp;
        return start;
    }
    q = start;
    while(q != NULL)
    {
        if(q -> info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp -> info = data;
            tmp -> prev = q -> prev;
            tmp -> next = q;
            q -> prev -> next = tmp;
            q -> prev = tmp;
            return start;
        }
        q = q -> next;
    }
    printf("%d not present in the list\n", item);
    return start;
}
struct node *create_list(struct node *start)
{
    int i, n, data;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    start = NULL;
    if(n == 0)
        return start;
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    start = addtoempty(start, data);
    for(i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}
struct node *del(struct node *start, int data)
{
    struct node *tmp;
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(start -> next == NULL) /*deletion of the only node */
    {
        if(start -> info == data)
        {
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
        }
        else
        {
            printf("Element %d not found\n", data);
            return start;
        }
    }
    if(start -> info == data) /*deletion of first node */
    {
        tmp = start;
        start = start -> next;
        start -> prev = NULL;
        free(tmp);
        return start;
    }
    tmp = start -> next; /*deletion in between */
    while(tmp -> next != NULL)
    {
        if(tmp -> info == data)
        {
            tmp -> prev -> next = tmp -> next;
            tmp -> next -> prev = tmp -> prev;
            free(tmp);
            return start;
        }
        tmp = tmp -> next;
    }
    if(tmp -> info == data) /*deletion of last node */
    {
        tmp -> prev -> next = NULL;
        free(tmp);
        return start;
    }
    printf("Element %d not found\n", data);
    return start;
}
struct node *reverse(struct node *start)
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1 -> next;
    p1 -> next = NULL;
    p1 -> prev = p2;
    while(p2 != NULL)
    {
        p2 -> prev = p2 -> next;
        p2 -> next = p1;
        p1 = p2;
        p2 = p2 -> prev;
    }
    start = p1;
    printf("List reversed\n");
    return start;
}