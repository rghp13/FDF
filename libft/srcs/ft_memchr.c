/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:07:56 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/29 15:02:37 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**the function locates the first occurence of c in s
**returns pointer to it or NULL if can't be found within n bytes
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cmp;
	unsigned char	*src;
	size_t			i;

	cmp = c;
	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (cmp == src[i])
		{
			return ((void *)src + i);
		}
		i++;
	}
	return (NULL);
}
