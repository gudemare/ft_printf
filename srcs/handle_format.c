/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 00:09:49 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/10 02:49:14 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		handle_format(char *f_o, t_spec spec)
{
	int		ret;

	(void)spec;
	ret = ft_strlen(f_o);
	ft_putstr(f_o);
	free(f_o);
	return (ret);
}
