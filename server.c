/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:51:12 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/24 21:56:09 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
t_bit bit;

static void Signal_handler(int code)
{
	char	res;

	if (code == SIGUSR1)
		signal(SIGUSR1, Signal_handler);
	else if (code == SIGUSR2)
	{
		bit.c = bit.c | 1 << bit.i;
		signal(SIGUSR2, Signal_handler);
	}
	bit.i++;
	if (bit.i == BIT_SIZE)
	{
		res = bit.c;
		bit.i = 0;
		bit.c = 0;
		write(1, &res, 1);
	}
	
}

int main(void)
{
	bit.i = 0;
	bit.c = 0;
	signal(SIGUSR1, Signal_handler);
	signal(SIGUSR2, Signal_handler);
	while (1);
	return 0;
}
