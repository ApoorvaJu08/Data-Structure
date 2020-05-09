#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};

struct node *create(struct node *start);
void compare(struct node *start);
struct node *addtobeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);

void compare(struct node *start)
{
	struct node *p;
	int flag = 1;
	p = start;
	int max, min;
	while(p != NULL)
	{
		if(flag == 1)
		{
			max = p -> info;
			min = p -> info;
			flag = 0;
		}
		else 
		{
			if(max < p -> info)
				max = p -> info;
			else if(min > p -> info)
				min = p -> info;
		}	
		p = p -> link;
	}
	printf("%d\n", max);
	printf("%d\n", min);
}

struct node *create(struct node *start)
{
	int i, n, data;
	printf("Enter the number of nodes");
	scanf("%d", &n);
	start = NULL;
	if(n == 0)
		return start;
	printf("Enter the element to be inserted");
	scanf("%d", &data);
	start = addtobeg(start, data);
	for(i = 2; i <= n; i++)
	{
		printf("Enter the element to be inserted");
		scanf("%d", &data);
		start = addatend(start, data); 
	}
	return start;
}

struct node *addtobeg(struct node *start, int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp -> info = data;
	tmp -> link = start;
	start = tmp;
	return start;
}

struct node *addatend(struct node *start, int data)
{
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp -> info = data;
	p = start;
	while(p -> link != NULL)
		p = p -> link;
	p -> link = tmp;
	tmp -> link = NULL;
	return start;
}

int main()
{
	struct node *start = NULL;
	start = create(start);
	compare(start);
	return 0;	
}

