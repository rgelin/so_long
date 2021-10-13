/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:08:07 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/13 18:56:39 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_nb_map_line(t_mlx *mlx, char *av[])
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nCouldn't open file.\n", 26);
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		mlx->map_heigth++;
	}
	close(fd);
}

void	get_map(t_mlx *mlx, char *av[])
{
	int		fd;
	int		i;

	get_nb_map_line(mlx, av);
	fd = open(av[1], O_RDONLY);
	mlx->map = (char **)malloc(sizeof(char *) * mlx->map_heigth);
	if (!mlx->map)
	{
		write(2, "Error\nCouldn't load map.\n", 25);
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < mlx->map_heigth)
		mlx->map[i++] = get_next_line(fd);
	mlx->map_width = ft_strlen(mlx->map[0]);
	close(fd);
}
