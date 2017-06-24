/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:07:29 by gudemare          #+#    #+#             */
/*   Updated: 2017/02/06 14:17:11 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_sec_strlen(const char *s)
{
	size_t size;

	size = 0;
	if (!s)
		return (0);
	while (s[size])
		size++;
	return (size);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	index;
	char			*dst;

	dst = (char *)malloc(sizeof(*dst) *
		(ft_sec_strlen(s1) + ft_sec_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	index = 0;
	while (*s1)
	{
		dst[index] = *s1;
		index++;
		s1++;
	}
	while (*s2)
	{
		dst[index] = *s2;
		index++;
		s2++;
	}
	dst[index] = '\0';
	return (dst);
}
