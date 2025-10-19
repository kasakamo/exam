#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		if (begin_list->data)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

#include <stdlib.h>
#include <stdio.h>

void free_list(t_list *list)
{
	t_list *tmp;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void print_list(t_list *list)
{
	while (list)
	{
		printf("%s -> ", (char *)list->data);
		list = list->next;
	}
	printf("NULL\n");
}

void first_large(void *s)
{
	if ('a' <= *(char *)s && *(char *)s <= 'z')
		*(char *)s += 'A' - 'a';
}

void list_add_front(t_list **list, char *str)
{
	t_list *new;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->data = str;
	new->next = *list;
	*list = new;
}

int main()
{
	t_list *list = NULL;
	char tab[][10] = {"apple", "banana", "apple", "cherry", "apple"};
	int i = 0;
	while (i < 5)
		list_add_front(&list, tab[i++]);
	print_list(list);
	ft_list_foreach(list, first_large);
	print_list(list);
	free_list(list);
}