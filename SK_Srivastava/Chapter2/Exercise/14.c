#include <stdio.h>
void func(int x, int *y);
int main()
{
    int a = 2, b = 6;
    func(a, &b);
    printf("a = %d, b = %d\n", a, b);
}
void func(int x, int *y)
{
    int temp;
    temp = x;
    x = *y;
    *y = temp;
}
//First one is pass by value so the value does not change and second is pass by reference so value changes