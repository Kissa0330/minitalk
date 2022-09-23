/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:48:58 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 12:59:53 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	*change_to_binarynum(int *binarynum, int num, int negativeflag)
{
	int	i;

	i = BIT_SIZE - 1;
	if (negativeflag == 1)
	{
		num = num * -1 - 1;
		while (num && i >= 0)
		{
			binarynum[i] -= num % 2;
			num /= 2;
			i --;
		}
	}
	else if (negativeflag == 0)
	{
		while (num && i >= 0)
		{
			binarynum[i] += num % 2;
			num /= 2;
			i --;
		}
	}
	return (binarynum);
}

int	*ft_decimaltobinary(int num)
{
	int	*res;
	int	initial;
	int	i;

	res = malloc(sizeof(int) * BIT_SIZE);
	if (num < 0)
		initial = 1;
	else if (0 <= num)
		initial = 0;
	i = 0;
	while (i < BIT_SIZE)
		res[i++] = initial;
	return (change_to_binarynum(res, num, initial));
}