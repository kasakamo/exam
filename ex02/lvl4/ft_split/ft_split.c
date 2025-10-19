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

char **ft_split(char *str)
{
	char **arr = malloc(sizeof(char *) * (cnt_w(str) + 1));
	if (!arr)
		return (NULL);
	int i = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str))
			{
				arr[i++] = dup_w(str);
				while (*str && !is_space(*str))
					str++;
			}
	}
	arr[i] = NULL;
	return (arr);
}

void free_all(char **arr)
{
	int i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char **arr = ft_split(av[1]);
		int i = 0;
		while (arr[i])
			printf("%s\n", arr[i++]);
		free_all(arr);
	}
}