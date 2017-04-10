/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_convertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 00:10:39 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/10 02:09:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_convertion(va_list ap, t_spec spec)
{
	char	*f_o;

	if (spec.conv == 'd' || spec.conv == 'D' || spec.conv == 'i'
		|| spec.conv == 'o' || spec.conv == 'O' || spec.conv == 'p'
		|| spec.conv == 'u' || spec.conv == 'U' || spec.conv == 'x'
		|| spec.conv == 'X')
		f_o = handle_int(ap, spec);
	else if (spec.conv == 's' || spec.conv == 'S')
		f_o = handle_str(ap, spec);
	else
		f_o = handle_char(ap, spec);
	return (f_o);
}
