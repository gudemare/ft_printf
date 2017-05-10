/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:04:34 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/10 23:22:24 by gudemare         ###   ########.fr       */
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
	char		conv;
}				t_spec;

char			*handle_int(va_list ap, t_spec spec);
char			*handle_str(va_list ap, t_spec spec);
char			*handle_char(va_list ap, t_spec spec);
int				handle_format(char *f_o, t_spec spec);
char			*handle_conversion(va_list ap, t_spec spec);
int				fill_spec(const char *restrict str, t_spec *spec);
int				ft_printf(const char *restrict str, ...);

#endif
