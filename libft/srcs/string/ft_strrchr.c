/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 05:22:47 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/04 05:26:15 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0 && s[i] != (char)c)
		i--;
	if (i == 0 && s[i] != c)
		return (NULL);
	return ((char *)&s[i]);
}
