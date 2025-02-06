/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:52:03 by hrami             #+#    #+#             */
/*   Updated: 2025/02/05 17:47:39 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	help_free(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	write(2, "Error : invalid map\n", 20);
	exit(1);
}

void	help_free1(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	write(2, "Error: Window creation failed.\n", 31);
	exit(1);
}

void	help(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "my_game");
	if (!game->win)
		help_free1(game);
	load_images(game);
	draw_map(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, close_win, game);
	mlx_loop(game->mlx);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
	{
		write(2, "Error: MLX initialization failed.\n", 34);
		exit(1);
	}
	game.map = read_from_file(&game);
	if (!game.map)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		write(2, "Error: Failed to read map file.\n", 33);
		exit(1);
	}
	if (!parse(game.map))
		help_free(&game);
	initialize_game(&game);
	if (valid_map(game) == 0)
		help_free(&game);
	help(&game);
	return (0);
}
