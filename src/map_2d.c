/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:47:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/15 15:28:59 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_matrice(t_map *map)
{
	int			i;
	t_parser	*tmp;
	int	flag;

	i = 0;
	tmp = map->parser;
	map->map = malloc(sizeof(char *) * (map_height(tmp) + 1));
	tmp = tmp->next;
	flag = 0;
	while (tmp)
	{
		if (ft_strchr(tmp->line, '1') && !flag)
		{
			flag = 1;
			map->map[i] = ft_strdup(tmp->line);
			i++;
		}
		if (flag)
		{
			map->map[i] = ft_strdup(tmp->line);
			i++;
		}
		tmp = tmp->next;
	}
}

void draw_line(int x0, int y0, int x1, int y1, t_map *map, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_put_pixel(map->img, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void ray_caster(t_map *map)
{
	int	x;
	int	y;
	int x1 = map->player->pos->x + cos(map->player->rotation_angle) * 40;
	int y1 = map->player->pos->y + sin(map->player->rotation_angle) * 40;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x <= map->width)
		{
			if (map->map[y / TAIL_SIZE][x / TAIL_SIZE] == '1' || map->map[y / TAIL_SIZE][x / TAIL_SIZE] == ' ')
				mlx_put_pixel(map->img, x, y, 0xdc143cdc);
			else
				mlx_put_pixel(map->img, x, y, 0xffffffff);
		}
	}
	mlx_put_pixel(map->img, map->player->pos->x, map->player->pos->y, 0x000000);
	int i = 0;
	while (++i < 30)
		draw_line(map->player->pos->x, map->player->pos->y, x1 + i, y1 + i, map, 0x000000);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}
