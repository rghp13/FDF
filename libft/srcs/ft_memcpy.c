/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:02:18 by rponsonn          #+#    #+#             */
/*   Updated: 2021/01/26 13:55:11 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*xfr;

	i = 0;
	if (dst == src)
		return (dst);
	ptr = (unsigned char *)dst;
	xfr = (unsigned char *)src;
	while (i < n)
	{
		*ptr++ = *xfr++;
		i++;
	}
	return (dst);
}
