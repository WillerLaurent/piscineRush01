/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:31:31 by gartaud           #+#    #+#             */
/*   Updated: 2020/09/20 15:40:47 by cmasse           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define N 4

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
char	**ft_init(int argc, char **argv);
int		ft_is_case_solvable(char **tab);
int		ft_solve(char **tab, int move_left);
int		ft_atoi(char *str);
int		ft_count_rowleft(char **tab, int i);
int		ft_count_rowright(char **tab, int i);
int		ft_count_coldown(char **tab, int j);
int		ft_count_colup(char **tab, int j);
void	ft_putsol(char **tab);

#endif
