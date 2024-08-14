/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:42:37 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/14 23:15:54 by hbettal          ###   ########.fr       */
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

int     init_player(t_player *player, t_map *map)
{
        player->pos = malloc(sizeof(t_cordonnees));
        if (!player->pos)
        {
                printf(RED_COLOR"Error\nmalloc failed\n"RESET);
                return (ERROR);
        }
        player->pos->x = map->width / 2;
        player->pos->y = map->height / 2;
        player->speed = 2.0;
        player->rotation_speed = 2 * (M_PI / 180);
        player->rotation_angle = M_PI / 2;
        player->walk_direction = 0;
        player->turn_direction = 0;
        return (SUCCESS);
}
