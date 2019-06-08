//When an array is passed to a function, the receiving argument is declared as a pointer

#include <stdio.h>
void func(float f[], int *i, char c[5]);
// several ways in which array can be passed in a function

int main()
{
    float f_arr[5] = {1.4, 2.5, 3.7, 4.1, 5.9};
    int i_arr[5] = {1, 2, 3, 4, 5};
    char c_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    printf("Inside main() :");
    printf("Size of f_arr = %lu\t", sizeof(f_arr));
    printf("Size of i_arr = %lu\t", sizeof(i_arr));
    printf("Size of c_arr = %lu\n", sizeof(c_arr));
    func(f_arr, i_arr, c_arr);
}

void func(float f[], int *i, char c[5])
{
    printf("Inside func(): ");
    printf("Size of f = %lu\t", sizeof(f));
    printf("Size of i = %lu\t", sizeof(i));
    printf("Size of c = %lu\n", sizeof(c));
}
