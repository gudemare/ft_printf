/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:35:41 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/16 16:23:12 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*handle_int(va_list ap, t_spec spec)
{
	char	*f_o;
	char	*tmp;

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
	return (f_o);
}
