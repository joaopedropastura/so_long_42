#include<stdio.h>

int main(void)
{
	int x;
	int impar;
	int count;
	int soma;
	int countImpar;

	count = 1;
	impar = 1;
	soma = 1;
	countImpar = 0;
	scanf("%i", &x);
	while(count <= x)
	{
		printf("%i*%i*%i = ", count, count, count);
		while(countImpar != count)
		{
			if(countImpar == count -1)
				printf("%i", soma);
			else
				printf("%i+", soma);
			soma +=2;
			countImpar++;

		}
		printf("\n");
		countImpar = 0;
		count++;
	}
	return(0);
}
