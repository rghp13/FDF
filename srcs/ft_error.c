/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:49:56 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/30 16:30:15 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**error 1 is malloc error
**error 2 is malformed map
*/

void	ft_free_error(int erno, t_map *map)
{
	ft_free(map);
	if (erno == 1)
	{
		printf("Error, Unable to Malloc\n");
		exit(1);
	}
	else if (erno == 2)
	{
		printf("Error, Map Shape error\n");
		exit(2);
	}
}
