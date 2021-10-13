/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:19:04 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/13 17:10:40 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	end_game(t_mlx *mlx)
{
	if (mlx->collectible == 0
		&& mlx->map[mlx->pos_player_y][mlx->pos_player_x] == 'E')
	{
		destroy_image(mlx);
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
		free_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
}

static void	render_image(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->mlx_window);
	put_background(mlx);
	put_map_window(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img_actual_char,
		(mlx->pos_player_x * NB_PIXEL) + 10,
		(mlx->pos_player_y * NB_PIXEL) + 10);
}

static void	move_player(int keycode, t_mlx *mlx)
{
	mlx_do_key_autorepeaton(mlx->mlx);
	if (move_up_down(keycode, mlx) && move_left_rigth(keycode, mlx))
	{
		printf("%d\n", mlx->nb_move);
		if (mlx->map[mlx->pos_player_y][mlx->pos_player_x] == 'C')
		{
			mlx->map[mlx->pos_player_y][mlx->pos_player_x] = '0';
			mlx->collectible--;
		}
		render_image(mlx);
	}
}

int	play(int keycode, t_mlx *mlx)
{
	char	*move;
	char	*nb_move_str;

	move = NULL;
	nb_move_str = NULL;
	if (keycode == ESC_KEY)
	{
		destroy_image(mlx);
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
		free_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == A_KEY || keycode == W_KEY
		|| keycode == D_KEY || keycode == S_KEY)
		move_player(keycode, mlx);
	end_game(mlx);
	return (0);
}
