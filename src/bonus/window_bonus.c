/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:46:18 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/13 17:09:00 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_background(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_heigth * NB_PIXEL)
	{
		x = 0;
		while (x < mlx->map_width * NB_PIXEL)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_window,
				mlx->img_background, x, y);
			x += mlx->x_back;
		}
		y += mlx->y_back;
	}
}

void	init_image(t_mlx *mlx, t_img *img)
{
	mlx->img_background = mlx_xpm_file_to_image(mlx->mlx,
			"./images/Grass.xpm", &mlx->x_back, &mlx->y_back);
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx,
			"./images/Wood.xpm", &img->x_wall, &img->y_wall);
	mlx->img_char_down = mlx_xpm_file_to_image(mlx->mlx,
			"./images/Char_down.xpm", &img->x_char_down, &img->y_char_down);
	mlx->img_char_up = mlx_xpm_file_to_image(mlx->mlx,
			"./images/Char_up.xpm", &img->x_char_up, &img->y_char_up);
	mlx->img_char_left = mlx_xpm_file_to_image(mlx->mlx,
			"./images/Char_left.xpm", &img->x_char_left, &img->y_char_left);
	mlx->img_char_rigth = mlx_xpm_file_to_image(mlx->mlx,
			"./images/Char_right.xpm", &img->x_char_rigth, &img->y_char_rigth);
	mlx->img_collectible = mlx_xpm_file_to_image(mlx->mlx,
			"./images/Blue_orb.xpm", &img->x_collect, &img->y_collect);
	mlx->img_exit = mlx_xpm_file_to_image(mlx->mlx,
			"./images/Door.xpm", &img->x_exit, &img->y_exit);
	if (!mlx->img_background || !mlx->img_wall || !mlx->img_char_down
		|| !mlx->img_char_up || !mlx->img_char_left || !mlx->img_char_rigth
		|| !mlx->img_collectible || !mlx->img_exit)
	{
		write(2, "Error loading sprite\n", 21);
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_window_texture_bonus(t_mlx *mlx)
{
	t_img	img;

	init_image(mlx, &img);
	put_background(mlx);
	put_map_window(mlx);
	mlx_string_put(mlx->mlx, mlx->mlx_window,
		mlx->map_width * NB_PIXEL - 100, 0, 0x00FFFFFF, "Moves: 0");
}

static void	put_img_to_window(t_mlx *mlx, int i, int j)
{
	if (mlx->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window,
			mlx->img_wall, j * NB_PIXEL, i * NB_PIXEL);
	if (mlx->map[i][j] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img_char_down,
			(j * NB_PIXEL) + 10, (i * NB_PIXEL) + 10);
		mlx->pos_player_x = j;
		mlx->pos_player_y = i;
		mlx->map[i][j] = '0';
	}
	if (mlx->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img_collectible,
			(j * NB_PIXEL) + 10, (i * NB_PIXEL) + 10);
	if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img_exit,
			(j * NB_PIXEL) + 10, (i * NB_PIXEL) - 10);
}

void	put_map_window(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map_heigth)
	{
		j = 0;
		while (j < mlx->map_width)
		{
			put_img_to_window(mlx, i, j);
			j++;
		}
		i++;
	}
}
