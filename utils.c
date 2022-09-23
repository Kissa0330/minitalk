/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:48:58 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 13:22:20 by takanoraika      ###   ########.fr       */
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

int	*ft_decimal_to_binary(int num)
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

unsigned int	ft_binary_to_decimal(int *binary)
{
	int				i;
	unsigned int	decimal;
	unsigned int	multiplynum;

	i = BIT_SIZE - 1;
	decimal = 0;
	multiplynum = 1;
	while (i >= 0)
	{
		decimal += binary[i] * multiplynum;
		multiplynum *= 2;
		i--;
	}
	return (decimal);
}