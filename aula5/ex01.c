#include<stdio.h>

int main(void)
{
	int column;
	int row;
	int i;
	int j;

	i = 1;
	j = 1;
	scanf("%i", &column);
	scanf("%i", &row);
	while(i <= row)
	{
		while(j <= column)
		{	
			if(j*i > 9)
				printf("%i ", j*i);
			else
				printf("0%i ", j*i);
			j++;
		}
		j = 1;
		i++;
		printf("\n");
	}
}