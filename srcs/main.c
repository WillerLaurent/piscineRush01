/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:34:11 by gartaud           #+#    #+#             */
/*   Updated: 2020/09/20 18:15:35 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

/*
** SOLVABLE 7*7 GRID
** "2 3 3 4 4 2 1 3 3 1 3 3 2 2 5 1 2 3 3 5 2 1 6 4 4 2 2 2"
**
** SOLVABLE 5*5 GRID :
** "4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2"
**
** SOLVABLE 4*4 GRID
** "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
** "1 2 4 2 3 2 1 3 1 2 2 3 2 1 3 2"
*/

int	main(int argc, char **argv)
{
	char	**tab;
	int		moves_left;

		if (!ft_parcer(argc, argv))
	{
		ft_putstr("Error");
		return (-1);
	}
	tab = ft_init(argc, argv);
	ft_putstr("\n===== INIT =====\n\n");
	ft_putsol(tab);
	printf("\n");

	if (tab == 0)
	{
		ft_putstr("Error\n");
		return (-1);
	}

	if (!ft_is_case_solvable(tab))
		return (-1);

	printf("===== SOLVE =====\n\n");
	moves_left = N * N;
	if (ft_solve(tab, moves_left))
	{
		ft_putstr("TOURNEE GENERALE EN Z1 VENEZ LES REUFS !!!\n");
		ft_putsol(tab);
		return (0);
	}
	ft_putstr("Error : grid is not solvable\n");

	return (-1);
}
