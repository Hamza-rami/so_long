#include "so_long_bonus.h"

t_enemy *new_enemy(int x, int y)
{
    t_enemy *enemy;

    enemy = malloc(sizeof(t_enemy));
    if (!enemy)
        return (NULL);
    enemy->x = x;
    enemy->y = y;
    enemy->dir = 4;
    enemy->next = NULL;
    return (enemy);
}

t_enemy	*ft_lstlast(t_enemy *enemy)
{
	if (enemy == NULL)
		return (NULL);
	while (enemy->next != NULL)
	{
		enemy = enemy->next;
	}
	return (enemy);
}

void	add_back(t_enemy **enemies, t_enemy *new)
{
	t_enemy	*last;

	if (!new || !enemies)
		return ;
	if (*enemies == NULL)
		*enemies = new;
	else
	{
		last = ft_lstlast(*enemies);
		last->next = new;
	}
}

void    store_enemy(t_game *game)
{
    int i;
    int j;

    game->enemies = NULL;
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'M')
                add_back(&game->enemies, new_enemy(j, i));
            j++;
        }
        i++;
    }
}

