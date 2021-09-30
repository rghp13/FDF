/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:29:38 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/30 16:29:46 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	if (map->gnl_text)
		free(map->gnl_text);
	while (map->y > i)
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
	free(map);
	return ;
}