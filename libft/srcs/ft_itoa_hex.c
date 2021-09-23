/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:40:50 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/20 17:17:27 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAXTABLE 16
#define HEXADECIMAL 16

/*
**take an int convert to hex values strdup it and return the str
*/

char	*ft_itoa_hex(unsigned long hex)
{
	char	table[MAXTABLE + 1];
	char	*ptr;
	int		i;

	i = MAXTABLE;
	table[i--] = '\0';
	if (hex == 0)
		table[i--] = '0';
	while (hex > 0 && i >= 0)
	{
		table[i] = hex % HEXADECIMAL;
		if (table[i] >= 0 && table[i] <= 9)
			table[i] += ASCII;
		else if (table[i] > 9 && table[i] <= HEXADECIMAL)
			table[i] += (-10 + 'a');
		i--;
		hex /= HEXADECIMAL;
	}
	i++;
	ptr = ft_strdup(table + i);
	if (ptr == NULL)
		return (NULL);
	else
		return (ptr);
}
