/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:31:31 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/10 02:39:38 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		ret;

	printf("--==[Testing ft_printf (Faulty display...)]==--\nprintf : <");
	ret = printf("Bonjour !");
	printf("> (%d)\nft_printf : <", ret);
	ret = ft_printf("Bonjour !");
	printf("> (%d)\nprintf : <", ret);
	ret = printf("Bonjour %%!");
	printf("> (%d)\nft_printf : <", ret);
	ret = ft_printf("Bonjour %%!");
	printf("> (%d)\nprintf : <", ret);
	ret = printf("Bonjour %c !", 'A');
	printf("> (%d)\nft_printf : <", ret);
	ret = ft_printf("Bonjour %c !", 'A');
	printf("> (%d)\nprintf : <", ret);
	ret = printf("Bonjour %s !", "Xavier");
	printf("> (%d)\nft_printf : <", ret);
	ret = ft_printf("Bonjour %s !", "Xavier");
	printf("> (%d)\nprintf : <", ret);
	ret = printf("Bonjour %d !", 42);
	printf("> (%d)\nft_printf : <", ret);
	ret = ft_printf("Bonjour %d !", 42);
	printf("> (%d)\nprintf : <", ret);
	return (0);
}
