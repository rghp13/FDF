/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:36:24 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/29 15:14:00 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**take s1 and s2 and merges them into a 3rd string
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[len] = '\0';
	return (ptr);
}

/*
**if you want to free the s1 and s2 then use this
**will free even if the strjoin fails
*/

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*output;

	output = NULL;
	output = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (output);
}
