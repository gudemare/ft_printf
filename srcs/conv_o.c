/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:52:25 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/24 04:30:02 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	get_d_arg(va_list ap, char *length)
{
	if (!length)
		return ((unsigned long long)va_arg(ap, unsigned int));
	else if (ft_strstr(length, "z"))
		return ((unsigned long long)va_arg(ap, size_t));
	else if (ft_strstr(length, "j"))
		return ((unsigned long long)va_arg(ap, uintmax_t));
	else if (ft_strstr(length, "ll"))
		return (va_arg(ap, unsigned long long));
	else if (ft_strstr(length, "l"))
		return ((unsigned long long)va_arg(ap, unsigned long));
	else if (ft_strstr(length, "hh"))
		return ((unsigned long long)(unsigned char)va_arg(ap, int));
	else if (ft_strstr(length, "h"))
		return ((unsigned long long)(unsigned short)va_arg(ap, int));
	exit(EXIT_FAILURE);
}

static char					*apply_pre(char *s, int precision)
{
	char	*buf;

	if (!(buf = ft_strnew(precision)))
		exit(EXIT_FAILURE);
	ft_memset((void*)buf, '0', precision);
	ft_strcpy(buf + precision - ft_strlen(s), s);
	ft_strdel(&s);
	return (buf);
}

static char					*apply_mfw(char *s, t_spec spec)
{
	char	*buf;

	if (spec.precision == -1 && spec.format && ft_strchr(spec.format, '0'))
		return (apply_pre(s, spec.min_width));
	if (!(buf = ft_strnew(spec.min_width)))
		exit(EXIT_FAILURE);
	ft_memset((void*)buf, ' ', spec.min_width);
	if (spec.format != NULL && ft_strchr(spec.format, (int)'-'))
		ft_strncpy(buf, s, ft_strlen(s));
	else
		ft_strcpy(buf + spec.min_width - ft_strlen(s), s);
	ft_strdel(&s);
	return (buf);
}

int							conv_o(va_list ap, t_spec spec)
{
	char	*buf;
	int		ret;

	if (!(buf = ft_uanytoa_base(get_d_arg(ap, spec.length), 8)))
		exit(EXIT_FAILURE);
	if (spec.format && ft_strchr(spec.format, '#')
			&& spec.precision <= (int)ft_strlen(buf))
		spec.precision = (*buf == '0') ? 1 : ft_strlen(buf) + 1;
	if ((spec.precision == 0 && *buf == '0')
			|| spec.precision > (int)ft_strlen(buf))
		buf = apply_pre(buf, spec.precision);
	if (spec.min_width > (int)ft_strlen(buf))
		buf = apply_mfw(buf, spec);
	ft_putstr(buf);
	ret = ft_strlen(buf);
	ft_strdel(&buf);
	return (ret);
}
