/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:26:16 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/29 15:12:00 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**duplicates s1 returns the duplicated string
*/

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memcpy(ptr, s1, size + 1);
	return (ptr);
}
