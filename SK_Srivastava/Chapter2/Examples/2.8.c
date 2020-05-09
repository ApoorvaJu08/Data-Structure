// Program for multiplication of 2 matrices
#include<stdio.h>
#define ROW1 3
#define COL1 4
#define ROW2 COL1
#define COL2 2
int main()
{
    int i, j, k, mat1[ROW1][COL1], mat2[ROW2][COL2], mat3[ROW1][COL2];
    printf("Enter matrix mat1(%dx%d) row-wise:\n", ROW1, COL1);
    for(i = 0; i < ROW1; i++)
    {
        for(j = 0; j < COL1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter matrix mat2(%dx%d) row-wise:\n", ROW1, COL1);
    for(i = 0; i < ROW2; i++)
    {
        for(j = 0; j < COL2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    for(i = 0; i < ROW1; i++)
    {
        for(j = 0; j < COL2; j++)
        {
            mat3[i][j] = 0;
            for(k = 0; k < COL2; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("The resultant matrix mat3 is:\n");
    for(i = 0; i < ROW1; i++)
    {
        for(j = 0; j < COL2; j++)
        {
            printf("%5d\n", mat3[i][j]);
        }
    }
}