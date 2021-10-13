/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:22:11 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/13 17:07:12 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	check_map_fit_screen(t_mlx *mlx)
{
	mlx_get_screen_size(mlx->mlx, &mlx->screen_width, &mlx->screen_heigth);
	if (mlx->screen_width < mlx->map_width * NB_PIXEL
		|| mlx->screen_heigth < mlx->map_heigth * NB_PIXEL)
	{
		write(2, "Error\nMap is too big for your screen.\n", 38);
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
}

static void	init_struct(t_mlx *mlx)
{
	mlx->map = NULL;
	mlx->map_heigth = 0;
	mlx->map_width = 0;
	mlx->player = 0;
	mlx->exit = 0;
	mlx->collectible = 0;
	mlx->pos_player_x = 0;
	mlx->pos_player_y = 0;
	mlx->nb_move = 0;
	mlx->img_background = NULL;
	mlx->img_char_down = NULL;
	mlx->img_char_up = NULL;
	mlx->img_char_left = NULL;
	mlx->img_char_rigth = NULL;
	mlx->img_actual_char = NULL;
	mlx->img_wall = NULL;
	mlx->img_collectible = NULL;
	mlx->img_exit = NULL;
}

int	main(int ac, char *av[])
{
	t_mlx	*mlx;

	if (ac != 2)
		exit(EXIT_FAILURE);
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit(EXIT_FAILURE);
	init_struct(mlx);
	get_map(mlx, av);
	check_map(mlx);
	mlx->mlx = mlx_init();
	check_map_fit_screen(mlx);
	mlx->mlx_window = mlx_new_window(mlx->mlx, mlx->map_width * NB_PIXEL,
			mlx->map_heigth * NB_PIXEL, "so_long");
	init_window_texture_bonus(mlx);
	mlx_hook(mlx->mlx_window, 2, 1L << 0, play_bonus, mlx);
	mlx_hook(mlx->mlx_window, 17, 1L << 5, press_red_cross, mlx);
	mlx_loop(mlx->mlx);
	exit(EXIT_SUCCESS);
}
