/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:29:06 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/20 18:10:56 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	ft_check_input(char *str)
{
	int nb;

	nb = ft_atoi(str);
	return (nb);
}

int		ft_init_raw(char **tab, int count, char **argv)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = 0;
	str = argv[1];
	while (count < N * 2)
	{
		while (x < N)
		{
			tab[y][x + 1] = ft_check_input(str + count);
			count += 2;
			x++;
		}
		x = 0;
		y = N + 1;
		while (x < N)
		{
			tab[y][x + 1] = ft_check_input(str + count);
			x++;
			count += 2;
		}
	}
	return (count);
}

int		ft_init_colon(char **tab, int count, char **argv)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = 0;
	str = argv[1];
	while (count < N * 6)
	{
		while (y < N)
		{
			tab[y + 1][x] = ft_check_input(str + count);
			y++;
			count += 2;
		}
		x = N + 1;
		y = 0;
		while (y < N)
		{
			tab[y + 1][x] = ft_check_input(str + count);
			y++;
			count += 2;
		}
	}
	return (count);
}

void	ft_init_array_box(char **tab)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (y < N + 1)
	{
		x = 1;
		while (x < N + 1)
		{
			tab[y][x] = 0;
			x++;
		}
		y++;
	}
}

char	**ft_init(int argc, char **argv)
{
	char	**tab;
	int		x;
//	int		y;
	int		count;

	if (argc != 2)
		return (0);
	tab = malloc(sizeof(char *) * (N + 2));
	x = 0;
	while (x < (N + 2))
	{
		tab[x] = malloc(sizeof(char) * (N + 2));
		x++;
	}
	count = 0;
	count = ft_init_raw(tab, count, argv);
	count = ft_init_colon(tab, count, argv);
	ft_init_array_box(tab);
	return (tab);
}
