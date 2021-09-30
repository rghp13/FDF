/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:50:19 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/29 15:59:58 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**this function makes a substring by starting from string s at position start
**it copies len number of chars but will not go past any null terminator
*/

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
