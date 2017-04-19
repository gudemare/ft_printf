/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:00:10 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/19 19:04:24 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int		handle_flag(const char *restrict *str, va_list ap)
{
	t_spec		spec;

	if (*(*str + 1) == '%')
	{
		ft_putchar('%');
		*str += 2;
		return (1);
	}
	spec.conv = '\0';
	*str += fill_spec(*str, &spec);
	return (handle_format(handle_convertion(ap, spec), spec));
}

int				ft_printf(const char *restrict str, ...)
{
	va_list		ap;
	int			i;
	int			ret;
	int			tmp;

	va_start(ap, str);
	ret = 0;
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		ft_putnstr(str, i);
		ret += i;
		str += i;
		if (*str == '%')
		{
			tmp = handle_flag(&str, ap);
			if (tmp < 1)
				break ;
			ret += tmp;
		}
	}
	va_end(ap);
	return (ret);
}
