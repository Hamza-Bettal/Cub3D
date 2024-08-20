/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:42:37 by omghazi           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/08/19 11:38:25 by omghazi          ###   ########.fr       */
=======
/*   Updated: 2024/08/20 07:59:08 by hbettal          ###   ########.fr       */
>>>>>>> 7b231891652cbf34723b43e72e8302f5da14aa1b
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int    init_map(t_map *map)
{
	map->height = map_height(map->parser) * TAIL_SIZE;
<<<<<<< HEAD
	map->width =  (map->largest_line + 2) * TAIL_SIZE;
	
	printf("here %d\n", map->width);
=======
	map->width =  20 * TAIL_SIZE;

>>>>>>> 7b231891652cbf34723b43e72e8302f5da14aa1b
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
				map->player->pos->y = TAIL_SIZE * (j + 1) + TAIL_SIZE / 2;
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
	map->player = player;
	find_player_pos(map);
	player->speed = 2.0;
	player->rotation_speed = 2 * (M_PI / 180);
	player->rotation_angle = 0;
	player->walk_direction = 0;
	player->turn_direction = 0;
	return (SUCCESS);
}
