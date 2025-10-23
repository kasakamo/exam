#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int cnt_w(char *s)
{
	int cnt = 0;
	int in_word = 0;
	while (*s)
	{
		if (!is_space(*s) && in_word == 0)
		{
			cnt++;
			in_word = 1;
		}
		else if (is_space(*s))
			in_word = 0;
		s++;
	}
	return (cnt);
}

char *dup_w(char *str)
{
	int len = 0;
	while (str[len] && !is_space(str[len]))
		len++;
	char *word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	int i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str)
{
	char **res = malloc(sizeof(char *) * (cnt_w(str) + 1));
	if (!res)
		return (NULL);
	int i = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str))
		{
			res[i++] = dup_w(str);
			while (*str && !is_space(*str))
				str++;
		}
	}
	res[i] = NULL;
	return (res);
}

void free_arr(char **arr)
{
	int i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void put_str(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void rostring(char *str)
{
	char **arr = ft_split(str);
	int i = 1;
	while (arr[i])
	{
		put_str(arr[i++]);
		write(1, " ", 1);
	}
	put_str(arr[0]);
	free_arr(arr);
}

int main(int ac, char **av)
{
	if (ac > 0)
		rostring(av[1]);
	write(1, "\n", 1);
}
