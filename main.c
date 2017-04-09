/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:31:31 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/04 15:00:49 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	ft_printf("Bonjour ! \n");
	ft_printf("Bonjour ! %%%%\n");
	ft_printf("%s %d\n", "Bonjour", 569);
	ft_printf("%d\n", 526);
	return (0);
}
