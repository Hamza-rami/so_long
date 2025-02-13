/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:21:58 by hrami             #+#    #+#             */
/*   Updated: 2025/02/13 10:22:28 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_heart(t_game *game)
{
	static int	counter = 0;

	counter++;
	if (counter == 9000)
	{
		game->heart_frame = (game->heart_frame + 1) % 3;
		counter = 0;
		draw_map(game);
	}
}

int	loop_game(t_game *game)
{
	animate_heart(game);
	update_enemies(game);
	return (0);
}
