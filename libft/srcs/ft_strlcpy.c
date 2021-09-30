/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:06:48 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/29 15:14:29 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**despair all ye who use this function
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	retsize;

	if (!dst || !src)
		return (0);
	retsize = ft_strlen(src);
	if (dstsize > retsize + 1)
	{
		ft_memcpy(dst, src, retsize + 1);
	}
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (retsize);
}
