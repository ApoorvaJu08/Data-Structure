// Program of stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *top = NULL;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main()
{
    int choice, item;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display the top element\n");
        printf("4. Display all stack elements\n");
        printf("5. Quit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            printf("Popped item is: %d\n", item);
            break;
        case 3:
            printf("Item at the top is: %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
}

void push(int item)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    tmp -> info = item;
    tmp -> link = top;
    top = tmp;
}

int pop()
{
    
}