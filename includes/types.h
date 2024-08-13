/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:35:41 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/13 21:10:54 by omghazi          ###   ########.fr       */
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

typedef struct s_player t_player;
typedef struct s_map t_map;
typedef struct s_img t_img;
typedef struct s_garbage t_garbage;
typedef struct s_cordonnees t_cordonnees;
typedef struct s_parser t_parser;

struct s_map
{
	char	**map;
	int	largest_line;
	int	height;
	int	width;
	void	*mlx;
	void	*win;
	void	*img;
	t_player *player;
	t_garbage *garbage;
	t_parser *parser;
};

struct s_parser
{
	char	*line;
	int		len;
	struct s_parser *next;
};

struct s_player
{
	t_cordonnees	*pos;
	double			speed;
	double			rotation_speed;
	double			rotation_angle;
	double			walk_direction;
	double 			turn_direction;
};

struct s_cordonnees
{
	int x;
	int y;
};

struct s_garbage
{
	void 				*addr;
	struct s_garbage	*next;
};
