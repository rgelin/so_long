/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:56:56 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/13 16:45:06 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img_char_down);
	mlx_destroy_image(mlx->mlx, mlx->img_char_up);
	mlx_destroy_image(mlx->mlx, mlx->img_char_left);
	mlx_destroy_image(mlx->mlx, mlx->img_char_rigth);
	mlx_destroy_image(mlx->mlx, mlx->img_background);
	mlx_destroy_image(mlx->mlx, mlx->img_collectible);
	mlx_destroy_image(mlx->mlx, mlx->img_wall);
	mlx_destroy_image(mlx->mlx, mlx->img_exit);
}

void	free_mlx(t_mlx *mlx)
{
	int	i;

	i = -1;
	if (mlx->map)
	{
		while (++i < mlx->map_heigth)
			free (mlx->map[i]);
		free(mlx->map);
	}
	if (mlx)
		free(mlx);
}

int	press_red_cross(t_mlx *mlx)
{
	destroy_image(mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_window);
	free_mlx(mlx);
	exit(EXIT_SUCCESS);
}
