/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:59:45 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/20 04:02:38 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void key_handler(mlx_key_data_t key, void *param)
{
    t_map *map = (t_map *)param;
    
    if (key.key == MLX_KEY_A && !is_wall(map->player->pos->x - 2, map->player->pos->y, map))
    {
        map->player->pos->x -= map->player->speed * cos(map->player->rotation_angle + M_PI / 2);
        map->player->pos->y -= map->player->speed * sin(map->player->rotation_angle + M_PI / 2);
    }
    else if (key.key == MLX_KEY_D && !is_wall(map->player->pos->x + 2, map->player->pos->y, map))
    {
        map->player->pos->x += map->player->speed * cos(map->player->rotation_angle + M_PI / 2);
        map->player->pos->y += map->player->speed * sin(map->player->rotation_angle + M_PI / 2);
    }
    else if (key.key == MLX_KEY_W && !is_wall(map->player->pos->x, map->player->pos->y - 2, map))
    {
        map->player->pos->x += map->player->speed * cos(map->player->rotation_angle);
        map->player->pos->y += map->player->speed * sin(map->player->rotation_angle);
    }
    else if (key.key == MLX_KEY_S && !is_wall(map->player->pos->x, map->player->pos->y + 2, map))
    {
        map->player->pos->x -= map->player->speed * cos(map->player->rotation_angle);
        map->player->pos->y -= map->player->speed * sin(map->player->rotation_angle);
    }
    else if (key.key == MLX_KEY_LEFT)
        map->player->rotation_angle -= 0.2;
    else if (key.key == MLX_KEY_RIGHT)
        map->player->rotation_angle += 0.2;
    else if (key.key == MLX_KEY_ESCAPE)
        exit(0);
    else
        return ;
    mlx_delete_image(map->mlx, map->img);
    map->img = mlx_new_image(map->mlx, map->width, map->height);
    ray_caster(map);
}
