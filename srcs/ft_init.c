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
	int nb;

	nb = ft_atoi(str);
	if (nb <= 0 || nb > N)
		return (0);
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
	while (count < 15)
	{
		//remplissage ligne du haut
		while (x < N)
		{
			while (str[count] == 32)
				count++;
			tab[y][x+1] = ft_check_input(str + count);
			count++;
			x++;
		}
		//remplissage ligne du bas
		x = 0;
		y = N + 1;
		while (x < N)
		{
			while (str[count] == 32)
				count++;
			tab[y][x+1] = ft_check_input(str + count);
			x++;
			count++;
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
	while (str[count])
	{
		//remplissage cote gauche
		x = 0;
		y = 0;
		while (y < N)
		{
			while (str[count] == ' ')
				count++;
			tab[y + 1][x] = ft_check_input(str + count);
			y++;
			count++;
		}
		//remplissage cote droit
		x = N + 1;
		y = 0;
		while (y < N)
		{
			while (str[count] == ' ')
				count++;
			tab[y + 1][x] = ft_check_input(str + count);
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
	//initialisation des cases a 0
	y = 0;
	while (++y < N + 1)
	{
		x = 0;
		while (++x < N + 1)
			tab[y][x] = 0;
	}
	return (tab);
}
