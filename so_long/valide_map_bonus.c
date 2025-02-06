/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:07:46 by hrami             #+#    #+#             */
/*   Updated: 2025/02/06 11:24:16 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**copy_map(t_game game)
{
	char	**copy;
	int		line;
	int		i;

	line = count_line();
	copy = malloc((line + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (game.map[i])
	{
		copy[i] = ft_strdup(game.map[i]);
		if (!copy[i])
		{
			while (i >= 0)
			{
				free(copy[i]);
				i--;
			}
			return (free(copy), NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(int x, int y, char **map)
{
	int	height;
	int	width;

	height = count_line();
	width = ft_tawl(map[0]);
	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E' || map[y][x] == 'M')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = '1';
	flood_fill(x + 1, y, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x, y - 1, map);
}

int	check_is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map(t_game game)
{
	char	**map;
	int		i;
	int		j;

	map = copy_map(game);
	if (!map)
		return (0);
	flood_fill(game.player_x, game.player_y, map);
	i = check_is_valid(map);
	j = 0;
	while (map[j])
	{
		free(map[j]);
		j++;
	}
	free(map);
	return (i);
}

void	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"photo/ibenmain.xpm", &img_width, &img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"photo/ataji.xpm", &img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"photo/ball.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"photo/smazouz.xpm", &img_width, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"photo/black.xpm", &img_width, &img_height);
	game->enemai_img = mlx_xpm_file_to_image(game->mlx,
			"photo/anemei.xpm", &img_width, &img_height);
}
