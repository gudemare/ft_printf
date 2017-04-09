/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:04:34 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/10 00:16:39 by gudemare         ###   ########.fr       */
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
char			*handle_convertion(va_list ap, t_spec spec);
char			*handle_width(char *str, int width);
int				handle_format(char *str, char *format);
int				fill_spec(const char *restrict str, t_spec spec);
int				ft_printf(const char *restrict str, ...);

#endif
