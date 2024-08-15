/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:29:39 by hbettal           #+#    #+#             */
/*   Updated: 2024/08/15 02:52:58 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_file_extention(char *file)
{
	int	fd;
	char	*extention;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("%s%s%s\n", RED_COLOR, strerror(errno), RESET), ERROR);
	extention = ft_strrchr(file, '.');
	if (!ft_strncmp(extention, ".cub", 4) && ft_strlen(extention) != 4)
	{
		printf(RED_COLOR"Invalid file extention\n"RESET);
		return (ERROR);
	}
	return (SUCCESS);
}

int	check_input(int ac, char **av)
{
	if (ac != 2)
	{
		printf(RED_COLOR"Invalid number of argument\n"RESET);
		return (ERROR);
	}
	if (check_file_extention(av[1]) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	main(int ac, char **av)
{	
	t_map		map;
	t_player	player;

	if (check_input(ac, av) == ERROR)
		return (ERROR);
	if (!parser(&map, av[1]))
		return (ERROR);
	if (check_map(&map) == ERROR)
		return (ERROR);
	if (init_map(&map) == ERROR)
		return (ERROR);
	if (init_player(&player, &map) == ERROR)
		return (ERROR);
	fill_matrice(&map);
	ray_caster(&map);
	mlx_key_hook(map.mlx, key_handler, &map);
	mlx_loop(map.mlx);
	return (EXIT_SUCCESS);
}
