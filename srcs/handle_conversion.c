/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 00:10:39 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/16 17:20:41 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flags non dispatches : p
*/

char	*handle_conversion(va_list ap, t_spec spec)
{
	char	*f_o;

	if (ft_strchr("diouxX", spec.conv))
	{
		while (spec.format && spec.precision != -1
				&& ft_strchr(spec.format, '0') != NULL)
			*(ft_strchr(spec.format, '0')) = '\26';
		f_o = handle_int(ap, spec);
	}
	else if (spec.conv == 's' || spec.conv == 'S')
		f_o = handle_str(ap, spec);
	else if (spec.conv == '%')
		f_o = ft_strdup("%");
	else
		f_o = handle_char(ap, spec);
	return (f_o);
}
