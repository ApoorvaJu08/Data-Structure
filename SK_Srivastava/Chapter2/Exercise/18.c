#include <stdio.h>
struct tag {
    int i;
    char c;
};
void func(struct tag);
int main()
{
    struct tag var = {12, 'c'};
    func(var);
    printf("%d\n", var.i);
}
void func(struct tag var)
{
    var.i++;
}