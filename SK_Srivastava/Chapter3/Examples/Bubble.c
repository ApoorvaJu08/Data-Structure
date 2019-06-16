//Bubble sort by exchanging data
#include <stdio.h>
struct node {
    int info; 
    struct node *link;
};
void bubble(struct node *start);
int main()
{
    struct node *start = NULL;
}
void bubble(struct node *start)
{
    struct node *end, *p, *q;
    int tmp;
    for(end = NULL; end != start -> link; end = q)
    {
        for(p = start; p -> link != end; p = p -> link)
        {
            q = p -> link;
            if(p -> info > q -> info)
            {
                tmp = p -> info;
                p -> info = q -> info;
                q -> info = tmp;
            }
        }
    }
}