/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:04:34 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/09 19:06:09 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_spec
{
	char		*format;
	int			min_width;
	int			precision;
	char		*length;
	char		conv_type;
}				t_spec;

const char		*handle_int(const char *restrict str, va_list ap);
const char		*handle_str(const char *restrict str, va_list ap);
const char		*handle_char(const char *restrict str, va_list ap);
const char		*fill_spec(const char *restrict str, t_spec spec);
int				ft_printf(const char *restrict str, ...);

#endif
