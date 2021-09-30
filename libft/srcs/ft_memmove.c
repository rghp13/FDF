/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:39:19 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/29 15:09:13 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**the function copies len bytes from src to dst. if there is overlap it is
**done in a non destructive manner
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*from;
	unsigned char	*to;
	size_t			i;

	if (dst == src)
		return (NULL);
	from = (unsigned char *)src;
	to = dst;
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			to[len - 1] = from[len - 1];
			len--;
		}
	}
	else
	{
		i--;
		while (++i < len)
			to[i] = from[i];
	}
	return (dst);
}
