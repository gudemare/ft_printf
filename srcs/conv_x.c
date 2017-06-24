/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:52:39 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/24 04:19:05 by gudemare         ###   ########.fr       */
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
	int		i;

	if (spec.precision == -1 && spec.format && ft_strchr(spec.format, '0'))
		s = apply_pre(s, spec.min_width);
	if (!(buf = ft_strnew(spec.min_width)))
		exit(EXIT_FAILURE);
	ft_memset((void*)buf, ' ', spec.min_width);
	if (spec.format != NULL && ft_strchr(spec.format, (int)'-'))
		ft_strncpy(buf, s, ft_strlen(s));
	else
		ft_strcpy(buf + spec.min_width - ft_strlen(s), s);
	if (spec.format && ft_strchr(spec.format, '#')
			&& *buf == '0' && buf[1] != 'x')
	{
		i = 0;
		while (buf[i] != 'x')
			i++;
		buf[i] = '0';
		buf[1] = 'x';
	}
	ft_strdel(&s);
	return (buf);
}

static void					ft_strtoupper(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s = *s - 'a' + 'A';
		s++;
	}
}

int							conv_x(va_list ap, t_spec spec)
{
	char	*buf;
	char	*tmp;
	int		ret;

	if (!(buf = ft_uanytoa_base(get_d_arg(ap, spec.length), 16)))
		exit(EXIT_FAILURE);
	if ((spec.precision == 0 && *buf == '0')
			|| spec.precision > (int)ft_strlen(buf))
		buf = apply_pre(buf, spec.precision);
	if (spec.format && ft_strchr(spec.format, '#')
			&& *buf && !ft_strequ(buf, "0"))
	{
		if (!(tmp = ft_strjoin("0x", buf)))
			exit(EXIT_FAILURE);
		ft_strdel(&buf);
		buf = tmp;
	}
	if (spec.min_width > (int)ft_strlen(buf))
		buf = apply_mfw(buf, spec);
	ft_strtoupper((spec.conv == 'X') ? buf : NULL);
	ft_putstr(buf);
	ret = ft_strlen(buf);
	ft_strdel(&buf);
	return (ret);
}
