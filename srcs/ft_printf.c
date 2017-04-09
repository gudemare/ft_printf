/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:00:10 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/09 19:38:59 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	spec.conv_type = '\0';
	*str = fill_spec(*str, spec);
/*	if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'p' ||
			c == 'u' || c == 'U' || c == 'x' || c == 'X')
		ret = handle_int(*str, ap);
	else if (c == 's' || c == 'S')
		ret = handle_str(*str, ap);
	else if (c == 'c' || c == 'C')
		ret = handle_char(str, ap);
	*str++;
	return (ret);*/
	(void)ap;
	return (0);
}

int				ft_printf(const char *restrict str, ...)
{
	va_list		ap;
	int			i;
	int			ret;

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
			ret += handle_flag(&str, ap);
	}
	va_end(ap);
	return (ret);
}
