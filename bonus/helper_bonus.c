/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:20:07 by hrami             #+#    #+#             */
/*   Updated: 2025/02/13 22:55:28 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_enemei(int column, int row, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemai_img, column, row);
}

char	*der(int n)
{
	if (n == 1)
		return ("textures/up.xpm");
	else if (n == 2)
		return ("textures/down.xpm");
	else if (n == 3)
		return ("textures/left.xpm");
	else if (n == 4)
		return ("textures/right.xpm");
	return ("textures/right.xpm");
}

void	help_exit_no_img(t_game *game)
{
	if (game->collectible_img[0])
		mlx_destroy_image(game->mlx, game->collectible_img[0]);
	if (game->collectible_img[1])
		mlx_destroy_image(game->mlx, game->collectible_img[1]);
	if (game->collectible_img[2])
		mlx_destroy_image(game->mlx, game->collectible_img[2]);
}

void	exit_no_img(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->enemai_img)
		mlx_destroy_image(game->mlx, game->enemai_img);
	help_exit_no_img(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	write(2, "Error :\n no image", 18);
	exit(0);
}

void	claer_list(t_game *game)
{
	t_enemy	*temp;

	if (!game->enemies)
		return ;
	while (game->enemies)
	{
		temp = game->enemies->next;
		free(game->enemies);
		game->enemies = temp;
	}
}
