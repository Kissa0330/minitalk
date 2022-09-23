/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:49:29 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 13:07:03 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
static void send_signal(pid_t id, int *bit)
{
	int i = 0;
	while (i < BIT_SIZE)
	{
		printf("%d", bit[i]);
		if (bit[i] == 0)
			kill(id, SIGUSR1);
		else if (bit[i] == 1)
			kill(id, SIGUSR2);
		i ++;
	}
	printf("\n");
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
		printf("%d\n", (int)argv[2][i]);
		bit = ft_decimaltobinary((int)argv[2][i]);
		send_signal((pid_t)ft_atoi(argv[1]), bit);
		free(bit);
		i ++;
	}
	return 0;
}
