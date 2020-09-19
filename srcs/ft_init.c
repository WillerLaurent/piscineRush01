/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:29:06 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/19 17:33:56 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	ft_check_input(char *str)
{
	int i;
	int nb;

	i = 0;
	while (str[i])
	{
		if (str[i] > '0' && str[i] <= N)
			nb = ft_atoi(&str[i]);
		if (nb > N)
			return (0);
	}
	return (nb + '0');
}

int		ft_init_raw(char **tab, int count, char **argv)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (argv[1][count])
	{
		//remplissage ligne du haut
		while (x < N)
		{
			while (argv[1][ count] == 32)
				count++;
					tab[y][x+1] = ft_check_input(argv[1] + count);
			count++;
			x++;
		}
		//remplissage ligne du bas
		x = 0;
		y = N + 1;
		while (x < (N * 2))
		{
			while (argv[1][ count] == 32)
				count++;
			tab[y][x+1] = ft_check_input(argv[1] + count);
			x++;
			count++;
		}
	}
	return (count);
}

int		ft_init_colon(char **tab, int count, char **argv)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (argv[1][count])
	{
		//remplissage cote gauche
		x = 0;
		y = 0;
		while (y < N)
		{
			while (argv[1][count] == ' ')
				count++;
			tab[y][x] = ft_check_input(argv[1] + count);
			y++;
			count++;
		}
		//remplissage cote droit
		x = N + 1;
		y = 0;
		while (y < (N * 2))
		{
			while (argv[1][count] == ' ')
				count++;
			tab[y][x] = ft_check_input(argv[1] + count);
			y++;
			count++;
		}
	}
	return (count);
}

char	**ft_init(int argc, char **argv)
{
	char **tab;
	int x;
	int y;
	int count;
	tab = malloc(sizeof(char*) * (N + 2));
	while (x < (N + 2))
	{
		tab[x] = malloc(sizeof(char) * (N + 2));
		x++;
	}
	x = 0;
	y = 0;
	count = 0;

	count = ft_init_raw(tab, count, argv);
	count = ft_init_colon(tab, count, argv);
	//initialisation des cases a 0
	y = 1;
	x = 1;
	while (y < N + 1)
		while (x < N + 1)
			tab[y][x] = '0';
	return (tab);
}
