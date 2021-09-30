/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:31:45 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/30 17:36:28 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_color(t_map *map)
{
	int	i;

	i = 0;
	while (map->y > (i / map->x))
	{
		map->array[i / map->x][i % map->x].color = 0xFFFFFF;
		i++;
	}
	return ;
}