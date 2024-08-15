/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:42:37 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/15 02:55:53 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int    init_map(t_map *map)
{
	map->height = map_height(map->parser) * TAIL_SIZE;
	map->width =  10 * TAIL_SIZE;
	printf("%d\n", map->height);
	map->mlx = mlx_init(map->width, map->height, "Cub3D", false);
	if (!map->mlx)
	{
		printf(RED_COLOR"Error\nmlx_init failed\n"RESET);
		return (ERROR);
	}
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	if (!map->img)
	{
		printf(RED_COLOR"Error\nmlx_new_image failed\n"RESET);
		return (ERROR);
	}
	return (SUCCESS);
}

void    find_player_pos(t_map *map)
{
	int			i;
	int			j;
	t_parser	*tmp;

	tmp = map->parser->next;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'N')
			{
				map->player->pos->x = TAIL_SIZE * i + TAIL_SIZE / 2;
				map->player->pos->y = TAIL_SIZE * j + TAIL_SIZE / 2;
				return ;
			}
			i++;
		}
		tmp = tmp->next;
		j++;
	}
}

int     init_player(t_player *player, t_map *map)
{
	player->pos = malloc(sizeof(t_cordonnees));
	if (!player->pos)
	{
		printf(RED_COLOR"Error\nmalloc failed\n"RESET);
		return (ERROR);
	}
	find_player_pos(map);
	player->speed = 2.0;
	player->rotation_speed = 2 * (M_PI / 180);
	player->rotation_angle = M_PI / 2;
	player->walk_direction = 0;
	player->turn_direction = 0;
	return (SUCCESS);
}
