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

/*Explanation */
/*The pointer variable end is null in the first iteration of outer loop, so inner loop will terminate
when p points to the last node i.e. the inner loop will work only till p reaches second last node. 
After first iteration, value of end is updated and is made equal to q. So now end points to the last 
node. This time the inner loop will terminate wwhen p points to the second last node that is the inner
loop will work only till p reaches the third last node.
After each iteration of outer loop, the pointer end moves one node backwards. Initially end is NULL,
after first iteration it points to the last node, after second iteration it points to the second last 
node and so on. The terminating condition for outer loop is taken as (end != start -> link), so the 
outer loop will terminate when end points to the second node, i.e. the outer loop will work only till
end reaches the third node.*/
