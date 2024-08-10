/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:42:37 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/10 15:59:09 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int    init_map(t_map *map)
{
        map->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
        if (!map->mlx)
        {
                printf(RED_COLOR"Error\nmlx_init failed\n"RESET);
                return (ERROR);
        }
        map->img = malloc(sizeof(t_img));
        if (!map->img)
        {
                printf(RED_COLOR"Error\nmalloc failed\n"RESET);
                return (ERROR);
        }
        map->img->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
        if (!map->img->img)
        {
                printf(RED_COLOR"Error\nmlx_new_image failed\n"RESET);
                return (ERROR);
        }
        return (SUCCESS);
}

int     init_player(t_player *player)
{
        player->pos = malloc(sizeof(t_cordonnees));
        if (!player->pos)
        {
                printf(RED_COLOR"Error\nmalloc failed\n"RESET);
                return (ERROR);
        }
        player->pos->x = WIDTH / 2;
        player->pos->y = HEIGHT / 2;
        player->speed = 2.0;
        player->rotation_speed = 2 * (M_PI / 180);
        player->rotation_angle = M_PI / 2;
        player->walk_direction = 0;
        player->turn_direction = 0;
        return (SUCCESS);
}
