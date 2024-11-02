/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:23:33 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/13 11:24:14 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count__word(char *str, char sep)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != sep)
		{
			count++;
			while (*str != sep && *str)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static int	ft_word_len(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static void	ft_fill_word(char **str, char *s, char c)
{
	int	i;
	int	word_len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_len = ft_word_len(s, c);
			str[i] = (char *)malloc(word_len + 1);
			if (!str[i])
			{
				while (i > 0)
					free(str[--i]);
				free(str);
				return ;
			}
			str[i] = ft_strncpy(str[i], s, word_len);
			str[i][word_len] = '\0';
			i++;
			s += word_len;
		}
	}
}

char	**ft_split(char *str, char sep)
// Split :)
{
	int		word_count;
	char	**list_word;

	if (!str)
		return (NULL);
	word_count = count__word(str, sep);
	list_word = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!list_word)
		return (NULL);
	ft_fill_word(list_word, str, sep);
	list_word[word_count] = NULL;
	return (list_word);
}
