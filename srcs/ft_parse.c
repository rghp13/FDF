/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:45:50 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/30 17:30:21 by rponsonn         ###   ########.fr       */
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
			x = ft_get_word_tally(hold, ' ');
		if (text == NULL)
			text = hold;
		else
			text = ft_free_strjoin(text, hold);
	}
	map = ft_init_map(x, flag, text);
	if (ft_get_word_tally(text, ' ') != (x * flag))
		ft_free_error(2, map);
	ft_fill_color(map);
	map = ft_write_to_map(map);
	free(text);
	return (map);
}

/*
**malloc all the things
*/

t_map	*ft_init_map(int x, int y, char *text)
{
	t_map	*map;
	int		i;

	i = 0;
	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		free(text);
		ft_error(1);
	}
	map->gnl_text = text;
	map->x = x;
	map->y = y;
	map->array = malloc(sizeof(t_point *) * y);
	if (map->array == NULL)
		ft_free_error(1, map);
	while (i < y)
	{
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

t_map	*ft_write_to_map(t_map *map)
{
	int		i;
	char	**split;
	char	*fltptr;

	i = 0;
	split = ft_split(map->gnl_text, ' ');
	while (split[i])
	{
		fltptr = NULL;
		map->array[i / map->x][i % map->x].x = i % map->x;
		map->array[i / map->x][i % map->x].y = i / map->x;
		map->array[i / map->x][i % map->x].z = ft_atoi(split[i]);
		fltptr = ft_strchr(split[i], ',');
		if (fltptr)
			map->array[i / map->x][i % map->x].color = ft_get_color(fltptr);
		i++;
	}
	ft_free_split(split);
	return (map);
}

/*
**Making a libft function that'll take hex string and conv to int
**just need to remove the 0x prefix and complete the hex value
*/

unsigned int	ft_get_color(char *ptr)
{
	int		i;
	int		len;
	char	hex[8];

	ptr++;
	len = ft_strlen(ptr);
	i = 0;
	if (len < 2)
		return (0);
	if (ptr[0] == '0' && (ptr[1] == 'x' || ptr[1] == 'X'))
		ptr += 2;
	len = ft_strlen(ptr);
	while (i < len)
		hex[i] = ptr[i];
	while (i < 8)
		hex[i] = '0';
	return (ft_hex_str_to_int(hex));
}
