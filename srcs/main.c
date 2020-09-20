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
** SOLVABLE 7*7 GRID (Timeout)
** "2 3 3 4 4 2 1 3 3 1 3 3 2 2 5 1 2 3 3 5 2 1 6 4 4 2 2 2"
**
** SOLVABLE 6*6 GRID
** "3 1 4 3 2 3 2 3 1 3 4 2 2 5 2 1 3 2 3 2 2 5 1 4"
**
** SOLVABLE 5*5 GRID :
** "4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2"
**
** SOLVABLE 4*4 GRID
** "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
** "1 2 4 2 3 2 1 3 1 2 2 3 2 1 3 2"
**
** SOLVABLE 3*3 GRID
** "2 2 1 2 1 3 3 1 2 1 2 2"
*/

int	main(int argc, char **argv)
{
	char	**tab;
	int		moves_left;

	tab = ft_init(argc, argv);
	if (tab == 0)
	{
		ft_putstr("Error\n");
		return (-1);
	}

	moves_left = ft_obvious_case(tab);
	if (moves_left == -1)
	{
		ft_putstr("Error\n");
		return (-1);
	}

	if (ft_solve(tab, moves_left))
	{
		ft_putsol(tab);
		return (0);
	}
	ft_putstr("Error\n");
	return (-1);
}
