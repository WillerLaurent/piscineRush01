/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:04:52 by gartaud           #+#    #+#             */
/*   Updated: 2020/09/19 17:32:31 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_isspace(char c)
{
	return ((c == '\n') || (c == '\r') || (c == '\t') ||
			(c == '\v') || (c == '\f') || (c == ' '));
}

int	ft_is_numeric(char c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_atoi(char *str)
{
	int res;
	int sgn;

	while (ft_isspace(*str))
		str++;
	sgn = 1;
	while ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sgn *= -1;
		str++;
	}
	res = 0;
	while (ft_is_numeric(*str))
		res = res * 10 + (*str++) - '0';
	return (sgn * res);
}
