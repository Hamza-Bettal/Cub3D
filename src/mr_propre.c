/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_propre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:37:25 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/11 14:53:39 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_garbage       *create_addr(void *addr)
{
        t_garbage       *new;

        new = malloc(sizeof(t_garbage));
        if (!new)
                return (NULL);
        new->addr = addr;
        new->next = NULL;
        return (new);
}

void    append_addr(t_garbage **garbage, t_garbage *addr)
{
        t_garbage       *tmp;

        if (!garbage || !addr)
                return ;
        if (!*garbage)
        {
                *garbage = addr;
                return ;
        }
        tmp = *garbage;
        while (tmp->next)
                tmp = tmp->next;
        tmp->next = addr;
}

void    mr_propre(t_garbage *garbage)
{
        t_garbage   *tmp;

        while (garbage)
        {
                tmp = garbage;
                garbage = garbage->next;
                free(tmp->addr);
                free(tmp);
        }
}

void    *machi_malloc(size_t size)
{
        char                    *new;
        static t_garbage        *garbage;

        garbage = NULL;
        new = malloc(size);
        append_addr(&garbage, create_addr(new));
        if (!new)
        {
                mr_propre(garbage);
                return(NULL);
        }
        return (new);
}
