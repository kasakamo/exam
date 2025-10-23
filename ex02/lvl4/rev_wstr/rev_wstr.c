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
		if(!is_space(*s) && in_word == 0)
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

char *dup_w(char *s)
{
	int len = 0;
	while (s[len] && !is_space(s[len]))
		len++;
	char *word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	int i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char *s)
{
	char **res = malloc(sizeof(char *) * (cnt_w(s) + 1));
	if (!res)
		return (NULL);
	int i = 0;
	while (*s)
	{
		while(*s && is_space(*s))
			s++;
		if (*s && !is_space(*s))
		{
			res[i++] = dup_w(s);
			while (*s && !is_space(*s))
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}

void free_all(char **arr)
{
	if (!arr)
		return ;
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

void rev_wstr(char *str)
{
	char **arr = ft_split(str);
	int len = 0;
	while (arr[len])
		len++;
	while (--len >= 0)
	{
		put_str(arr[len]);
		if (len > 0)
			write(1, " ", 1);
	}
	free_all(arr);
}

int main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
}
