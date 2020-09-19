#include "../includes/ft.h"

int		ft_count_colup(char **tab, int j)
{
	int i;
	int	max;
	int	res;

	i = 0;
	max = tab[i + 1][j];
	res = (max != 0);
	while (++i < 5)
		if (tab[i][j] && tab[i][j] > max)
		{
			res++;
			max = tab[i][j];
		}
	return (res);
}

int		ft_count_coldown(char **tab, int j)
{
	int i;
	int	max;
	int	res;

	i = 5;
	max = tab[i - 1][j];
	res = (max != 0);
	while (--i > 0)
		if (tab[i][j] && tab[i][j] > max)
		{
			res++;
			max = tab[i][j];
		}
	return (res);
}

int		ft_count_rowright(char **tab, int i)
{
	int j;
	int	max;
	int	res;

	j = 5;
	max = tab[i][j - 1];
	res = (max != 0);
	while (--j > 0)
		if (tab[i][j] && tab[i][j] > max)
		{
			res++;
			max = tab[i][j];
		}
	return (res);
}

int		ft_count_rowleft(char **tab, int i)
{
	int j;
	int	max;
	int	res;

	j = 0;
	max = tab[i][j + 1];
	res = (max != 0);
	while (++j < 5)
		if (tab[i][j] && tab[i][j] > max)
		{
			res++;
			max = tab[i][j];
		}
	return (res);
}
