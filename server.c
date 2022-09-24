/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:51:12 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/24 22:30:13 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit	g_bit;

static void	signal_handler(int code)
{
	char	res;

	if (code == SIGUSR1)
		signal(SIGUSR1, signal_handler);
	else if (code == SIGUSR2)
	{
		g_bit.c = g_bit.c | 1 << g_bit.i;
		signal(SIGUSR2, signal_handler);
	}
	g_bit.i++;
	if (g_bit.i == BIT_SIZE)
	{
		res = g_bit.c;
		g_bit.i = 0;
		g_bit.c = 0;
		write(1, &res, 1);
	}
}

int	main(void)
{
	g_bit.i = 0;
	g_bit.c = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		;
	return (0);
}
