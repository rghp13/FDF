/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:50:19 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/09 13:33:21 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	rlen;
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		ptr = malloc(sizeof(char) * 1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	rlen = ft_strlen(s + start);
	if (rlen < len)
		len = rlen;
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s + start, len + 1);
	ptr[len] = '\0';
	return (ptr);
}
