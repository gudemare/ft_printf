/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:35:37 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/09 19:27:22 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//'c' only

const char	*handle_char(const char *restrict str, va_list ap)
{
	char	*ret;

	ret = ft_strnew(1);
	*ret = (unsigned char)va_arg(ap, int);
	(void)str;
	return (ret);
}
