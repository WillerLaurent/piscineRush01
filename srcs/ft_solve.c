#include "../includes/ft.h"

int		ft_is_move_valid(char **tab, int i, int j, int value)
{
	int	res;
	int	x;
	int	y;
	int count;

	printf("=== ENTREE IS_VALID ===\n\n");
	if (tab[i][j] != 0 || value <= 0 || value > N ||
		i <= 0 || i >= N + 1 || j <= 0 || j >= N + 1)
		return (0);
	printf("\tTests de base passés !\n");
	tab[i][j] = value;

	printf("\tcount_rl = %d, tab[%d][0] = %d\n", ft_count_rowleft(tab, i), i, tab[i][0]);
	printf("\tcount_rr = %d, tab[%d][%d] = %d\n", ft_count_rowright(tab, i), i, N + 1, tab[i][N + 1]);
	printf("\tcount_cu = %d, tab[0][%d] = %d\n", ft_count_colup(tab, j), j, tab[0][j]);
	printf("\tcount_cd = %d, tab[%d][%d] = %d\n", ft_count_colup(tab, j), j, N + 1, tab[N + 1][j]);


	printf("\tcond rl = %d\n", (ft_count_rowleft(tab, i) <= tab[i][0]));
	printf("\tcond rr = %d\n", (ft_count_rowright(tab, i) <= tab[i][N + 1]));
	printf("\tcond cu = %d\n", (ft_count_colup(tab, j) <= tab[0][j]));
	printf("\tcond cd = %d\n", (ft_count_coldown(tab, j) <= tab[N + 1][j]));

	res = ((ft_count_rowleft(tab, i) <= tab[i][0]) &&
			(ft_count_rowright(tab, i) <= tab[i][N + 1]) &&
			(ft_count_colup(tab, j) <= tab[0][j]) &&
			(ft_count_coldown(tab, j) <= tab[N + 1][j]));
	printf("\tTests de count passés ! (res = %d)\n", res);
	y = 0;
	count = 0;
	while (++y < N + 1)
	{
		if (tab[y][j] == value)
			count++;
		if (count > 1)
			res = 0;
	}
//	printf("\tTests de doublons vertical passés ! (res = %d)\n", res);
	x = 0;
	count = 0;
	while (++x < N + 1)
	{
		if (tab[i][x] == value)
			count++;
		if (count > 1)
			res = 0;
	}
//	printf("\tTests de doublons horizonto passés ! (res = %d)\n", res);
	tab[i][j] = 0;
//	printf("\tres = %d\n", res);
//	printf("=== SORTIE IS_VALID ===\n\n");
	return (res);
}

void	ft_next_empty_space(char **tab, int *i, int *j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++y <= N)
	{
		x = 0;
		while (++x <= N)
			if (!tab[y][x])
			{
				*i = y;
				*j = x;
				return ;
			}
	}
	return ;
}

int		ft_solve(char **tab, int move_left)
{
	int next_move;
	int	i;
	int j;

	//printf("\n\n");
	//ft_putsol(tab);
	if (move_left == 0)
	{
		//ft_putsol(tab);
		printf("J'AI TROUVE UNE SOLUTION !!! :))))\n\n");
		return (1);
	}
	ft_next_empty_space(tab, &i, &j);
//	printf("(i, j) = (%d, %d)\n", i, j);
	next_move = 0;
	while (++next_move <= N)
	{
		printf("On va tenter : %d\n", next_move);
		printf("\n");
		if (ft_is_move_valid(tab, i, j, next_move))
		{
			tab[i][j] = next_move;
			ft_putsol(tab);
			if (ft_solve(tab, move_left - 1))
				return (1);
			tab[i][j] = 0;
		}
	}
	return (0);
}
