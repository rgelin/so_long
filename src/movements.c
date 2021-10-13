/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:59:42 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/13 16:45:17 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_up_down(int keycode, t_mlx *mlx)
{
	if (keycode == W_KEY)
	{
		if (mlx->map[mlx->pos_player_y - 1][mlx->pos_player_x] == '1')
			return (0);
		mlx->img_actual_char = mlx->img_char_up;
		mlx->pos_player_y--;
		mlx->nb_move++;
	}
	if (keycode == S_KEY)
	{
		if (mlx->map[mlx->pos_player_y + 1][mlx->pos_player_x] == '1')
			return (0);
		mlx->img_actual_char = mlx->img_char_down;
		mlx->pos_player_y++;
		mlx->nb_move++;
	}
	return (1);
}

int	move_left_rigth(int keycode, t_mlx *mlx)
{
	if (keycode == A_KEY)
	{
		if (mlx->map[mlx->pos_player_y][mlx->pos_player_x - 1] == '1')
			return (0);
		mlx->img_actual_char = mlx->img_char_left;
		mlx->pos_player_x--;
		mlx->nb_move++;
	}
	if (keycode == D_KEY)
	{
		if (mlx->map[mlx->pos_player_y][mlx->pos_player_x + 1] == '1')
			return (0);
		mlx->img_actual_char = mlx->img_char_rigth;
		mlx->pos_player_x++;
		mlx->nb_move++;
	}
	return (1);
}
