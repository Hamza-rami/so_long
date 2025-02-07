/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:55:27 by hrami             #+#    #+#             */
/*   Updated: 2025/02/06 11:23:25 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static int	get_length(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = get_length(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		result[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (result);
}
