#include <stdio.h>

int main(void)
{
	char c;
	int flag = 0;

	while(scanf("%c", &c) != EOF)
	{
		if(c == '"' && flag == 0)
		{
			printf("``");
			flag++;
		}
		else if(c == '"' && flag == 1)
		{
			printf("''");
			flag--;
		}
		else
			printf("%c", c);	
	}
	return(0);
}