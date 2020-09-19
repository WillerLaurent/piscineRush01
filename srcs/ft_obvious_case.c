/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obvious_case_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:16:46 by cmasse            #+#    #+#             */
/*   Updated: 2020/09/19 17:33:17 by cmasse           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_obvious_case_rowleft(char **tab)
{
	int		i;
	int		y;

	i = 0;
	y = 1;
	while (y < 5)
	{
		if (tab[y][i] == 4)
		{
			while (i < 4)
			{
				while (tab[y][i + 1] != 0)
					i++;
				if (i < 4)
					tab[y][i + 1] = i + 1;
				i++;
			}
		}
		i = 0;
		if (tab[y][i] == 1 && tab[y][i + 1] == 0)
			tab[y][i + 1] = 4;
		y++;
	}
}

void	ft_obvious_case_colup(char **tab)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	while (i < 5)
	{
		if (tab[y][i] == 4)
		{
			while (y < 4)
			{
				while (y < 4 && tab[y + 1][i] != 0)
					y++;
				if (y < 4)
					tab[y + 1][i] = y + 1;
				y++;
			}
		}
		y = 0;
		if (tab[y][i] == 1 && tab[y + 1][i] == 0)
			tab[y + 1][i] = 4;
		i++;
	}
}

void	ft_obvious_case_rowright(char **tab)
{
	int		i;
	int		y;

	i = 5;
	y = 1;
	while (y < 5)
	{
		if (tab[y][i] == 4)
		{
			while (i > 1)
			{
				while (tab[y][i - 1] != 0)
					i--;
				if (i > 1)
					tab[y][i - 1] = i - 1;
				i--;
			}
		}
		i = 5;
		if ((tab[y][i] == 1) && tab[y][i - 1] == 0)
			tab[y][i - 1] = 4;
		y++;
	}
}

void	ft_obvious_case_coldown(char **tab)
{
	int		i;
	int		y;

	i = 1;
	y = 5;
	while (i < 5)
	{
		if (tab[y][i] == 4)
		{
			while (y > 1)
			{
				while (tab[y - 1][i] != 0)
					y--;
				if (y > 1)
					tab[y - 1][i] = y - 1;
				y--;
			}
		}
		y = 5;
		if (tab[y][i] == 1 && tab[y - 1][i] == 0)
			tab[y - 1][i] = 4;
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
	while (y < 5)
	{
		i = 1;
		while (i < 5)
		{
			if (tab[y][i] == 0)
				a++;
			i++;
		}
		y++;
	}
	return (a);
}
