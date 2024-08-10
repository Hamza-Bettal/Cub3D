/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:00:20 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/10 21:32:31 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_parser     *parser(t_map *map, char *file)
{
        t_parser        *parser;
        static int           i;
        char            *line;
        int             fd;
        char            **str;

        parser = NULL;
        fd = open(file, O_RDONLY);
        if (fd == -1)
                return (printf("%s%s%s\n", RED_COLOR, strerror(errno), RESET), NULL);
        line = get_next_line(fd);
        while (line)
        {
                if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3) \
                        || !ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3) \
                                || !ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
                {
                        if (i >= 6)
                                return (printf("%s%s%s\n", RED_COLOR, "Too many information\n", RESET), NULL);
                        i++;
                }
                if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
                {
                        str = ft_split(strrchr(line, ' '), ',');
                        while (*str)
                        {
                                if (ft_atoi(*str) < 0 || ft_atoi(*str) > 255)
                                        return (printf("%s%s%s\n", RED_COLOR, "Invalid color\n", RESET), NULL);
                                str++;
                        }
                }
                if (i >= 6)
                        append_node(&parser, create_node(line, ft_strlen(line)));
                free(line);
                line = get_next_line(fd);
        } 
        if (i != 6)
                return (printf("%s%s%s\n", RED_COLOR, "Missing information\n", RESET), NULL);
        close(fd);
        map->parser = parser;
        return (parser);
}


int     check_first_last(char *line)
{
        int     i;

        i = 0;
        while (line[i])
        {
                if (line[i] == '0')
                        return (printf("%s%s%s\n", RED_COLOR, "Invalid map\n", RESET), ERROR);
                i++;
        }
        return (SUCCESS);
}

int    check_map(t_map *map)
{
        t_parser *head;
        int     flag;

        head = map->parser->next;
        flag = 0;
        while (head->next)
        {
                if (ft_strchr(head->line, ft_isdigit(head->line[0])) && !flag)
                {
                        flag = 1;
                        if (check_first_last(head->line) == ERROR)
                                return (ERROR);
                }
                head = head->next;
        }
        if (check_first_last(head->line))
                return (ERROR);
        return (SUCCESS);
}
