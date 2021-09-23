/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:21:06 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/09 11:56:04 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_arr2str(char *arr, int max)
{
	char	*ptr;
	int		i;
	int		c;

	i = 0;
	c = max - 1;
	ptr = malloc(sizeof(char) * (max + 1));
	if (ptr == NULL)
		return (NULL);
	while (c >= 0)
	{
		ptr[i++] = arr[c--];
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_zero_string(void)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * 2);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_utoa(unsigned int n)
{
	char		*ptr;
	char		arr[12];
	int			i;

	i = 0;
	if (n == 0)
		return (ptr = ft_zero_string());
	while (n > 0)
	{
		arr[i++] = (n % 10) + ASCII;
		n /= 10;
	}
	ptr = ft_arr2str(arr, i);
	return (ptr);
}
