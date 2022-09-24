/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:51:12 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/24 21:14:50 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
t_bit bit;

static void Signal1(int code)
{
	(void)code;
	bit.bit[bit.i] = 0;
	// printf("%d\n",bit.bit[bit.i]);
	bit.i++;
	signal(SIGUSR1, Signal1);
}

static void Signal2(int code)
{
	(void)code;
	bit.bit[bit.i] = 1;
	// printf("%d\n",bit.bit[bit.i]);
	bit.i++;
	signal(SIGUSR2, Signal2);
}

int main(void)
{
	char	res;

	bit.i = 0;
	signal(SIGUSR1, Signal1);
	signal(SIGUSR2, Signal2);
	while (1)
	{
		if (bit.i == BIT_SIZE)
		{
			res = ft_binary_to_decimal(bit.bit);
			bit.i = 0;
			write(1, &res, 1);
		}
	}
	return 0;
}
