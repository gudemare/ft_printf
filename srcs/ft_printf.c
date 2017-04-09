/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:00:10 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/04 14:59:26 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void		handle_flag(const char *restrict str, va_list ap)
{
	str++;
	if (*str == '%')
		ft_putchar('%');
	else if (*str == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (*str == 's')
		ft_putstr(va_arg(ap, char *));
}

int				ft_printf(const char *restrict str, ...)
{
	va_list		ap;
	int			i;

	va_start(ap, str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		ft_putnstr(str, i);
		str += i;
		if (*str == '%')
		{
			handle_flag(str, ap);
			str += 2;
		}
	}
	va_end(ap);
	return (0);
}
