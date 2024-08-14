/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:47:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/15 00:51:50 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_matrice(t_map *map)
{
	int			i;
	t_parser	*tmp;

	i = 0;
	tmp = map->parser;
	map->map = malloc(sizeof(char *) * (map_height(tmp) + 1));
	tmp = tmp->next;
	while (tmp)
	{
		map->map[i] = ft_strdup(tmp->line);
		printf("--> %s\n", map->map[i]);
		i++;
		tmp = tmp->next;
	}
}

void ray_caster(t_map *map)
{
	int	x;
	int	y;

	fill_matrice(map);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y / TAIL_SIZE][x / TAIL_SIZE] == '1')
				mlx_put_pixel(map->img, x, y, 55656);
			else if (map->map[y / TAIL_SIZE][x / TAIL_SIZE] == '0')
				mlx_put_pixel(map->img, x, y, 0xFFFFFF);
		}
	}
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}