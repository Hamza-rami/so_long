/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:11:23 by hrami             #+#    #+#             */
/*   Updated: 2025/02/14 13:02:19 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "get_file/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*argv;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		total_collectibles;
	int		window_width;
	int		window_height;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	void	*floor_img;
	int		der;
}	t_game;

# define TILE_SIZE 64

int		count_line(t_game *gmae);
char	**read_from_file(t_game *game);
int		parse(char **str, t_game *game);
void	initialize_game(t_game *game);
void	draw_map(t_game *game);
void	exit_game(t_game *game);
int		key_press(int keycode, t_game *game);
int		ft_tawl(char *s);
int		valid_map(t_game game);
void	load_images(t_game *game);
void	exit_game(t_game *game);
void	draw_wall(int column, int row, t_game *game);
void	draw_player(int column, int row, t_game *game);
void	draw_collectible(int column, int row, t_game *game);
void	draw_exit(int column, int row, t_game *game);
void	draw_floor(int column, int row, t_game *game);
void	ft_putnbr(int number);
int		close_win(t_game *game);
char	*der(int n);
void	exit_no_img(t_game *game);

#endif