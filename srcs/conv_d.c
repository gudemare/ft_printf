/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:52:18 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/24 04:29:10 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_d_arg(va_list ap, char *length)
{
	if (!length)
		return ((long long)va_arg(ap, int));
	else if (ft_strstr(length, "z"))
		return ((long long)va_arg(ap, size_t));
	else if (ft_strstr(length, "j"))
		return ((long long)va_arg(ap, intmax_t));
	else if (ft_strstr(length, "ll"))
		return (va_arg(ap, long long));
	else if (ft_strstr(length, "l"))
		return ((long long)va_arg(ap, long));
	else if (ft_strstr(length, "hh"))
		return ((long long)(signed char)va_arg(ap, int));
	else if (ft_strstr(length, "h"))
		return ((long long)(short)va_arg(ap, int));
	exit(EXIT_FAILURE);
}

static char			*apply_sign(char *s, char *format)
{
	char	*buf;

	if (!ft_isdigit(*s))
		return (s);
	if (!(buf = ft_strnew(ft_strlen(s) + 1)))
		exit(EXIT_FAILURE);
	ft_strcpy(buf + 1, s);
	ft_strdel(&s);
	*buf = (ft_strchr(format, '+')) ? '+' : ' ';
	return (buf);
}

static char			*apply_pre(char *s, int precision)
{
	char	*buf;
	int		is_signed;

	is_signed = 1 - ft_isdigit(*s);
	if (!(buf = ft_strnew(precision + is_signed)))
		exit(EXIT_FAILURE);
	if (is_signed)
	{
		*buf = *s;
		buf++;
		s++;
	}
	ft_memset((void*)buf, '0', precision);
	ft_strcpy(buf + precision - ft_strlen(s), s);
	s -= is_signed;
	ft_strdel(&s);
	return (buf - is_signed);
}

static char			*apply_mfw(char *s, t_spec spec)
{
	char	*buf;

	if (spec.precision == -1 && spec.format && ft_strchr(spec.format, '0'))
		return (apply_pre(s, spec.min_width + ft_isdigit(*s) - 1));
	if (!(buf = ft_strnew(spec.min_width)))
		exit(EXIT_FAILURE);
	ft_memset((void*)buf, ' ', spec.min_width);
	if (spec.format && ft_strchr(spec.format, (int)'-'))
		ft_strncpy(buf, s, ft_strlen(s));
	else
		ft_strcpy(buf + spec.min_width - ft_strlen(s), s);
	ft_strdel(&s);
	return (buf);
}

int					conv_d(va_list ap, t_spec spec)
{
	char	*buf;
	int		ret;

	if (!(buf = ft_anytoa(get_d_arg(ap, spec.length))))
		exit(EXIT_FAILURE);
	if (spec.format
			&& (ft_strchr(spec.format, ' ') || ft_strchr(spec.format, '+')))
		buf = apply_sign(buf, spec.format);
	if ((spec.precision == 0 && *buf == '0')
			|| spec.precision > (int)ft_strlen(buf) + ft_isdigit(*buf) - 1)
		buf = apply_pre(buf, spec.precision);
	if (spec.min_width > (int)ft_strlen(buf))
		buf = apply_mfw(buf, spec);
	ft_putstr(buf);
	ret = ft_strlen(buf);
	ft_strdel(&buf);
	return (ret);
}
