
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obvious_case_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:16:46 by cmasse            #+#    #+#             */
/*   Updated: 2020/09/20 13:31:19 by cmasse           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_obvious_case_rowleft(char **tab)
{
	int		i;
	int		y;

	i = 0;
	y = 1;
	while (y < N  + 1)
	{
		if (tab[y][i] == N)
		{
			while (i < N)
			{
				while (tab[y][i + 1] != 0 && i < N)
					i++;
				if (i < N)
					tab[y][i + 1] = i + 1;
				i++;
			}
		}
		i = 0;
		if (tab[y][i] == 1 && tab[y][i + 1] == 0)
			tab[y][i + 1] = N;
		if ((tab[y][i] == 1 && tab[y][N + 1] == 2) && tab[y][N] == 0)
			tab[y][N] = N - 1;
		y++;
	}
}

void	ft_obvious_case_colup(char **tab)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	while (i < N + 1)
	{
		if (tab[y][i] == N)
		{
			while (y < N)
			{
				while (tab[y + 1][i] != 0 && y < N)
					y++;
				if (y < N)
					tab[y + 1][i] = y + 1;
				y++;
			}
		}
		y = 0;
		if (tab[y][i] == 1 && tab[y + 1][i] == 0)
			tab[y + 1][i] = N - 1;
		if ((tab[y][i] == 1 && tab[N + 1][i] == 2) && tab[N][i] == 0)
			tab[N][i] = N - 1;
		i++;
	}
}

void	ft_obvious_case_rowright(char **tab)
{
	int		i;
	int		y;

	i = N + 1;
	y = 1;
	while (y < N + 1)
	{
		if (tab[y][i] == N)
		{
			while (i > 1)
			{
				while (tab[y][i - 1] != 0 && i > 1)
					i--;
				if (i > 1)
					tab[y][i - 1] = i - 1;
				i--;
			}
		}
		i = N + 1;
		if ((tab[y][i] == 1) && tab[y][i - 1] == 0)
			tab[y][i - 1] = N;
		if ((tab[y][i] == 1 && tab[y][N - 4] == 2) && tab[y][N - 3] == 0)
			tab[y][N - 3] = N - 1;
		y++;
	}
}

void	ft_obvious_case_coldown(char **tab)
{
	int		i;
	int		y;

	i = 1;
	y = N + 1;
	while (i < N)
	{
		if (tab[y][i] == N)
		{
			while (y > 1)
			{
				while (tab[y - 1][i] != 0 && y > 1)
					y--;
				if (y > 1)
					tab[y - 1][i] = y - 1;
				y--;
			}
		}
		y = N + 1;
		if (tab[y][i] == 1 && tab[y - 1][i] == 0)
			tab[y - 1][i] = N;
		if ((tab[y][i] == 1 && tab[N - 4][i] == 2) && tab[N - 3][i] == 0)
			tab[N - 3][i] = N - 1;

		i++;
	}
}

int		ft_obvious_case(char **tab)
{
	int		a;
	int		i;
	int		y;

	i = 1;
	y = 1;
	a = 0;
	if (!ft_is_case_solvable(tab))
		return (-1);
	ft_obvious_case_coldown(tab);
	ft_obvious_case_colup(tab);
	ft_obvious_case_rowleft(tab);
	ft_obvious_case_rowright(tab);
	while (y < N + 1)
	{
		i = 1;
		while (i < N + 1)
		{
			if (tab[y][i] == 0)
				a++;
			i++;
		}
		y++;
	}
	return (a);
}
