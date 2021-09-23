/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:34:38 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/09 11:57:23 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char str)
{
	int	flag;

	flag = 0;
	if (str == ' ')
		flag = 1;
	else if (str >= '\t' && str <= '\r')
		flag = 1;
	return (flag);
}

int	ft_atoi(const char *str)
{
	unsigned long int	num;
	int					i;
	int					neg;

	i = 0;
	neg = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (10 * num) + (str[i++] - '0');
	if (num > 0x7fffffff && neg == 0)
		return (-1);
	if (num > 0xffffffff && neg == 1)
		return (0);
	if (neg % 2)
		num = -num;
	return (num);
}
