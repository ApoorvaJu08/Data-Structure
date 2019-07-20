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

/*Explanation */
/*If the value in node pointed by p is greater than the value in node pointed by q then we will have to 
change the links such that the position of these nodes in list are exchanged. For changing the positions 
we will need the address of predecessor nodes also. So we will take two more pointers r and s which will
point to the predecessors of nodes pointed by p and q respectively. */