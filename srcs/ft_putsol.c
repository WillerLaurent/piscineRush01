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
			//printf("%d\n", tab[i][j]);
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
			//printf("%d\n", tab[i][j]);
			if (j != N)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return ;
}
