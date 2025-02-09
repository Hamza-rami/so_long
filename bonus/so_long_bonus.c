/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:52:03 by hrami             #+#    #+#             */
/*   Updated: 2025/02/09 16:03:00 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	write(2, "Error :\ninvalid map\n", 20);
	exit(1);
}

void	help(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "my_game");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(game->map);
		write(2, "Error:\nWindow creation failed.\n", 31);
		exit(1);
	}
	load_images(game);
	store_enemy(game);
	draw_map(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, close_win, game);
	mlx_loop(game->mlx);
}

int	help_main(int argc, char *argv[], t_game *game)
{
	int		i;
	int		j;
	char	*str;

	str = ".ber";
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			i++;
		}
		j = 0;
		while (str[j])
		{
			if (str[j] != argv[1][i - 4])
				return (write(2, "Error :\nfile not .ber\n", 23), 0);
			i++;
			j++;
		}
		game->argv = argv[1];
	}
	else
		return (write(2, "Error:\nEnter the map file.\n", 27), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (help_main(argc, argv, &game) == 0)
		exit(1);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		write(2, "Error:\nMLX initialization failed.\n", 34);
		exit(1);
	}
	game.map = read_from_file(&game);
	if (!game.map)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		write(2, "Error:\nFailed to read map file.\n", 33);
		exit(1);
	}
	if (!parse(game.map, &game))
		help_free(&game);
	initialize_game(&game);
	if (valid_map(game) == 0)
		help_free(&game);
	help(&game);
	return (0);
}
