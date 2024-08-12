/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:00:20 by omghazi           #+#    #+#             */
/*   Updated: 2024/08/11 19:41:33 by omghazi          ###   ########.fr       */
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
                if (!ft_strncmp("NO ", ft_strtrim(line, " "), 3) || !ft_strncmp("SO ", ft_strtrim(line, " "), 3) \
                        || !ft_strncmp("WE ", ft_strtrim(line, " "), 3) || !ft_strncmp("EA ", ft_strtrim(line, " "), 3) \
                                || !ft_strncmp("F ", ft_strtrim(line, " "), 2) || !ft_strncmp("C ", ft_strtrim(line, " "), 2))
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

int     check_first_last(t_parser *head)
{
        int     i;

        i = 0;
        while (head && head->line && head->line[i])
        {
                if (head->line[i] != ' ' && head->line[i] != '1' && head->line[i] != '\0' && head->line[i] != '\n')
                        return (printf("%s%s%s\n", RED_COLOR, "Invalid map\n", RESET), ERROR);
                i++;
        }
        return (SUCCESS);
}

int     valid_chararcter(char  c)
{
        return (c == '1' || c == '0' || c == ' ' || c == '\n' || c == '\0' || c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int     check_lines(t_parser *parse, int *n)
{
        int     i;
        
        i = 0;
        while (parse->line[i])
        {
                if (!valid_chararcter(parse->line[i]))
                        return (printf("%s%s%s\n", RED_COLOR, "Invalid map : missing character\n", RESET), ERROR);
                i++;
        }
        i = 0;
        while (parse->line[i])
        {
                if (parse->line[i] == ' ')
                        i++;
                else
                        break;
        }
        if (parse->line[i] == '\0' || parse->line[i] == '\n')
                return (printf("%s%s%s\n", RED_COLOR, "Invalid map : empty line\n", RESET), ERROR);
        i = 0;
        while (parse->line[i])
        {
                if ((parse->line[i] == 'N' || parse->line[i] == 'S' || parse->line[i] == 'W' || parse->line[i] == 'E') && !*n)
                {
                        *n = 1;
                        i++;
                        continue;
                }
                if ((parse->line[i] == 'N' || parse->line[i] == 'S' || parse->line[i] == 'W' || parse->line[i] == 'E') && *n)
                        return (printf("%s%s%s\n", RED_COLOR, "Invalid map : there is more than one player\n", RESET), ERROR);
                i++;
        }
        return (SUCCESS);
}

int    check_map(t_map *map)
{
        t_parser *head;
        int     flag;
        int     n;

        head = map->parser->next;
        flag = 0;
        n = 0;
        while (head && head->next)
        {
                if (!flag && (ft_strchr(head->line, '1') || ft_strchr(head->line, '0')))
                {
                        flag = 1;
                        if (check_first_last(head) == ERROR)
                                return (ERROR);
                }
                if (flag)
                {
                        if (check_lines(head, &n) == ERROR)
                                return (ERROR);
                        if (ft_strtrim(head->line, " ")[0] != '1')
                                return (printf("%s%s%s\n", RED_COLOR, "Invalid map\n", RESET), ERROR);
                        if (head->line[head->len - 2] != '1')
                                return (printf("%s%s%s\n", RED_COLOR, "Invalid map\n", RESET), ERROR);
                }
                head = head->next;
        }
        if (!n)
                return (printf("%s%s%s\n", RED_COLOR, "Invalid map : there is no player\n", RESET), ERROR);
        if (check_first_last(head))
                return (ERROR);
        if (map_height(map->parser) <= 3)
                return (printf("%s%s%s\n", RED_COLOR, "Invalid map\n", RESET), ERROR);
        return (SUCCESS);
}
