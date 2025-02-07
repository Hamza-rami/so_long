/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:59:56 by hrami             #+#    #+#             */
/*   Updated: 2025/02/06 14:27:58 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **str)
{
	int	len;
	int	i;

	len = ft_tawl(str[0]);
	i = 1;
	while (str[i])
	{
		if (ft_tawl(str[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	help_only_element(int *p, int *e, int *c, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (!(str[i][j] == '1' || str[i][j] == '0' ||
				str[i][j] == 'E' || str[i][j] == 'P' || str[i][j] == 'C'))
				return (0);
			if (str[i][j] == 'E')
				(*e)++;
			if (str[i][j] == 'P')
				(*p)++;
			if (str[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	only_element(char **str)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	if (help_only_element(&p, &e, &c, str) == 0)
		return (0);
	if (e != 1 || p != 1 || c < 1)
		return (0);
	return (1);
}

int	check_borders(char **str, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (str[0][i] != '\n' && str[0][i])
	{
		if (str[0][i] != '1')
			return (0);
		i++;
	}
	i = count_line(game) - 1;
	j = 0;
	while (str[i][j] != '\n' && str[i][j])
	{
		if (str[i][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (i++ < count_line(game) - 1)
	{
		if (str[i][0] != '1' || str[i][ft_tawl(str[i]) - 1] != '1')
			return (0);
	}
	return (1);
}

int	parse(char **str, t_game *game)
{
	if (check_borders(str, game) == 0)
		return (0);
	if (is_rectangular(str) == 0)
		return (0);
	if (only_element(str) == 0)
		return (0);
	return (1);
}
