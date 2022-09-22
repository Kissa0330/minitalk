/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:49:29 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 00:11:58 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char const *argv[])
{
	// if (argc != 3)
	// 	exit(1);
	kill((pid_t)ft_atoi(argv[1]), SIGUSR1);
	return 0;
}
