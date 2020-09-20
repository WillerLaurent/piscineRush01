/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:04:56 by cmasse            #+#    #+#             */
/*   Updated: 2020/09/20 18:05:00 by cmasse           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_count_colup(char **tab, int j)
{
	int i;
	int	max;
	int	res;

	i = 0;
	max = tab[i + 1][j];
	res = (max != 0);
	while (++i < N + 1)
		if (tab[i][j] && tab[i][j] > max)
		{
			res++;
			max = tab[i][j];
		}
	return (res);
}

int		ft_count_coldown(char **tab, int j)
{
	int i;
	int	max;
	int	res;

	i = N + 1;
	max = tab[i - 1][j];
	res = (max != 0);
	while (--i > 0)
		if (tab[i][j] && tab[i][j] > max)
		{
			res++;
			max = tab[i][j];
		}
	return (res);
}

int		ft_count_rowright(char **tab, int i)
{
	int j;
	int	max;
	int	res;

	j = N + 1;
	max = tab[i][j - 1];
	res = (max != 0);
	while (--j > 0)
		if (tab[i][j] && tab[i][j] > max)
		{
			res++;
			max = tab[i][j];
		}
	return (res);
}

int		ft_count_rowleft(char **tab, int i)
{
	int j;
	int	max;
	int	res;

	j = 0;
	max = tab[i][j + 1];
	res = (max != 0);
	while (++j < N + 1)
		if (tab[i][j] && tab[i][j] > max)
		{
			res++;
			max = tab[i][j];
		}
	return (res);
}
