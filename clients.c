/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:49:29 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 00:03:41 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char const *argv[])
{
	// if (argc != 3)
	// 	exit(1);
	kill((pid_t)ft_atoi(argv[1]), SIGSEGV);
	return 0;
}
