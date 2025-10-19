#include <stdlib.h>

int cnt_n(long n)
{
	int cnt = 0;
	if (n <= 0)
	{
		cnt++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char *ft_itoa(int nbr)
{
	long n = nbr;
	int len = cnt_n(n);
	char *str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

#include <stdio.h>

int main()
{
	int tab[] = {0, 1, 123, -456, 2147483647, -2147483648};
	int i = 0;
	while (i < 6)
	{
		char *res = ft_itoa(tab[i]);
		printf("%d -> %s\n", tab[i++], res);
		free(res);
	}
}