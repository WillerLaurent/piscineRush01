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

#include "ft.h"

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

int	ft_error(char **tab)
{
	ft_putstr("Error\n");
	free(tab);
	return (-1);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		moves_left;

	tab = 0;
	if (N < 3 || N > 6)
		return (ft_error(tab));
	if (!ft_parcer(argc, argv))
		return (ft_error(tab));
	tab = ft_init(argc, argv);
	if (tab == 0)
		return (ft_error(tab));
	if (!ft_is_case_solvable(tab))
		return (ft_error(tab));
	moves_left = N * N;
	if (ft_solve(tab, moves_left))
	{
		ft_putsol(tab);
		free(tab);
		return (0);
	}
	return (ft_error(tab));
}
