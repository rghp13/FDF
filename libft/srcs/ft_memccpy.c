/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:44:28 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/29 15:01:12 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**the function copies bytes from string src into string dst. if the character c
**as an unsigned char occurs in src, copy stops, and a pointer to the byte after
**the copy of c in the string dst is returned. otherwise n bytes are copied
**and null is returned
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	i = 0;
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	while (i < n)
	{
		to[i] = from[i];
		if (from[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
