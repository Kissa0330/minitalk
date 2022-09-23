/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:51:12 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 13:10:48 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
static void Signal1(int code)
{
	printf("0\n");
	signal(SIGUSR1, Signal1);
}

static void Signal2(int code)
{
	printf("1\n");
	signal(SIGUSR2, Signal2);
}

int main(void)
{
	signal(SIGUSR1, Signal1);
	signal(SIGUSR2, Signal2);
	while (1);
	return 0;
}
