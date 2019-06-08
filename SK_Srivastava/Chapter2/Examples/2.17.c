//Program to show that changes made to the array inside the function affect the original array
#include <stdio.h>
void func(int a[]);

void func(int a[])
{
    int i;
    printf("Inside func: ");
    for(i = 0; i < 5; i++)
    {
        a[i] = a[i] + 2;
        printf("%d", a[i]);
    }
    printf("\n");
}

int main()
{
    int i, arr[5] = {3, 6, 2, 7, 1};
    func(arr);
    printf("Inside main(): ");
    for(i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}