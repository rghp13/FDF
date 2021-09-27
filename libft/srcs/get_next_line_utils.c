/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:39:28 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/27 17:55:08 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strjoin(char **s1, const char *s2)
{
	int		len;
	char	*ptr;

	if (*s1 == NULL)
		return (ft_strdup(s2));
	len = ft_strlen(*s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, *s1, ft_strlen(*s1));
	ft_memcpy(ptr + ft_strlen(*s1), s2, ft_strlen(s2));
	ptr[len] = '\0';
	free(*s1);
	*s1 = NULL;
	return (ptr);
}
