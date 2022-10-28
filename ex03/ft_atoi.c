/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:27:40 by dcarassi          #+#    #+#             */
/*   Updated: 2022/10/28 21:33:26 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	spacesheck(char *str, int *i_ptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	*i_ptr = i;
	return (sign);
}

int	ft_atoi(char *str)
{
	int	i;
	int	k;
	int	get_sign;

	i = 0;
	k = 0;
	get_sign = spacesheck(str, &i);
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{		
			k *= 10;
			k += str[i] - 48;
			i++;
			if (str[i] < 48 || str[i] > 57)
				break ;
		}
		else
			i++;
	}
	return (k * get_sign);
}
