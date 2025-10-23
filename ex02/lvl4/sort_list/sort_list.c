#include "list.h"

void list_swap(t_list *lst)
{
	int tmp;
	tmp = lst->data;
	lst->data = lst->next->data;
	lst->next->data = tmp;
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *head = lst;
	while (lst->next)
	{
		if (!(*cmp)(lst->data, lst->next->data))
		{
			list_swap(lst);
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (head);
}

//=======================================================

#include <stdio.h>
#include <stdlib.h>

int ascending(int a, int b)
{
	return (a <= b);
}

void free_list(t_list *lst)
{
	t_list *tmp;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", lst->data);
		lst = lst->next;
	}
	printf("NULL\n");
}

void list_add_front(t_list **lst, int nbr)
{
	t_list *new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->data = nbr;
	new->next = *lst;
	*lst = new;
}

int main()
{
	t_list *lst = NULL;
	int tab[] = {4,2,8,0,3,7,1,5,6};
	int i = 0;
	while (i < 9)
		list_add_front(&lst, tab[i++]);
	print_list(lst);
	sort_list(lst, ascending);
	print_list(lst);
	free_list(lst);
}
