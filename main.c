/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:31:31 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/19 22:04:06 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		ret;

	printf("--==[Testing ft_printf]==--\nprintf :\n");
	ret = printf("Bonjour %5d %12s %3c %#0- +10.3hh%!\n", 42, "Xavier", 'A');
	printf("(%d)\nft_printf :\n", ret);
	ret = ft_printf("Bonjour %5d %12s %3c %#0- +10.3hh%!\n", 42, "Xavier", 'A');
	printf("(%d)\n", ret);
	return (0);
}
