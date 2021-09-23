/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:37:15 by rponsonn          #+#    #+#             */
/*   Updated: 2021/01/19 14:27:51 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	copy;
	unsigned char	*ptr;
	size_t			i;

	copy = c;
	i = 0;
	ptr = str;
	while (i < len)
	{
		*ptr++ = copy;
		i++;
	}
	return (str);
}
