/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:58:39 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/12 17:14:50 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int     create_table(t_map *map)
{
        t_parser *tmp;
        int     flag;

        flag = 0;
        tmp = map->parser->next;
        while (tmp)
        {
                tmp = tmp->next;
        }
        return (SUCCESS);
}
