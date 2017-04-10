/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:35:37 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/10 02:22:11 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_char(va_list ap, t_spec spec)
{
	char	*f_o;

	if (!(f_o = ft_strnew(1)))
		return (0);
	f_o[0] = (char)va_arg(ap, int);
	(void)spec;
	return (f_o);
}
