/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:35:41 by omghazi           #+#    #+#             */
/*   Updated: 2024/07/30 21:01:30 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define RED_COLOR	 "\x1b[31m"
# define YELLOW_COLOR	 "\x1b[33m"
# define GREEN_COLOR	 "\x1b[32m"
# define RESET		 "\x1b[0m"
# define ERROR		 1
# define SUCCESS	 0
# define HEIGHT         1000
# define WIDTH          1000
# define TAIL_SIZE      40


typedef struct s_map t_map;
typedef struct s_img t_img;
typedef struct s_player t_player;
typedef struct s_win t_win;

struct	s_img
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
};

struct s_map
{
	int		width; 
	int		height;
	int		**map; 
};

struct	s_player
{
	int		player_x;
	int		player_y;
	double	        player_angle;
	int		line_length;
};

struct	s_win
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	char		*img_addrs;
	t_img		*img;
	t_map		*map;
	t_player	*player;
	char		**matrice;
};
