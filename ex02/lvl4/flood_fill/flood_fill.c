#include "flood_fill.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void fill(char **tab, t_point size, char target, int x, int y)
{
	if (x < 0 || y < 0 || size.x <= x || size.y <= y)
		return ;
	if (tab[y][x] == 'F' || tab[y][x] != target)
		return ;
	tab[y][x] = 'F';
	fill(tab, size, target, x + 1, y);
	fill(tab, size, target, x - 1, y);
	fill(tab, size, target, x, y + 1);
	fill(tab, size, target, x, y - 1);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, tab[begin.y][begin.x], begin.x, begin.y);
}

// =====================================================

void print_tab(char **area)
{
	while (*area)
		printf("%s\n", *area++);
}

void free_all(char **arr, int i)
{
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char **make_area(char **zone, int size)
{
	char **area = malloc(sizeof(char *) * (size + 1));
	if (!area)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		area[i] = strdup(zone[i]);
		if (!area[i])
			return (free_all(area, i), NULL);
		i++;
	}
	area[i] = NULL;
	return (area);
}

int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010101",
		"10010101",
		"11000011",
	};
	area = make_area(zone, size.y);
	print_tab(area);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area);
	return (0);
}