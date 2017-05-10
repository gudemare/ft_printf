/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:35:41 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/10 23:47:26 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_int(va_list ap, t_spec spec)
{
	char	*f_o;

	if (!(f_o = ft_itoa((spec.conv == 'u') ? (unsigned int)va_arg(ap, int)
					: (int)va_arg(ap, int))))
		return (0);
	(void)spec;
	return (f_o);
}
