/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:45:50 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/09 11:19:38 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int		count_words(char const *s, char c);
static char		**free_strings(char **strings, size_t j);
static size_t	wordlen(char const *s, char c, size_t start);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strings;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	strings = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!strings)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			strings[j] = ft_substr(s, i, wordlen(s, c, i));
			if (!strings[j])
				return (free_strings(strings, j));
			j++;
		}
		i++;
	}
	return (strings);
}

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	wordlen(char const *s, char c, size_t start)
{
	size_t	i;

	i = 0;
	while (s[start + i] != '\0' && s[start + i] != c)
		i++;
	return (i);
}

static char	**free_strings(char **strings, size_t j)
{
	while (j > 0)
	{
		j--;
		free(strings[j]);
	}
	free(strings);
	return (NULL);
}
