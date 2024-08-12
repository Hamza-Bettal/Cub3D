/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:29:29 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/11 14:37:07 by omghazi          ###   ########.fr       */
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
# include <errno.h>
# include <stdbool.h>
# include <types.h>
# include <MLX42.h>

/* FUNCTIONS */
int     create_table(t_map *map);
int     map_height(t_parser *parser);
int    check_map(t_map *map);
t_parser     *parser(t_map *map, char *file);
void append_node(t_parser **lst, t_parser *node);
t_parser *create_node(char *line, int len);
int     init_player(t_player *player);
int    init_map(t_map *map);
