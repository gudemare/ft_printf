/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:35:41 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/11 18:37:26 by gudemare         ###   ########.fr       */
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
	(void)spec;
	return (f_o);
}
