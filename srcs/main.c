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
	char **tab;

	tab = ft_init(argc, argv);
	if (tab == 0)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	ft_obvious_case(tab);
	ft_solve(tab);
	return (0);
}
