/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:46:02 by gartaud           #+#    #+#             */
/*   Updated: 2020/09/13 09:50:17 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_process_nbr(int nbr)
{
	unsigned int res;

	if (nbr < 0)
	{
		write(1, "-", 1);
		res = (unsigned int)(0 - nbr);
	}
	else
		res = nbr;
	return (res);
}

void			ft_putnbr(int nb)
{
	unsigned int	un_nbr;
	char			digits[10];
	int				i;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb == -2147483648)
		un_nbr = ft_process_nbr(nb + 1) + 1;
	else
		un_nbr = ft_process_nbr(nb);
	i = 0;
	while (un_nbr != 0)
	{
		digits[i++] = un_nbr % 10 + '0';
		un_nbr /= 10;
	}
	while (i > 0)
		write(1, &digits[--i], 1);
	return ;
}
