/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_str_to_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:33:34 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/30 17:21:54 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BYTE 4

/*
**takes a hex string and returns an unsigned int
**as it returns an unsigned int it will not deal with strings longer than 8byte
**returns 0 if no string is passed
*/

unsigned int	ft_hex_str_to_int(char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (str == NULL)
		return (0);
	while (i < 8)
	{
		result <<= BYTE;
		if (ft_isalpha(str[i]))
		{
			str[i] = ft_toupper(str[i]);
			result |= (str[i] - 'A' + 10);
		}
		else
			result |= (str[i] - '0');
		i++;
	}
	return (result);
}
