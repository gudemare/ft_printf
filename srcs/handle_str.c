/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:35:39 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/10 23:39:10 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_str(va_list ap, t_spec spec)
{
	char	*f_o;

	if (!(f_o = (spec.precision == -1) ? ft_strdup(va_arg(ap, char *))
				: ft_strndup(va_arg(ap, char *), spec.precision)))
		return (0);
	(void)spec;
	return (f_o);
}
