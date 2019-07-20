// Program of polynomial addition and multiplication using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coef;
    int expo;
    struct node *link;
};
struct node *create(struct node *);
struct node *insert_s(struct node *, float, int);
struct node *insert(struct node *, float, int);
void display(struct node *ptr);
void poly_add(struct node *, struct node *);
void poly_mult(struct node *, struct node *);

int main()
{
    struct node *start1 = NULL, *start2 = NULL;
    printf("Enter polynomail1: \n");
    start1 = create(start1);
    printf("Enter polynomail2: \n");
    start2 = create(start2);
    printf("Polynomial 1 is: ");
    display(start1);
    printf("Polynomial 2 is: ");
    display(start2);
}

struct node *create(struct node *start)
{
    int i, n, ex;
    float co;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        printf("Enter coeficient for term %d: ", i);
        scanf("%f", &co);
        printf("Enter exponent for term %d: ", i);
        scanf("%d", &ex);
        start = insert_s(start, co, ex);
    }
    return start;
}