/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:49:39 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/24 21:10:45 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include "./libft/libft.h"

#define BIT_SIZE 8

typedef struct s_bit
{
	int	bit[BIT_SIZE];
	int	i;
}	t_bit;


int				*ft_decimal_to_binary(int num);
unsigned int	ft_binary_to_decimal(int *binary);

#endif