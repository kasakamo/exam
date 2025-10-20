#include "ft_list.h"
#include <stdlib.h>

int cmp_str(void *a, void *b);

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *cur = *begin_list;
	t_list *head = NULL;
	t_list *tmp;
	if (!begin_list || !*begin_list)
		return ;
	while (cur)
	{
		if (!(*cmp)(cur->data, data_ref))
		{
			tmp = cur->next;
			if (head == NULL)
				*begin_list = tmp;
			else
				head->next = tmp;
			free(cur);
			cur = tmp;
		}
		else
		{
			head = cur;
			cur = cur->next;
		}
	}
}

//========================================================================

#include <stdio.h>
#include <string.h>

int cmp_str(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
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
		printf("%s -> ", (char *)lst->data);
		lst = lst->next;
	}
	printf("NULL\n");
}

void list_add_front(t_list **lst, char *str)
{
	t_list *new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->data = str;
	new->next = *lst;
	*lst = new;
}

int main()
{
	t_list *lst = NULL;
	char *tab[] = {"apple", "banana", "apple", "cherry", "apple"};
	int i = 0;
	while (i < 5)
		list_add_front(&lst, tab[i++]);
	print_list(lst);
	ft_list_remove_if(&lst, "apple", cmp_str);
	print_list(lst);
	free_list(lst);
}
