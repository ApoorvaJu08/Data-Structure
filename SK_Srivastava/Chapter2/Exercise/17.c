#include <stdio.h>
struct tag {
        int i;
        char c;
    };
void fun(struct tag);
int main()
{
    struct tag var = {2, 's'};
    fun(var);
}
void fun(struct tag v)
{
	printf("%d %c\n", v.i, v.c);
}
