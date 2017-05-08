/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 00:09:49 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/08 23:57:26 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char		*min_width(char *f_o, int min_width, char *format)
{
	char	*tmp;
	char	c;
	int		i;

	if (!(tmp = ft_strnew(min_width)))
	{
		free(f_o);
		return (0);
	}
	i = 0;
	c = (!format || ft_strchr(format, (int)'0') == NULL) ? ' ' : '0';
	while (i < min_width)
	{
		tmp[i] = c;
		i++;
	}
	ft_strcpy(tmp + min_width - ft_strlen(f_o), f_o);
	free(f_o);
	f_o = tmp;
	return (f_o);
}

int				handle_format(char *f_o, t_spec spec)
{
	int		ret;

	if ((size_t)spec.min_width > ft_strlen(f_o))
		if (!(f_o = min_width(f_o, spec.min_width, spec.format)))
			return (-1);
	(void)spec;
	ret = ft_strlen(f_o);
	ft_putstr(f_o);
	free(f_o);
	return (ret);
}
