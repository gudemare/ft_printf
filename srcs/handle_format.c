/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 00:09:49 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/16 18:06:47 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char		*min_width(char *f_o, int min_width, char *format, char conv)
{
	char	*tmp;
	char	c;
	int		f_o_at_right;

	if (!(tmp = ft_strnew(min_width)))
	{
		free(f_o);
		return (0);
	}
	c = (!format || ft_strchr(format, (int)'0') == NULL) ? ' ' : '0';
	ft_memset((void*)tmp, (int)c, min_width);
	f_o_at_right = (!format || ft_strchr(format, (int)'-') == NULL) ? 1 : 0;
	ft_strncpy(tmp + ((min_width - ft_strlen(f_o)) * f_o_at_right),
			f_o, ft_strlen(f_o));
	free(f_o);
	f_o = tmp;
	if (format && ft_strchr("di", conv) && ft_strchr(format, '0'))
	{
		while (*tmp == '0')
			tmp++;
		if (*tmp == '+' || *tmp == '-')
		{
			*f_o = *tmp;
			*tmp = '0';
		}
	}
	return (f_o);
}

int				handle_format(char *f_o, t_spec spec)
{
	int		ret;

	if ((size_t)spec.min_width > ft_strlen(f_o))
		if (!(f_o = min_width(f_o,
				spec.min_width - ((*f_o == '\0' && spec.conv == 'c') ? 1 : 0),
				spec.format, spec.conv)))
			return (-1);
	ft_putstr(f_o);
	ret = ft_strlen(f_o);
	if (ret == spec.min_width - 1)
		ft_putchar(f_o[spec.min_width]);
	free(f_o);
	if (spec.conv == 'c')
	{
		if (!*f_o)
			return (1);
		else if (ret < spec.min_width)
			return (spec.min_width);
	}
	return (ret);
}
