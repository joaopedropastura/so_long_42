#include <stdio.h>

float media(float notas[])
{
	int i;
	float media;

	i = 0;
	media = 0;
	float result;
	while(notas[i])
	{
		media += notas[i];
		printf("%.2f\n", media);
		i++;
	}
	result = media/i;
	printf("mdf %.2f\n", result);
	return(result);
}

int main()
{
	float a;
	float notas[5] = {4,5,6,7,8};
	printf("%.2f\n", notas[2]);
	a = media(notas);
	printf("%.2f\n", a);
}