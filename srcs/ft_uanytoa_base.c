/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uanytoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 23:17:28 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/24 00:20:04 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_magnitude_order_base(unsigned long long n, int base)
{
	size_t	res;

	res = 0;
	while (n > 0)
	{
		res++;
		n /= base;
	}
	return (res);
}

static void			ft_itoa_decompose_base(unsigned long long n,
		char *dst, int base)
{
	while (n > 0)
	{
		*dst = n % base + '0';
		*dst = (*dst >= '0' && *dst <= '9') ? *dst : *dst - '0' - 10 + 'a';
		n /= base;
		dst--;
	}
}

char				*ft_uanytoa_base(unsigned long long n, int base)
{
	unsigned int	size;
	char			*dst;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_magnitude_order_base(n, base);
	if (!(dst = ft_strnew(size)))
		exit(EXIT_FAILURE);
	ft_itoa_decompose_base(n, dst + size - 1, base);
	dst[size] = '\0';
	return (dst);
}
