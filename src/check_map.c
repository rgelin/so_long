/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:41:03 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/13 17:09:50 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_map_character(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map_heigth)
	{
		j = -1;
		while (++j < mlx->map_width)
		{
			if (mlx->map[i][j] == 'E')
				mlx->exit++;
			if (mlx->map[i][j] == 'P')
				mlx->player++;
			if (mlx->map[i][j] == 'C')
				mlx->collectible++;
			if (mlx->map[i][j] != 'E' && mlx->map[i][j] != 'P' &&
				mlx->map[i][j] != 'C' && mlx->map[i][j] != '0' &&
				mlx->map[i][j] != '1')
				return (1);
		}
	}
	return (0);
}

static int	check_map_surounded(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->map_width)
	{
		if (mlx->map[0][i] != '1' || mlx->map[mlx->map_heigth - 1][i] != '1')
		{
			write(2, "Error\nMap is not surrounded by walls.\n", 38);
			return (1);
		}
	}
	i = -1;
	while (++i < mlx->map_heigth)
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][mlx->map_width - 1] != '1')
		{
			write(2, "Error\nMap is not surrounded by walls.\n", 38);
			return (1);
		}
	}
	return (0);
}

static int	check_map_size(t_mlx *mlx)
{
	int	i;

	if (mlx->map_heigth == mlx->map_width)
	{
		write(2, "Error\nMap is not rectangular.\n", 31);
		return (1);
	}
	i = -1;
	while (++i < mlx->map_heigth)
	{
		if (ft_strlen(mlx->map[i]) != mlx->map_width)
		{
			write(2, "Error\nMap has not same lines length.\n", 37);
			return (1);
		}
	}
	return (0);
}

void	check_map(t_mlx *mlx)
{
	if (check_map_size(mlx) || check_map_surounded(mlx))
	{
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
	if (check_map_character(mlx))
	{
		write(2, "Error\n", 6);
		write(2, "Invalid map character (only [0,1,P,C,E] are allowed).\n", 54);
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx->exit < 1 || mlx->player < 1 || mlx->collectible < 1)
	{
		write(2, "Error\n", 6);
		write(2, "Map is missing one or more character between [P,C,E].\n", 54);
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
}
