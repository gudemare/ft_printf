/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:27:11 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/24 01:56:06 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_format(const char *restrict str, char **format)
{
	int		i;
	char	*c;

	i = 0;
	*format = 0;
	while (str[i] && ft_strchr("#0- +", str[i]))
		i++;
	if (i == 0)
		return (0);
	if (!(*format = ft_strndup(str, i)))
		exit(EXIT_FAILURE);
	while (ft_strchr(*format, '+') && (c = ft_strchr(*format, ' ')))
		*c = '+';
	while (ft_strchr(*format, '-') && (c = ft_strchr(*format, '0')))
		*c = '-';
	return (i);
}

static int	fill_width(const char *restrict str, int *width)
{
	int		i;

	i = 0;
	*width = 0;
	if (!ft_isdigit(str[i]))
		return (0);
	*width = ft_atoi(str);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	fill_precision(const char *restrict str, int *precision)
{
	int		i;

	*precision = -1;
	if (*str != '.')
		return (0);
	i = 1;
	*precision = ft_atoi(str + 1);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	fill_length(const char *restrict str, char **length)
{
	int		i;

	i = 0;
	*length = 0;
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		i++;
	if (i != 0)
		if (!(*length = ft_strndup(str, i)))
			exit(EXIT_FAILURE);
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
	if (spec->conv && ft_strchr("COUDS", (int)spec->conv))
	{
		spec->conv += 32;
		if (spec->length && !(ft_strchr(spec->length, (int)'l')))
		{
			if (!(spec->length = ft_strextend(spec->length, 1)))
				exit(EXIT_FAILURE);
			spec->length[ft_strlen(spec->length)] = 'l';
		}
		else if (!spec->length && !(spec->length = ft_strdup("l")))
			exit(EXIT_FAILURE);
	}
	return (i + 1);
}
