/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:31:31 by gartaud           #+#    #+#             */
/*   Updated: 2020/09/19 17:12:06 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# define N 4

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	**ft_init(int argc, char **argv);
void	ft_obvious_case(char **tab);
void	ft_solve(char **tab);
int		ft_atoi(char *str);

#endif
