/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:06 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/29 15:44:16 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**the function lexicographically compares the null terminated string s1 and s2
**does not compare more than n characters however and data after a \0 will not
**be compared
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	val1;
	unsigned char	val2;
	unsigned int	i;
	int				hold;

	i = 0;
	while (i < n)
	{
		val1 = s1[i];
		val2 = s2[i];
		if (val1 != val2)
		{
			hold = val1 - val2;
			return (hold);
		}
		if (val1 == '\0' && val2 == '\0')
			return (0);
		i++;
	}
	return (0);
}
