#include "so_long_bonus.h"

void	move_enemie(t_game *game)
{
	t_enemy *tmp;
	int moved;

	printf("tmp\n");
	tmp = game->enemies;
	// return ;
	while (tmp)
	{
		moved = 0;
		if (tmp->dir == 4 && game->map[tmp->x + 1][tmp->y] == '0')
		{
			if (game->map[tmp->x + 1][tmp->y] == 'P')
				exit_game(game);
			game->map[tmp->x + 1][tmp->y] = 'M';
			game->map[tmp->x][tmp->y] = '0';
			tmp->x += 1;
			moved = 1;
		}
		else if (tmp->dir == 3 && game->map[tmp->x - 1][tmp->y] == '0')
		{
			if (game->map[tmp->x - 1][tmp->y] == 'P')
				exit_game(game);
			game->map[tmp->x - 1][tmp->y] = 'M';
			game->map[tmp->x][tmp->y] = '0';
			tmp->x -= 1;
			moved = 1;
		}
		else if (tmp->dir == 2 && game->map[tmp->x][tmp->y - 1] == '0')
		{
			if (game->map[tmp->x][tmp->y - 1] == 'P')
				exit_game(game);
			game->map[tmp->x][tmp->y - 1] = 'M';
			game->map[tmp->x][tmp->y] = '0';
			tmp->y -= 1;
			moved = 1;
		}
		else if (tmp->dir == 1 && game->map[tmp->x][tmp->y + 1] == '0')
		{
			if (game->map[tmp->x][tmp->y + 1] == 'P')
				exit_game(game);
			game->map[tmp->x][tmp->y + 1] = 'M';
			game->map[tmp->x][tmp->y] = '0';
			tmp->y += 1;
			moved = 1;
		}
		if (!moved)
			tmp->dir = (tmp->dir % 4) + 1;
		tmp = tmp->next;
	}
}


