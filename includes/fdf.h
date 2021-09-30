/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:10:44 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/30 17:18:14 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "../minilibx_macos/mlx.h"

# define XSIZE 1920
# define YSIZE 1080

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point {
	float			x;
	float			y;
	float			z;
	unsigned int	color;
}			t_point;

typedef struct s_map {
	t_point	**array;
	int		x;
	int		y;
	char	*gnl_text;
}			t_map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_map	*ft_parse(char *argv);
t_map	*ft_set_structs(int fd);
t_map	*ft_init_map(int x, int y, char *text);
t_map	*ft_write_to_map(t_map *map);
void	ft_free_error(int erno, t_map *map);
void	ft_free(t_map *map);

#endif