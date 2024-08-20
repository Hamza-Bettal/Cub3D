/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:58:39 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/19 11:37:20 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int     stock_largest_line(t_map *map)
{
        t_parser *tmp;
        t_parser *prev;
        int     flag;

        flag = 0;
        tmp = map->parser->next;
        prev = NULL;
        while (tmp)
        {
                if (tmp->line[0] != '\n' && !flag)
                        flag = 1;
                if (flag)
                {
                        printf("%d\n", tmp->len);
                        if (prev && prev->len <= tmp->len)
                                map->largest_line = tmp->len;
                }
                prev = tmp;
                tmp = tmp->next;
        }
        return (SUCCESS);
}
