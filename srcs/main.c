/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:34:11 by gartaud           #+#    #+#             */
/*   Updated: 2020/09/20 15:52:15 by cmasse           ###   ########lyon.fr   */
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

	tab = ft_init(argc, argv);
	ft_putstr("\n===== INIT =====\n\n");
	ft_putsol(tab);
	printf("\n");

	if (tab == 0)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	printf("===== OBVIOUS_CASE =====\n\n");

	moves_left = ft_obvious_case(tab);
	printf("moves_left = %d\n", moves_left);
	if (moves_left == -1)
	{
		ft_putstr("Error : grid is not solvable (sum of opposit values of raw");
		ft_putstr(" and column is not between 3 and ");
		ft_putnbr(N + 1);
		ft_putstr("\n");
	}
	ft_putsol(tab);
	printf("\n");

	if (!moves_left)
	{
		ft_putsol(tab);
		return (0);
	}

	printf("===== SOLVE =====\n\n");
	if (ft_solve(tab, moves_left))
	{
		ft_putstr("TOURNEE GENERALE EN Z1 VENEZ LES REUFS !!!\n");
		ft_putsol(tab);
		return (0);
	}
	ft_putstr("Error : grid is not solvable\n");

	return (-1);
}
