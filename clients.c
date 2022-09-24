/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:49:29 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/24 22:16:26 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(pid_t id, char c)
{
	int	i;

	i = 0;
	while (i < BIT_SIZE)
	{
		usleep(200);
		if (!(c & (1 << i)))
			kill(id, SIGUSR1);
		else
			kill(id, SIGUSR2);
		i ++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		*bit;
	pid_t	id;

	if (argc != 3)
		exit(1);
	i = 0;
	id = (pid_t)ft_atoi(argv[1]);
	if (id < 2)
		exit(1);
	while (argv[2][i] != '\0')
	{
		send_signal(id, argv[2][i]);
		i ++;
	}
	exit(0);
}
