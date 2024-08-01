/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:29:29 by hbettal           #+#    #+#             */
/*   Updated: 2024/07/30 22:18:19 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <string.h>
# include <types.h>
# include <MLX42.h>

/* FUNCTIONS */
void	init_function(char **av);
int		key_handler(int key, t_win *win);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
void	creat_2d_world(t_win *win);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	**fill_matrice(char *file);

