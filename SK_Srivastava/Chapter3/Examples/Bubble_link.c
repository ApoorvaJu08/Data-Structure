// Bubble sort by rearranging links
#include <stdio.h>
struct node {
    int info; 
    struct node *link;
};
struct node *bubble_l(struct node *start);
int main()
{
    struct node *start = NULL;
}
struct node *bubble_l(struct node *start)
{
    struct node *end, *r, *p, *q, *tmp;
    for(end = NULL; end != start -> link; end = q)
    {
        for(r = p = start; p -> link != end; r=p, p = p -> link)
        {
            q = p -> link;
            if(p -> info > q -> info)
            {
                p -> link = q -> link;
                q -> link = p;
                if(p != start)
                    r -> link = q;
                else
                {
                    start = q;
                }
                tmp = p; 
                p = q;
                q = tmp;
            }
        }
    }
    return start;
}