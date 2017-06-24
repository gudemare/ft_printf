/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:00:10 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/24 01:58:57 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			handle_conv(const t_conv_ptr *conv_list,
		const char *restrict *str, va_list ap)
{
	t_spec		spec;
	int			ret;
	int			i;

	*str += fill_spec(*str, &spec);
	if (spec.conv && (i = ft_strchr_loc("cdiopsuxX%", (int)spec.conv)) != -1)
		ret = (conv_list[i])(ap, spec);
	else if (spec.conv)
		ret = conv_c(ap, spec);
	else
	{
		*str -= 1;
		ret = 0;
	}
	ft_strdel(&spec.format);
	ft_strdel(&spec.length);
	return (ret);
}

static t_conv_ptr	*fill_conv_list(void)
{
	t_conv_ptr	*conv_list;

	if (!(conv_list = malloc(sizeof(t_conv_ptr) * 10)))
		exit(EXIT_FAILURE);
	conv_list[0] = &conv_c;
	conv_list[1] = &conv_d;
	conv_list[2] = &conv_d;
	conv_list[3] = &conv_o;
	conv_list[4] = &conv_p;
	conv_list[5] = &conv_s;
	conv_list[6] = &conv_u;
	conv_list[7] = &conv_x;
	conv_list[8] = &conv_x;
	conv_list[9] = &conv_c;
	return (conv_list);
}

int					ft_printf(const char *restrict str, ...)
{
	va_list		ap;
	int			i;
	int			ret;
	t_conv_ptr	*conv_list;

	va_start(ap, str);
	ret = 0;
	conv_list = fill_conv_list();
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		ft_putnstr(str, i);
		ret += i;
		str += i;
		if (*str == '%')
			ret += handle_conv(conv_list, &str, ap);
	}
	free(conv_list);
	va_end(ap);
	return (ret);
}
