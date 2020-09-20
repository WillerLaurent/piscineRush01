/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:00:06 by gartaud           #+#    #+#             */
/*   Updated: 2020/09/20 18:00:09 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_is_move_valid(char **tab, int i, int j, int value)
{
	int	res;
	int	x;
	int	y;
	int count;

	if (tab[i][j] != 0 || value <= 0 || value > N ||
		i <= 0 || i >= N + 1 || j <= 0 || j >= N + 1)
		return (0);
	tab[i][j] = value;
	res = 1;
	y = 0;
	count = 0;
	while (++y < N + 1)
	{
		if (tab[y][j] == value)
			count++;
		if (count > 1)
			res = 0;
	}
	x = 0;
	count = 0;
	while (++x < N + 1)
	{
		if (tab[i][x] == value)
			count++;
		if (count > 1)
			res = 0;
	}
	tab[i][j] = 0;
	return (res);
}

int		ft_is_solution(char **tab)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (res && ++i <= N)
	{
		res = res &&
			((ft_count_rowleft(tab, i) == tab[i][0]) &&
			(ft_count_rowright(tab, i) == tab[i][N + 1]) &&
			(ft_count_colup(tab, i) == tab[0][i]) &&
			(ft_count_coldown(tab, i) == tab[N + 1][i]));
	}
	return (res);
}

void	ft_next_empty_space(char **tab, int *i, int *j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++y <= N)
	{
		x = 0;
		while (++x <= N)
			if (!tab[y][x])
			{
				*i = y;
				*j = x;
				return ;
			}
	}
	*i = -1;
	*j = -1;
	return ;
}

int		ft_solve(char **tab, int move_left)
{
	int next_move;
	int	i;
	int j;

	if (move_left == 0)
		return (ft_is_solution(tab));
	ft_next_empty_space(tab, &i, &j);
	next_move = 0;
	while (++next_move <= N)
		if (ft_is_move_valid(tab, i, j, next_move))
		{
			tab[i][j] = next_move;
			if (ft_solve(tab, move_left - 1))
				return (1);
			tab[i][j] = 0;
		}
	return (0);
}
