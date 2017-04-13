/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 05:51:32 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/04 05:54:24 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dst, const char *src)
{
	int		offset;
	int		i;

	i = 0;
	offset = ft_strlen(dst);
	while (src[i])
	{
		dst[offset + i] = src[i];
		i++;
	}
	dst[offset + i] = '\0';
	return (dst);
}
