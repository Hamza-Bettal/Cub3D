/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:59:45 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/15 13:19:59 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void key_handler(mlx_key_data_t key, void *param)
{
    t_map *map = (t_map *)param;
    
    if (key.key == MLX_KEY_A)
        map->player->pos->x -= 2;
    else if (key.key == MLX_KEY_D)
        map->player->pos->x += 2;
    else if (key.key == MLX_KEY_W)
        map->player->pos->y -= 2;
    else if (key.key == MLX_KEY_S)
        map->player->pos->y += 2;
    else if (key.key == MLX_KEY_LEFT)
        map->player->rotation_angle -= 0.2;
    else if (key.key == MLX_KEY_RIGHT)
        map->player->rotation_angle += 0.2;
    else if (key.key == MLX_KEY_ESCAPE)
        exit(0);
    else
        return ;
    ray_caster(map);
}
