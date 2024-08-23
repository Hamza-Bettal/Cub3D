/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:47:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/23 21:43:30 by hbettal          ###   ########.fr       */
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
		if (tmp->line[0] != '\n' && !flag)
			flag = 1;
		if (flag)
		{
			map->map[i] = calloc_dyali(map->largest_line + 1, tmp->line);
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

bool	is_wall(int x, int y, t_map *map)
{
	if (x <= 0 || y <= 0 || x >= map->width || y >= map->height)
		return (true);
	if (map->map[y / TAIL_SIZE][x / TAIL_SIZE] == '1')
		return (true);
	return (false);
}

void	find_horizontal_intersections_for_cub3d_by_lbznaz_for_common_core(t_map *map, double angle)
{
	t_cordonnees	step;
	t_cordonnees	intersx;
	t_cordonnees	check;
	t_cordonnees	next_touch;

	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	intersx.y = floor(map->player->pos->y / TAIL_SIZE) * TAIL_SIZE;
	intersx.x = map->player->pos->x + (intersx.y - map->player->pos->y) / tan(angle);
	step.y = TAIL_SIZE;
	if (!(angle > 0 && angle < M_PI))
		step.y *= -1;
	step.x = TAIL_SIZE / tan(angle);
	if (step.x > 0 && (angle > (M_PI / 2) && angle < (1.5 * M_PI)))
		step.x *= -1;
	if (step.x < 0 && !(angle > (M_PI / 2) && angle < (1.5 * M_PI)))
		step.x *= -1;
	next_touch.x = intersx.x;
	next_touch.y = intersx.y;
	while (next_touch.x >= 0 && next_touch.x < map->width && next_touch.y >= 0 && next_touch.y < map->height)
	{
		check.x = next_touch.x;
		check.y = next_touch.y;
		if (!(angle > 0 && angle < M_PI))
			check.y--;
		if (is_wall(check.x, check.y, map))
			break;
		next_touch.x += step.x;
		next_touch.y += step.y;
	}
	if (check.y <= -1)
		check.y = 0;
	map->h_ray = &check;
}

void	find_vertical_intersections_for_cub3d_by_lbznaz_for_common_core(t_map *map, double angle)
{
	t_cordonnees	step;
	t_cordonnees	intersx;
	t_cordonnees	check;
	t_cordonnees	next_touch;

	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	intersx.x = floor(map->player->pos->x / TAIL_SIZE) * TAIL_SIZE;
	intersx.y = map->player->pos->y + (intersx.x - map->player->pos->x) * tan(angle);
	step.x = TAIL_SIZE;
	if (angle > M_PI / 2 && angle < M_PI * 1.5)
		step.x *= -1;
	step.y = TAIL_SIZE * tan(angle);
	if (step.y > 0 && !(angle > 0 && angle < M_PI))
		step.y *= -1;
	if (step.y < 0 && (angle > 0 && angle < M_PI))
		step.y *= -1;
	next_touch.x = intersx.x;
	next_touch.y = intersx.y;
	while (next_touch.x >= 0 && next_touch.x < map->width && next_touch.y >= 0 && next_touch.y < map->height)
	{
		check.x = next_touch.x;
		check.y = next_touch.y;
		if ((angle > M_PI / 2 && angle < M_PI * 1.5))
			check.x--;
		if (is_wall(check.x, check.y, map))
			break;
		next_touch.x += step.x;
		next_touch.y += step.y;
	}
	if (check.x <= -1)
		check.x = 0;
	map->v_ray = &check;
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
		while (++y < map->height)
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

void	distance_cmp(t_map *map)
{
	long h_distance;
	long v_distance;

	h_distance = sqrt(pow(map->h_ray->x, 2) - pow(map->h_ray->y, 2));
	v_distance = sqrt(pow(map->v_ray->x, 2) - pow(map->v_ray->y, 2));
	
	if (v_distance < h_distance)
	{
		map->v_ray->x = map->h_ray->x;
		map->v_ray->y = map->h_ray->y;
	}
}

void ray_caster(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x <= map->width)
		{
			if (map->map[y / TAIL_SIZE][x / TAIL_SIZE] == '0' || map->map[y / TAIL_SIZE][x / TAIL_SIZE] == 'N')
				mlx_put_pixel(map->img, x, y, 0xffffffff);
			else
				mlx_put_pixel(map->img, x, y, 0x00000000);
		}
	}
	mlx_put_pixel(map->img, map->player->pos->x, map->player->pos->y, 0x00000000);
	double i = -0.45;
	while (i < 0.45)
	{
		find_horizontal_intersections_for_cub3d_by_lbznaz_for_common_core(map, map->player->rotation_angle + i);
		find_vertical_intersections_for_cub3d_by_lbznaz_for_common_core(map, map->player->rotation_angle + i);
		distance_cmp(map);
		draw_line(map->player->pos->x, map->player->pos->y, map->v_ray->x, map->v_ray->y, map, 0xFFFFFF);
		i += 0.01;
	}
	// ray_drawer(map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}
