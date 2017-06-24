/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:04:34 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/24 02:32:55 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"

typedef struct	s_spec
{
	char		*format;
	int			min_width;
	int			precision;
	char		*length;
	char		conv;
}				t_spec;

typedef	int		(*t_conv_ptr)(va_list ap, t_spec spec);

char			*ft_anytoa(long long n);
char			*ft_uanytoa(unsigned long long n);
char			*ft_uanytoa_base(unsigned long long n, int base);
int				conv_c(va_list ap, t_spec spec);
int				conv_d(va_list ap, t_spec spec);
int				conv_o(va_list ap, t_spec spec);
int				conv_p(va_list ap, t_spec spec);
int				conv_s(va_list ap, t_spec spec);
int				conv_u(va_list ap, t_spec spec);
int				conv_x(va_list ap, t_spec spec);
int				fill_spec(const char *restrict str, t_spec *spec);
int				ft_printf(const char *restrict str, ...);
int				ft_wcharsize(wchar_t wc);
int				ft_wstrlen(wchar_t *ws);
int				ft_wstrsize(wchar_t *ws);
void			ft_putwchar(wchar_t wc);
void			ft_putwnstr(wchar_t *ws, size_t len);
void			ft_wmemset(wchar_t *ws, wchar_t wc, size_t len);
void			ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t n);
wchar_t			*ft_wstrdup(wchar_t *ws);

#endif
