/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:38:29 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/13 17:36:32 by hbettal          ###   ########.fr       */
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

void	delete_node(t_parser **lst, void (*del)(void *))
{
	t_parser        *tmp;
	
	if (!lst || !*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	del(tmp);
}

void	clear_list(t_parser **lst, void (*del)(void *))
{
	t_parser *tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del(tmp);
	}
}
