/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:10:44 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/27 17:59:09 by rponsonn         ###   ########.fr       */
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
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_map {
	t_point	**array;
}			t_map;

#endif