/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:35:41 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/11 19:07:30 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_int(va_list ap, t_spec spec)
{
	char	*f_o;

	if (!(f_o = ft_itoa((int)va_arg(ap, int))))
		return (0);
	if (spec.precision == 0 && ft_strcmp(f_o, "0") == 0)
		*f_o = '\0';
	if (*f_o != '-' && (spec.conv == 'd' || spec.conv == 'i') && spec.format &&
			(ft_strchr(spec.format, ' ') || ft_strchr(spec.format, '+')))
	{
		if (!(f_o = ft_strextend(f_o, 1)))
			return (0);
		ft_memmove(f_o + 1, f_o, ft_strlen(f_o));
		*f_o = (ft_strchr(spec.format, ' ')) ? ' ' : '+';
	}
	(void)spec;
	return (f_o);
}
