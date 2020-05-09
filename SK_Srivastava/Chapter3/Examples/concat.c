#include <stdio.h>
#include <stdlib.h>
struct node {
    int info; 
    struct node *link;
};
struct node *concat(struct node *start1, struct node *start2);
struct node *concat_circular(struct node *last1, struct node *last2);
int main()
{
    struct node *start = NULL;
}

/*for single linked list */
struct node *concat(struct node *start1, struct node *start2)
{
    struct node *ptr;
    if(start1 == NULL)
    {
        start1 = start2;
        return start1;
    }
    if(start2 == NULL)
        return start1;
    ptr = start1;
    while(ptr -> link != NULL)
        ptr = ptr -> link;
    ptr -> link = start2;
    return start1;
}

/*for circular linked list */
struct node *concat_circular(struct node *last1, struct node *last2)
{
    struct node *ptr;
    if(last1 == NULL)
    {
        last1 = last2;
        return last1;
    }
    if(last2 == NULL)
        return last1;
    ptr = last1 -> link;
    last1 -> link = last2 -> link;
    last2 -> link = ptr;
    last1 = last2;
    return last1;
}