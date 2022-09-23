/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:49:29 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 15:33:18 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
static void send_signal(pid_t id, int *bit)
{
	int i = 0;
	while (i < BIT_SIZE)
	{
		sleep(1);
		if (bit[i] == 0)
		{
			printf("0\n");
			kill(id, SIGUSR1);
		}
		else if (bit[i] == 1)
		{
			printf("1\n");
			kill(id, SIGUSR2);
		}
		i ++;
	}
}

int main(int argc, char *argv[])
{
	int	i;
	int	*bit;

	if (argc != 3)
		exit(1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit = ft_decimal_to_binary((int)argv[2][i]);
		send_signal((pid_t)ft_atoi(argv[1]), bit);
		free(bit);
		i ++;
	}
	return 0;
}
