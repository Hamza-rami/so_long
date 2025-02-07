/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:18:52 by hrami             #+#    #+#             */
/*   Updated: 2025/02/07 12:50:12 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectibles = 0;
	game->total_collectibles = 0;
	game->der = 4;
	game->player_img = NULL;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'C')
				game->total_collectibles++;
			j++;
		}
		i++;
	}
}

void	help_move_player(t_game *game, int new_x, int new_y)
{
	static int	count = 1;

	ft_putnbr(count++);
	write(1, "\n", 1);
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
}

void	move_player(t_game *game, int dx, int dy)
{
	int			new_x;
	int			new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectibles++;
		if (game->map[new_y][new_x] == 'E' &&
			game->collectibles == game->total_collectibles)
		{
			write(1, "You win!\n", 9);
			exit_game(game);
		}
		if (game->map[new_y][new_x] != 'E')
			help_move_player(game, new_x, new_y);
		draw_map(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 119 || keycode == 65362)
	{
		game->der = 1;
		move_player(game, 0, -1);
	}
	if (keycode == 115 || keycode == 65364)
	{
		game->der = 2;
		move_player(game, 0, 1);
	}
	if (keycode == 97 || keycode == 65361)
	{
		game->der = 3;
		move_player(game, -1, 0);
	}
	if (keycode == 100 || keycode == 65363)
	{
		game->der = 4;
		move_player(game, 1, 0);
	}
	return (0);
}

void	exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
