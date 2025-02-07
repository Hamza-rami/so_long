/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:22:51 by hrami             #+#    #+#             */
/*   Updated: 2025/02/07 11:24:09 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_no_img(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	write(2, "Error :\n no image", 17);
	exit(0);
}

char	*der(int n)
{
	if (n == 1)
		return ("photo/up.xpm");
	else if (n == 2)
		return ("photo/down.xpm");
	else if (n == 3)
		return ("photo/left.xpm");
	else if (n == 4)
		return ("photo/right.xpm");
	return ("photo/right.xpm");
}
