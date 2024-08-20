/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:59:45 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/20 18:06:45 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void key_handler(mlx_key_data_t key, void *param)
{
    t_map *map = (t_map *)param;
    double  sincalc[2];
    double  coscalc[2];
    
    sincalc[0] = map->player->speed * sin(map->player->rotation_angle);
    sincalc[1] = map->player->speed * sin(map->player->rotation_angle + M_PI / 2);
    coscalc[0] = map->player->speed * cos(map->player->rotation_angle);
    coscalc[1] = map->player->speed * cos(map->player->rotation_angle + M_PI / 2);
    if (key.key == MLX_KEY_A && !is_wall(map->player->pos->x - coscalc[1], map->player->pos->y - sincalc[1], map))
    {
        map->player->pos->x -= coscalc[1];
        map->player->pos->y -= sincalc[1];
    }
    else if (key.key == MLX_KEY_D && !is_wall(map->player->pos->x + coscalc[0], map->player->pos->y + sincalc[1], map))
    {
        map->player->pos->x += coscalc[1];
        map->player->pos->y += sincalc[1];
    }
    else if (key.key == MLX_KEY_W && !is_wall(map->player->pos->x + coscalc[0], map->player->pos->y + sincalc[0], map))
    {
        map->player->pos->x += coscalc[0];
        map->player->pos->y += sincalc[0];
    }
    else if (key.key == MLX_KEY_S && !is_wall(map->player->pos->x - coscalc[0], map->player->pos->y - sincalc[0], map))
    {
        map->player->pos->x -= coscalc[0];
        map->player->pos->y -= sincalc[0];
    }
    else if (key.key == MLX_KEY_LEFT)
        map->player->rotation_angle -= 0.05;
    else if (key.key == MLX_KEY_RIGHT)
        map->player->rotation_angle += 0.05;
    else if (key.key == MLX_KEY_ESCAPE)
        exit(0);
    else
        return ;
    mlx_delete_image(map->mlx, map->img);
    map->img = mlx_new_image(map->mlx, map->width, map->height);
    printf("x ----> %f || y ----> %f\n", map->player->pos->x, map->player->pos->y);
    printf("--> %d\n", map->width);
    ray_caster(map);
}
