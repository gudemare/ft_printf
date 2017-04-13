/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 07:27:25 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 07:36:46 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char*)malloc(sizeof(char) * (ft_min(ft_strlen(src), (int)n) + 1));
	if (!dst)
		return (NULL);
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
