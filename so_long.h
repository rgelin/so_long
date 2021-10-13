/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:28:34 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/13 16:49:54 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./src/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define NB_PIXEL 55
# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
	int		screen_width;
	int		screen_heigth;
	char	**map;
	int		map_heigth;
	int		map_width;
	int		player;
	int		exit;
	int		collectible;
	int		pos_player_x;
	int		pos_player_y;
	int		nb_move;
	void	*img_background;
	int		x_back;
	int		y_back;
	void	*img_char_down;
	void	*img_char_up;
	void	*img_char_left;
	void	*img_char_rigth;
	void	*img_actual_char;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
}				t_mlx;

typedef struct s_img
{
	int	x_char_down;
	int	y_char_down;
	int	x_char_up;
	int	y_char_up;
	int	x_char_left;
	int	y_char_left;
	int	x_char_rigth;
	int	y_char_rigth;
	int	x_wall;
	int	y_wall;
	int	x_collect;
	int	y_collect;
	int	x_exit;
	int	y_exit;
}				t_img;

void	get_map(t_mlx *mlx, char *av[]);
void	check_map(t_mlx *mlx);

void	init_image(t_mlx *mlx, t_img *img);
void	init_window_texture(t_mlx *mlx);
void	put_background(t_mlx *mlx);
void	put_map_window(t_mlx *mlx);

int		play(int keycode, t_mlx *mlx);
int		move_up_down(int keycode, t_mlx *mlx);
int		move_left_rigth(int keycode, t_mlx *mlx);

void	free_mlx(t_mlx *mlx);
void	destroy_image(t_mlx *mlx);
int		press_red_cross(t_mlx *mlx);

int		play_bonus(int keycode, t_mlx *mlx);
void	init_window_texture_bonus(t_mlx *mlx);
char	*ft_itoa(int nb);

#endif
