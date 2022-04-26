#include<stdio.h>
int main(void)
{
	unsigned int p0;
	unsigned int p1;
	unsigned int p2;
	unsigned int p3;
	unsigned int result;
	
	result = 0;
	scanf("%i %i %i %i", &p0, &p1, &p2, &p3);
	
	result += (p0 - p1 + 40) % 40;
	result += (p2 - p1 + 40) % 40;
	result += (p2 - p3 + 40) % 40;
	result += 120;
	result *= 9;
	
	printf("%i\n", result);
	return(0);
}