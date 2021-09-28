/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:45:50 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/28 18:20:43 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_parse(char *argv)
{
	t_map	*map;
	int		fd;

	fd = open(argv, O_RDONLY);
	map = ft_set_structs(fd);
	close(fd);
}

t_map	*ft_set_structs(int fd)
{
	char	*text;
	char	*hold;
	int		flag;
	int		x;
	t_map	*map;

	text = NULL;
	hold = NULL;
	flag = 0;
	while (get_next_line(fd, &hold))
	{
		if (flag++ == 0)
		{
			x = ft_get_word_tally(hold, ' ');
		}
		if (text == NULL)
			text = hold;
		else
			text = ft_free_strjoin(text, hold);
	}
	map = ft_init_map(x, flag);
	ft_fill_color(map);
	map = ft_write_to_map(map, text);
	free(text);
	return (map);
}

/*
**malloc all the things
*/

t_map	*ft_init_map(int x, int y)
{
	t_map	*map;
	int		i;

	i = 0;
	map = NULL;
	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_error(1);
	map->x = x;
	map->y = y;
	map->array = NULL;
	map->array = malloc(sizeof(t_point *) * y);
	if (map->array == NULL)
		ft_free_error(1, map);
	while (i < x)
	{
		map->array[i] = NULL;
		map->array[i] = malloc(sizeof(t_point) * x);
		if (map->array[i] == NULL)
			ft_free_error(1, map);
		i++;
	}
	return (map);
}

/*
**put the text in
*/

t_map	*ft_write_to_map(t_map *map, char *text)
{
	int		i;
	char	**split;
	int		x;
	int		y;
	char	*fltptr;

	i = 0;
	x = 0;
	y = 0;
	split = ft_split(text, ' ');
	while (split[i])
	{
		fltptr = NULL;
		map->array[y][x].z = ft_atoi(split[i]);
		fltptr = ft_strchr(split[i++], ',');
		if (fltptr)
			map->array[y][x].color = ft_get_color(fltptr);
		if (++x >= map->x)
		{
			x = 0;
			y++;
		}
	}
	ft_free_split(split);
	return (map);
}
