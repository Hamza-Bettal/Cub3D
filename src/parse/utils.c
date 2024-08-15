/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:38:29 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/15 13:27:29 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_parser	*create_node(char *line, int len)
{
	t_parser *new;

	new = malloc(sizeof(t_parser));
	if (!new)
		return (NULL);
	new->line = ft_strdup(line);
	new->len = len;
	new->next = NULL;
	return (new);
}

void	append_node(t_parser **lst, t_parser *node)
{
	t_parser *tmp;

	if (!lst || !node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}
int     map_height(t_parser *parser)
{
        t_parser *tmp;
        int     i;
        int     flag;

        tmp = parser;
        i = 0;
        flag = 0;
        while (tmp)
        {
                if (ft_strchr(tmp->line, '1') && !flag)
                {
                        flag = 1;
                        i++;
                }
                if (flag)
                        i++;
                tmp = tmp->next;
        }
        return (i--);
}
