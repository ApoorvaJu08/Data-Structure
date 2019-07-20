//selection sort by exchanging data
#include <stdio.h>
struct node {
    int info; 
    struct node *link;
};
void selection(struct node *start);
int main()
{
    struct node *start = NULL;
}
void selection(struct node *start)
{
    struct node *p, *q;
    int tmp;
    p = start;
    for(p = start; p -> link != NULL; p = p -> link)
    {
        for(q = p -> link; q != NULL; q = q -> link)
        {
            if(p -> info > q -> info)
            {
                tmp = p -> info;
                p -> info = q -> info;
                q -> info = tmp;
            }
        }
    }
}
/*The terminating condition for outer loop is (p -> link != NULL), 
so it will terminate when p points to the last node i.e, it will work till p reaches second last node.
 The termination condition for inner loop is (q != NULL), so it will terminate when q becomes null,
  i.e, it will work till q reaches last node. After each iteration of the outer loop, the smallest
   element from the unsorted elements will be placed at its proper place. */