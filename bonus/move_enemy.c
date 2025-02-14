/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:30:15 by hrami             #+#    #+#             */
/*   Updated: 2025/02/14 12:42:33 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	helper1_move_ene(t_game *game, t_enemy *tmp)
{
	if (game->player_y < tmp->y && (game->map[tmp->y - 1][tmp->x] == '0'
		|| game->map[tmp->y - 1][tmp->x] == 'P'))
	{
		if (game->map[tmp->y - 1][tmp->x] == 'P')
		{
			write(1, "game over!\n", 12);
			exit_game(game);
		}
		game->map[tmp->y - 1][tmp->x] = 'M';
		game->map[tmp->y][tmp->x] = '0';
		return (tmp->y -= 1, 1);
	}
	else if (game->player_y > tmp->y && (game->map[tmp->y + 1][tmp->x] == '0'
		|| game->map[tmp->y + 1][tmp->x] == 'P'))
	{
		if (game->map[tmp->y + 1][tmp->x] == 'P')
		{
			write(1, "game over!\n", 12);
			exit_game(game);
		}
		game->map[tmp->y + 1][tmp->x] = 'M';
		game->map[tmp->y][tmp->x] = '0';
		return (tmp->y += 1, 1);
	}
	return (0);
}

int	helper2_move_ene(t_game *game, t_enemy *tmp)
{
	if (game->player_x < tmp->x && (game->map[tmp->y][tmp->x - 1] == '0'
		|| game->map[tmp->y][tmp->x - 1] == 'P'))
	{
		if (game->map[tmp->y][tmp->x - 1] == 'P')
		{
			write(1, "game over!\n", 12);
			exit_game(game);
		}
		game->map[tmp->y][tmp->x - 1] = 'M';
		game->map[tmp->y][tmp->x] = '0';
		return (tmp->x -= 1, 1);
	}
	else if (game->player_x > tmp->x && (game->map[tmp->y][tmp->x + 1] == '0'
		|| game->map[tmp->y][tmp->x + 1] == 'P'))
	{
		if (game->map[tmp->y][tmp->x + 1] == 'P')
		{
			write(1, "game over!\n", 12);
			exit_game(game);
		}
		game->map[tmp->y][tmp->x + 1] = 'M';
		game->map[tmp->y][tmp->x] = '0';
		return (tmp->x += 1, 1);
	}
	return (0);
}

void	move_enemie(t_game *game)
{
	t_enemy	*tmp;

	tmp = game->enemies;
	while (tmp)
	{
		if (helper1_move_ene(game, tmp) == 0)
			helper2_move_ene(game, tmp);
		tmp = tmp->next;
	}
	draw_map(game);
}

void	update_enemies(t_game *game)
{
	char		*move_str;
	static int	frame = 0;

	move_str = ft_itoa(game->move_count);
	if (!move_str)
		return ;
	mlx_string_put(game->mlx, game->win, 15, 15, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 55, 15, 0xFFFFFF, move_str);
	free(move_str);
	if (frame % 10000 == 0)
		move_enemie(game);
	frame++;
}
