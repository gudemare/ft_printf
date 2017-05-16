/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:35:41 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/16 17:31:25 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*handle_int(va_list ap, t_spec spec)
{
	char	*f_o;
	char	*tmp;
	int		is_signed;

	if (!(f_o = ft_itoa((int)va_arg(ap, int))))
		return (0);
	if (spec.precision == 0 && ft_strcmp(f_o, "0") == 0)
		*f_o = '\0';
	if (*f_o != '-' && ft_strchr("di", spec.conv) && spec.format &&
			(ft_strchr(spec.format, ' ') || ft_strchr(spec.format, '+')))
	{
		if (!(tmp = ft_strjoin((ft_strchr(spec.format, ' ')) ? " " : "+", f_o)))
			return (0);
		free(f_o);
		f_o = tmp;
	}
	is_signed = 1 - ft_isdigit(*f_o);
	if (spec.precision != -1
			&& (size_t)spec.precision > ft_strlen(f_o) - is_signed)
	{
		if (!(tmp = ft_strnew(spec.precision + is_signed)))
			return (0);
		ft_memset(tmp + is_signed, (int)'0',
				spec.precision - ft_strlen(f_o) + is_signed);
		*tmp = (is_signed) ? *f_o : '0';
		ft_strcat(tmp, f_o + is_signed);
		free(f_o);
		f_o = tmp;
	}
	return (f_o);
}
