/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:45:50 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/27 18:18:25 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_parse(char *argv)
{
	t_map	*map;
	int		fd;

	fd = open(argv, O_RDONLY);
	map = ft_set_structs(fd);
}

t_map	*ft_set_structs(int fd)
{
	char	*text;
	char	*hold;
	int		flag;

	text = NULL;
	hold = NULL;
	flag = 0;
	while (get_next_line(fd, &hold))
	{
		if (flag++ == 0)
		{
			ft_x_count(hold);//count the number of entries on the first line
		}
		if (text == NULL)
			text = hold;
		else
			text = ft_free_strjoin(text, hold);
	}
}
