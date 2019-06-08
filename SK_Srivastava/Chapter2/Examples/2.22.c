// Program to display the values of structure members
#include <stdio.h>
#include <string.h>

struct student {
    char name[20];
    int rollno;
    float marks;
};

int main()
{
    struct student stu1 = { "Marry", 25, 68};
    struct student stu2, stu3;
    strcpy(stu2.name, "John");
    stu2.marks = 98;
    stu2.rollno = 26;
    printf("Enter name, marks and rollno for stu3: ");
    scanf("%s %f %d", stu3.name, &stu3.marks, &stu3.rollno);
    printf("stu1: %s %d %.2f\n", stu1.name, stu1.rollno, stu1.marks);
    printf("stu2: %s %d %.2f\n", stu2.name, stu2.rollno, stu2.marks);
    printf("stu3: %s %d %.2f\n", stu3.name, stu3.rollno, stu3.marks);
}