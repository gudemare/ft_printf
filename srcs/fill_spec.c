/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:27:11 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/13 23:58:35 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	fill_format(const char *restrict str, char **format)
{
	int		i;
	int		j;

	i = 0;
	*format = 0;
	while (str[i] == '#' || str[i] == '0' || str[i] == '-'
			|| str[i] == ' ' || str[i] == '+')
		i++;
	if (i != 0)
	{
		*format = ft_strnew(i);
		j = i;
		while (j > 0)
		{
			(*format)[j - 1] = str[j - 1];
			j--;
		}
	}
	return (i);
}

static int	fill_width(const char *restrict str, int *width)
{
	int		i;

	i = 0;
	*width = 0;
	while (ft_isdigit(str[i]))
	{
		*width *= 10;
		*width += str[i] - '0';
		i++;
	}
	return (i);
}

static int	fill_precision(const char *restrict str, int *precision)
{
	int		i;

	i = 0;
	*precision = -1;
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			*precision *= 10;
			*precision += str[i] - '0';
			i++;
		}
	}
	return (i);
}

static int	fill_length(const char *restrict str, char **length)
{
	int		i;
	int		j;

	i = 0;
	*length = 0;
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		i++;
	if (i != 0)
	{
		*length = ft_strnew(i);
		j = i;
		while (j > 0)
		{
			(*length)[j - 1] = str[j - 1];
			j--;
		}
	}
	return (i);
}

int			fill_spec(const char *restrict str, t_spec *spec)
{
	int		i;

	i = 1;
	i += fill_format(str + i, &(spec->format));
	i += fill_width(str + i, &(spec->min_width));
	i += fill_precision(str + i, &(spec->precision));
	i += fill_length(str + i, &(spec->length));
	spec->conv = str[i];
	i++;
	return (i);
}
