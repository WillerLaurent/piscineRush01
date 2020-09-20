/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:01:54 by cmasse            #+#    #+#             */
/*   Updated: 2020/09/20 18:03:33 by cmasse           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_putsol(char **tab)
{
	int i;
	int j;

	i = 0;
	while (i < N + 2)
	{
		j = 0;
		while (j < N + 2)
		{
			ft_putchar(tab[i][j] + '0');
			if (j != N + 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return ;
}

void	ft_putsol_def(char **tab)
{
	int i;
	int j;

	i = 1;
	while (i < N + 1)
	{
		j = 1;
		while (j < N + 1)
		{
			ft_putchar(tab[i][j] + '0');
			if (j != N)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return ;
}
