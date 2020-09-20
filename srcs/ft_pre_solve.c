/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:10:41 by cmasse            #+#    #+#             */
/*   Updated: 2020/09/20 17:10:45 by cmasse           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"


void	ft_pre_solve_rowleft(char **tab)
{

	int		i;
	int		y;
	int		b;
	int		case_vide[2];
	int		somme;

	i = 1;
	y = 1;
	b = N;
	somme = 0;
	while (y < N + 1)
	{
		i = 1;
		while(i < N +1)
		{ 
			if(tab[y][i] != 0)
			{
				b--;
				somme = somme + tab[y][i];
			}
			if(tab[y][i] == 0)
				case_vide[0] = y;
				case_vide[1] = i;
			i++;
		}
		if(b == 1);
			tab[case_vide[0]][case_vide[1]] = N - somme;
}


void	ft_pre_solve_colup(char **tab)
{

	int		i;
	int		y;
	int		b;
	int		case_vide[2];
	int		somme;

	i = 1;
	y = 1;
	b = N;
	somme = 0;
	while (i < N + 1)
	{
		y = 1;
		while(y < N +1)
		{
			if(tab[y][i] != 0)
			{
				b--;
				somme = somme + tab[y][i];
			}
			if(tab[y][i] == 0)
				case_vide[0] = y;
				case_vide[1] = i;
			i++;
		}
		if(b == 1);
			tab[case_vide[0]][case_vide[1]] = N - somme;
}

int		ft_pre_solve(char **tab)
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
	ft_pre_solve_rowleft(tab);
	ft_pre_solve_colup(tab);

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
	
