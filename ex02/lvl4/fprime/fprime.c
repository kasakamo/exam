#include <stdio.h>
#include <stdlib.h>

void fprime(int num)
{
	int i = 2;
	if (num == 1)
		printf("1");
	while (i <= num)
	{
		if (num % i == 0)
		{
			printf("%d", i);
			if (i != num)
				printf("*");
			num /= i;
		}
		else
			i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
}