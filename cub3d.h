/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:29:29 by hbettal           #+#    #+#             */
/*   Updated: 2024/07/30 00:03:47 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <string.h>
# include <mlx.h>

# define BUFFER_SIZE 100
# define HEIGHT 1000
# define WIDTH 1000
# define TAIL_SIZE 40

typedef struct	s_img
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}	t_img;

typedef struct s_map t_map;
struct s_map
{
	int		width; 
	int		height;
	int		**map; 
};

typedef struct	s_player
{
	int		player_x;
	int		player_y;
	double	player_angle;
	int		line_length;
}	t_player;

typedef struct	s_win
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	char		*img_addrs;
	t_img		*img;
	t_map		*map;
	t_player	*player;
	char		**matrice;
}	t_win;

void	init_function(char **av);
int		key_handler(int key, t_win *win);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
void	creat_2d_world(t_win *win);
char	*get_next_line(int fd);
char	**fill_matrice(char *file);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);

#endif