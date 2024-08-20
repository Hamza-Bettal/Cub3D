/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:47:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/20 19:19:43 by hbettal          ###   ########.fr       */
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

int draw_line(int x0, int y0, int x1, int y1, t_map *map, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;
	int	i = 0;

	while (1)
	{
		mlx_put_pixel(map->img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		if (is_wall(x0, y0, map))
			return (i);
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
		i++;
	}
	return (5000);
}

bool	is_wall(int x, int y, t_map *map)
{
	if (x <= 0 || y <= 0 || x >= map->width || y >= map->height)
		return (true);
	if (map->map[y / TAIL_SIZE][x / TAIL_SIZE] == '1')
		return (true);
	return (false);
}

void	ray_drawer(t_map *map)
{
	int	x;
	int	y;
	int to_draw;

	x = map->width / 2 - 1;
	while (++x < map->width)
	{
		y = -1;
		while (++y <= map->height - 1)
		{
			if (x - (map->width / 2 - 1) <= 200)
				to_draw = (map->height - map->linesize[x - (map->width / 2 - 1)]) / 2;
			if (y <= to_draw || (x - (map->width / 2 - 1) <= 200 && y >= map->linesize[x - (map->width / 2 - 1)]))
				mlx_put_pixel(map->img, x, y, 0xFF);
			else
				mlx_put_pixel(map->img, x, y, 0xFFFFFFFF);
		}
	}
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}

void ray_caster(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y / TAIL_SIZE][x / TAIL_SIZE] == '1' || map->map[y / TAIL_SIZE][x / TAIL_SIZE] == ' ')
				mlx_put_pixel(map->img, x, y, 0xdc143cdc);
			else
				mlx_put_pixel(map->img, x, y, 0xffffffff);
		}
	}
	mlx_put_pixel(map->img, map->player->pos->x, map->player->pos->y, 0x00000000);
	double i = -0.5;
	int	j;
	int x1;
	int y1;
	j = i * 100 + 50;
	while (i < 0.5)
	{
		x1 = map->player->pos->x + cos(map->player->rotation_angle + i) * 5000;
		y1 = map->player->pos->y + sin(map->player->rotation_angle + i) * 5000;
		draw_line(map->player->pos->x, map->player->pos->y, x1, y1, map, 0x000000);
		// map->linesize[j] = 10000 / map->linesize[j] + 10;
		// j++;
		// map->linesize[j] = map->linesize[j - 1];
		// j++;
		i += 0.01;
	}
	// ray_drawer(map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}
