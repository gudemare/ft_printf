/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:27:11 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/09 19:58:28 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static const char	*fill_format(const char *restrict str, char	**format)
{
	int		i;

	i = 0;
	*format = 0;
	while (str[i] == '#' || str[i] == '0' || str[i] == '-'
			|| str[i] == ' ' || str[i] == '+')
		i++;
	if (i != 0)
	{
		*format = ft_strnew(i);
		while (i > 0)
		{
			(*format)[i - 1] = str[i - 1];
			i--;
		}
	}
	return (str + i);
}

static const char	*fill_width(const char *restrict str, int *width)
{
	*width = 0;
	while (ft_isdigit(*str))
	{
		*width *= 10;
		*width += *str - '0';
		str++;
	}
	return (str);
}

static const char	*fill_precision(const char *restrict str, int *precision)
{
	*precision = 0;
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			*precision *= 10;
			*precision += *str - '0';
			str++;
		}
	}
	return (str);
}

static const char	*fill_length(const char *restrict str, char	**length)
{
	int		i;

	i = 0;
	*length = 0;
	while (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		i++;
	if (i != 0)
	{
		*length = ft_strnew(i);
		while (i > 0)
		{
			*length[i - 1] = str[i - 1];
			i--;
		}
	}
	return (str + i);
}

const char		*fill_spec(const char *restrict str, t_spec spec)
{
	str++;
	str = fill_format(str, &(spec.format));
	str = fill_width(str, &(spec.min_width));
	str = fill_precision(str, &(spec.precision));
	str = fill_length(str, &(spec.length));
	spec.conv_type = *str;	
	str++;
	return (str);
}
