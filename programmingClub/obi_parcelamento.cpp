#include <stdio.h>

int main(void)
{
	int v;
	int p;
	int i;
	int resto;

	scanf("%i", &v);
	scanf("%i", &p);
	i = 0;
	resto = v % p;
	while(i != p)
	{
		if(v % p == 0)
		{
			printf("%i\n", v/p);
			i++;
		}
		else
		{
			if(i >= resto)
				printf("%i\n", v/p);
			else
				printf("%i\n", v/p+1);	
			i++;
		}
	}
	return(0);
}