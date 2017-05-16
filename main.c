/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:31:31 by gudemare          #+#    #+#             */
/*   Updated: 2017/05/16 18:09:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		ret;

	printf("--==[Testing ft_printf]==--\nprintf :\n");
	ret = printf("{% 03d}", 0);
	printf("\n(%d)\nft_printf :\n", ret);
	ret = ft_printf("{% 03d}", 0);
	printf("\n(%d)\n", ret);
/*	printf("printf :\n");
	ret = printf("Bonjour |%5d|%-12s|%3c|%#0- +10.3hh%|%+.0d|%8s|%.2c|%p"
			, 42, "Xavier", 'A', 0, NULL, NULL, &ret);
	printf("\n(%d)\nft_printf :\n", ret);
	ret = ft_printf("Bonjour |%5d|%-12s|%3c|%#0- +10.3hh%|%+.0d|%8s|%.2c|%p"
			, 42, "Xavier", 'A', 0, NULL, NULL, &ret);
	printf("\n(%d)\n", ret);*/
	return (0);
}
