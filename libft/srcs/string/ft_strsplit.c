/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:23:29 by gudemare          #+#    #+#             */
/*   Updated: 2017/02/06 14:15:43 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int		ft_count_words(char const *s, char c)
{
	unsigned int	word_nb;

	word_nb = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_nb++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word_nb);
}

static void				ft_clear_split(char **dst)
{
	unsigned int	i;

	i = 0;
	while (dst[i])
	{
		free(dst[i]);
		i++;
	}
	free(dst);
}

static unsigned int		ft_wordlen(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void				ft_strsplit_putwords(char **dst, char const *s, char c)
{
	unsigned int	len;
	unsigned int	index;

	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return ;
		len = ft_wordlen(s, c);
		dst[index] = ft_strsub(s, 0, len);
		if (!dst[index])
		{
			ft_clear_split(dst);
			return ;
		}
		s += len;
		index++;
	}
}

char					**ft_strsplit(char const *s, char c)
{
	unsigned int	word_nb;
	char			**dst;

	word_nb = ft_count_words(s, c);
	dst = (char **)malloc(sizeof(*dst) * (word_nb + 1));
	if (!dst)
		return (NULL);
	dst[word_nb] = NULL;
	ft_strsplit_putwords(dst, s, c);
	return (dst);
}
