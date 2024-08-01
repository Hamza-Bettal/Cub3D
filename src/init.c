/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:28:38 by hbettal           #+#    #+#             */
/*   Updated: 2024/07/30 22:44:16 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_line(t_win *win, int player_x, int player_y, int pos_x, int pos_y, int color)
{
    int dx = abs(pos_x - player_x);
    int sx = player_x < pos_x ? 1 : -1;
    int dy = -abs(pos_y - player_y);
    int sy = player_y < pos_y ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (1)
    {
        my_mlx_pixel_put(win, player_x, player_y, color);
        if (player_x == pos_x && player_y == pos_y)
            break ;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            player_x += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            player_y += sy;
        }
    }
}

void	creat_2d_world(t_win *win)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	y = -1;
	win->player->line_length = 60;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if ((x >= win->player->player_x && x <= win->player->player_x + 10) && (y >= win->player->player_y && y <= win->player->player_y + 10))
					my_mlx_pixel_put(win, x, y, 0xFFFF);
			// else if (x % 40 == 0 || y % 40 == 0)
			// 	my_mlx_pixel_put(win, x, y, 0);
			else if (win->matrice[y/TAIL_SIZE][x/TAIL_SIZE] == '1')
				my_mlx_pixel_put(win, x, y, 0);
			else 
				my_mlx_pixel_put(win, x, y, 16777215);
		}
	}
	float i = 0;
	while (i < 90)
	{
		pos_x = win->player->player_x + cos(win->player->player_angle * i ) * win->player->line_length;
		pos_y = win->player->player_y + sin(win->player->player_angle * i ) * win->player->line_length;
		draw_line(win, win->player->player_x, win->player->player_y, pos_x, pos_y, 0xFF);
		i++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->mlx_img, 0, 0);
}

void	init_function(char **av)
{
	t_win	*win;
	t_img	img;
	t_map	map;
	t_player	player;
	
	win = malloc(sizeof(t_win));
	if (!win)
		(perror("error"), exit(1));
	win->player = &player;
	win->player->player_angle = 0;
	win->player->player_x = WIDTH / 2;
	win->player->player_y = HEIGHT / 2;
	win->matrice = fill_matrice(av[1]);
	win->img = &img;
	win->map = &map;
	win->mlx = mlx_init(WIDTH, HEIGHT, "Cube", true);
	if (!win->mlx)
		(perror("error"), exit(1));
	win->mlx_win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "DOOM");
	win->mlx_img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->img_addrs = mlx_get_data_addr(win->mlx_img, \
		&win->img->bits_per_pixel, &win->img->size_line, &win->img->endian);
	creat_2d_world(win);
	mlx_hook(win->mlx_win, 2, 1L<<0, key_handler, win);
	mlx_loop(win->mlx);
}
