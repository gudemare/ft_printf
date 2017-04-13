/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:26:43 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/08 14:31:44 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnendl_fd(char const *s, int fd, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i < n)
		i++;
	write(fd, s, i);
	write(fd, "\n", 1);
}
