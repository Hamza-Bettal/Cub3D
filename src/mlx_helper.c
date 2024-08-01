/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:27:06 by hbettal           #+#    #+#             */
/*   Updated: 2024/07/30 21:03:34 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)data->img_addrs;
	dst[y * WIDTH + x] = color;
}

char	**fill_matrice(char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	**matrice;

	fd = open(file, O_RDONLY, 0644);
	line = get_next_line(fd);
	matrice = malloc(sizeof(char *) * 26);
	matrice[10] = NULL;
	j = 0;
	while (line)
	{
		i = 0;
		matrice[j] = line;
		j++;
		line = NULL;
		line = get_next_line(fd);
	}
	return (matrice);
}

int	check_walls(int x, int y, t_win *win)
{
	if (x + 10 <= 0 || x >= WIDTH || y + 10 <= 0 || y >= HEIGHT)
		return (1);
	if (win->matrice[y / TAIL_SIZE][x / TAIL_SIZE] == '1')
		return (1);
	return (0);
}

int	key_handler(int key, t_win *win)
{
	if (key == 13 && !check_walls(win->player->player_x, win->player->player_y - 10, win)) // 'w'
		win->player->player_y -= 10;
	else if (key == 1 && !check_walls(win->player->player_x, win->player->player_y + 10, win)) // 's'
		win->player->player_y += 10;
	else if (key == 0 && !check_walls(win->player->player_x - 10 , win->player->player_y, win)) // 'a'
		win->player->player_x -= 10;
	else if (key == 2 && !check_walls(win->player->player_x + 10 , win->player->player_y, win)) // 'd'
		win->player->player_x += 10;
	else if (key == 124)
		win->player->player_angle -= 0.2;
	else if (key == 123)
		win->player->player_angle += 0.2;
	else
		return 0;
	creat_2d_world(win);
	return 0;
}
