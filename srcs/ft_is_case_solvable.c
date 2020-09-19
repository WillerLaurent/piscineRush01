/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_case_solvable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 22:42:48 by cmasse            #+#    #+#             */
/*   Updated: 2020/09/19 23:10:41 by cmasse           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_is_case_solvable(char **tab)
{
	int		i;
	int		y;

	i = 1;
	y = 1;
	while (y < N + 1)
	{
		if (!(tab[y][0] + tab[y][N + 1] >= 3 &&
					tab[y][0] + tab[y][N + 1] <= N + 1))
			return (0);
		y++;
	}
	while (i < N + 1)
	{
		if (!(tab[0][i] + tab[N + 1][i] >= 3 &&
					tab[0][i] + tab[N + 1][i] <= N + 1))
			return (0);
		i++;
	}
	return (1);
}
