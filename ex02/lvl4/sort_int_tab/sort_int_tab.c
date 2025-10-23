void ft_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int is_smaller(int a, int b)
{
	return (a <= b);
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (!is_smaller(tab[i], tab[j]))
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

#include <stdio.h>

void print_tab(int *tab, int size)
{
	int i = 0;
	while (i < size)
		printf("%d\n", tab[i++]);
}

int main()
{
	int tab[] = {6, 2, 9, 3, 0, 1, 5};
	print_tab(tab, 7);
	sort_int_tab(tab, 7);
	printf("\n");
	print_tab(tab, 7);
}
