//selection sort by exchanging data
#include <stdio.h>
struct node {
    int info; 
    struct node *link;
};
struct node *selection(struct node *start);
int main()
{
    struct node *start = NULL;
}
struct node *selection(struct node *start)
{
    struct node *p, *q, *r, *s, *tmp;
    for(r = p = start; p -> link != NULL; r = p, p = p -> link)
    {
        for(s = q = p -> link; q != NULL; s = q, q = q -> link)
        {
            if(p -> info > q -> info)
            {
                tmp = p -> link;
                p -> link = q -> link;
                q -> link = tmp;
                if(p != start)
                    r -> link = q;
                s -> link = p;
                if(p == start)
                    start = q;
                tmp = p; 
                p = q;
                q = tmp;
            }
        }
    }
    return start;
}