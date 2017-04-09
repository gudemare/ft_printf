/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:04:34 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/09 23:54:30 by gudemare         ###   ########.fr       */
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

int				handle_int(const char *restrict str, va_list ap);
int				handle_str(const char *restrict str, va_list ap);
int				handle_char(const char *restrict str, va_list ap);
int				fill_spec(const char *restrict str, t_spec spec);
int				ft_printf(const char *restrict str, ...);

#endif
