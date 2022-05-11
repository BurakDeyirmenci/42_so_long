/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:57:33 by devman            #+#    #+#             */
/*   Updated: 2022/02/15 13:41:26 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*skip_del(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static size_t	count_words(char const *str, char delimitter)
{
	size_t	ret;

	ret = 0;
	while (1)
	{
		str = skip_del(str, delimitter);
		if (*str)
		{
			ret++;
			while (*str && *str != delimitter)
				str++;
		}		
		else
			break ;
	}
	return (ret);
}

static void	*free_list(char **lst, size_t len)
{
	while (len-- > 0)
		free(*lst++);
	free(lst);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	while (1)
	{
		s = skip_del(s, c);
		if (!*s)
			break ;
		ret[i] = ft_substr(s, 0, get_word_len(s, c));
		if (ret[i] == NULL)
			return (free_list(ret, i));
		while (*s && *s != c)
			s++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
