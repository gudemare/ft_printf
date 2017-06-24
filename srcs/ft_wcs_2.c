/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcs_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 23:39:39 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/24 03:52:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_wmemset(wchar_t *ws, wchar_t wc, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ws[i] = wc;
		i++;
	}
}

wchar_t	*ft_wstrdup(wchar_t *ws)
{
	return ((wchar_t*)ft_memdup(ws, (ft_wstrlen(ws) + 1) * sizeof(wchar_t)));
}

void	ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
}
