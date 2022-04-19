#include<stdio.h>

int main(void)
{
	int x;
	int equação;
	int value;
	int modValue;

	scanf("%i", &value);
	modValue = value*-1;
	while(modValue <= value)
	{
		x = modValue;
		equação = (x * x)+ x + 1;
		if(modValue > 0)
			printf("0%i",modValue);
		else
			printf("%i",modValue);
		while(equação != 0)
		{
			printf("–");
			equação--;
		}
		printf("*\n");
		modValue++;
	}
	return(0);
}