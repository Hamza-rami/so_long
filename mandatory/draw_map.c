/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:21:53 by hrami             #+#    #+#             */
/*   Updated: 2025/02/01 12:56:59 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(int column, int row, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->wall_img, column, row);
}

void	draw_player(int column, int row, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		column, row);
}

void	draw_collectible(int column, int row, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->collectible_img, column, row);
}

void	draw_exit(int column, int row, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->exit_img, column, row);
}

void	draw_floor(int column, int row, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, column, row);
}
