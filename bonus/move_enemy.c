#include "so_long_bonus.h"

void	move_enemie(t_game *game)
{
	t_enemy *tmp;

	tmp = game->enemies;
	while (tmp)
	{
		if (game->player_y < tmp->y && game->map[tmp->y - 1][tmp->x] == '0')
		{
			game->map[tmp->y - 1][tmp->x] = 'M';
			game->map[tmp->y][tmp->x] = '0';
			tmp->y -= 1;
		}
		else if (game->player_y > tmp->y && game->map[tmp->y + 1][tmp->x] == '0')
		{
			game->map[tmp->y + 1][tmp->x] = 'M';
			game->map[tmp->y][tmp->x] = '0';
			tmp->y += 1;
		}
		else if (game->player_x < tmp->x && game->map[tmp->y][tmp->x - 1] == '0')
		{
			game->map[tmp->y][tmp->x - 1] = 'M';
			game->map[tmp->y][tmp->x] = '0';
			tmp->x -= 1;
		}
		else if (game->player_x > tmp->x && game->map[tmp->y][tmp->x + 1] == '0')
		{
			game->map[tmp->y][tmp->x + 1] = 'M';
			game->map[tmp->y][tmp->x] = '0';
			tmp->x += 1;
		}
		tmp = tmp->next;
	}
	draw_map(game);
}





