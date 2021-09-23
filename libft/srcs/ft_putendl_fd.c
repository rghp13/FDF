/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendlfd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:51:52 by rponsonn          #+#    #+#             */
/*   Updated: 2021/01/22 15:13:41 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	char	nl;

	if (s == NULL)
		return ;
	nl = '\n';
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, &nl, 1);
}
