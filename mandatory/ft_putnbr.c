/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:55:27 by hrami             #+#    #+#             */
/*   Updated: 2025/02/05 14:56:01 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int number)
{
	if (number <= 9)
		ft_putchar(number + 48);
	else
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
}

int	close_win(t_game *game)
{
	exit_game(game);
	return (0);
}
