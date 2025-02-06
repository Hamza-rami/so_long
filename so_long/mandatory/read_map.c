/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:16:11 by hrami             #+#    #+#             */
/*   Updated: 2025/02/05 16:28:40 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(void)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open("map.ber", O_RDONLY);
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

	lines = count_line();
	if (lines <= 0 || lines >= 150)
		return (NULL);
	str = malloc((lines + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	fd = open("map.ber", O_RDONLY);
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

	row = i * TILE_SIZE;
	column = j * TILE_SIZE;
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
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

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
}

int	ft_tawl(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
