/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:34:11 by gartaud           #+#    #+#             */
/*   Updated: 2020/09/15 16:37:36 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int argc, char **argv)
{
	char	**tab;
	int		moves_left = N * N;

	tab = ft_init(argc, argv);
	ft_putstr("\n===== INIT =====\n\n");
	ft_putsol(tab);
	printf("\n");

	if (tab == 0)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	//printf("===== OBVIOUS_CASE =====\n\n");
	/*
	moves_left = ft_obvious_case(tab);
	if (moves_left == -1)
	{
		ft_putstr("Error : grid is not solvable (sum of opposit values of raw");
		ft_putstr(" and column is not between 3 and 5)\n");
	}
	//ft_putsol(tab);
	//printf("\n");

	if (!moves_left)
	{
		ft_putsol(tab);
		return (0);
	}
	*/
	printf("===== SOLVE =====\n\n");
	if (ft_solve(tab, moves_left))
	{
		ft_putsol(tab);
		return (0);
	}
	ft_putstr("Error : grid is not solvable\n");

	return (-1);
}
