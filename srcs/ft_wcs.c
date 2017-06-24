/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:09:02 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/23 03:34:44 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int		ft_wstrlen(wchar_t *ws)
{
	int	ret;

	ret = 0;
	while (ws[ret])
		ret++;
	return (ret);
}

int		ft_wcharsize(wchar_t wc)
{
	if (wc <= 127)
		return (1);
	else if (wc <= 2047)
		return (2);
	else if (wc <= 65535)
		return (3);
	else if (wc <= 1114111)
		return (4);
	exit(EXIT_FAILURE);
}

int		ft_wstrsize(wchar_t *ws)
{
	int	ret;

	ret = 0;
	while (*ws)
	{
		ret += ft_wcharsize(*ws);
		ws++;
	}
	return (ret);
}

void	ft_putwchar(wchar_t wc)
{
	if (wc <= 127)
		ft_putchar(wc);
	else if (wc <= 2047)
	{
		ft_putchar((wc >> 6) + 0xC0);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 65535)
	{
		ft_putchar((wc >> 12) + 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 1114111)
	{
		ft_putchar((wc >> 18) + 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
}

void	ft_putwnstr(wchar_t *ws, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		ft_putwchar(ws[i]);
		i++;
	}
}
