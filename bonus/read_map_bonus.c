/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:16:11 by hrami             #+#    #+#             */
/*   Updated: 2025/02/10 13:03:58 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_line(t_game *game)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(game->argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_from_file(t_game *game)
{
	int		i;
	int		fd;
	int		lines;
	char	**str;

	lines = count_line(game);
	if (lines <= 0 || lines >= 150)
		return (NULL);
	str = malloc((lines + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	fd = open(game->argv, O_RDONLY);
	if (fd < 0)
		return (free(str), NULL);
	i = 0;
	while (i < lines)
	{
		str[i] = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	game->window_width = ft_tawl(str[0]) * 64;
	game->window_height = lines * 64;
	return (close(fd), str);
}

void	help_draw_map(int i, int j, t_game *game)
{
	int	row;
	int	column;
	int	img_width;
	int	img_height;

	row = i * TILE_SIZE;
	column = j * TILE_SIZE;
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			der(game->der), &img_width, &img_height);
	if (!game->player_img)
		exit_no_img(game);
	if (game->map[i][j] == '1')
		draw_wall(column, row, game);
	if (game->map[i][j] == 'P')
		draw_player(column, row, game);
	if (game->map[i][j] == 'C')
		draw_collectible(column, row, game);
	if (game->map[i][j] == 'E')
		draw_exit(column, row, game);
	if (game->map[i][j] == '0')
		draw_floor(column, row, game);
	if (game->map[i][j] == 'M')
		draw_enemei(column, row, game);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;
	char	*move_str;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			help_draw_map(i, j, game);
			j++;
		}
		i++;
	}
	move_str = ft_itoa(game->move_count);
	if (!move_str)
		return ;
	mlx_string_put(game->mlx, game->win, 15, 15, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 55, 15, 0xFFFFFF, move_str);
	free(move_str);
}

int	ft_tawl(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
