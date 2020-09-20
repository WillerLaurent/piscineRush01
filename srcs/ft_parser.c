/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:34:09 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/20 17:25:58 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_parcer(int argc, char **argv)
{
	int i;
	int count;
	int nb;

	i = 0;
	count = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			i++;
		if (!ft_is_numeric(argv[1][i]))
			return (0);
		nb = ft_atoi(argv[1] + i);
		if (nb < 1 || nb > N)
			return (0);
		else
			count++;
		i++;
	}
	if (count % 4 != 0)
		return (0);
	return (1);
}
