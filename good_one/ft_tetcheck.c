/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:37:12 by blebrass          #+#    #+#             */
/*   Updated: 2017/12/20 11:59:32 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_input(char *tetri, int ret)
{
	int		x;
	int		hashtag;
	int		newline;

	x = 0;
	hashtag = 0;
	newline = 0;
	while (tetri[x] != 0)
	{
		if ((tetri[x] != '.' && tetri[x] != '#' && tetri[x] != '\n') ||
				hashtag > 4 || (tetri[x] == '\n' && x % 5 != 4 && x != 20))
			return (ft_error());
		if (tetri[x] == '\n')
			newline++;
		if (tetri[x] == '#')
			hashtag++;
		x++;
	}
	if (newline != 5 || x != 21)
		if (newline != 4 || x != 20 || ret != 20)
			return (ft_error());
	return ((x == 21) ? 1 : 2);
}

static void	mktet(int *data, char **tetri, t_tet **tet, int lette)
{
	t_tet	*new;

	if (data[0] < 3 && tetri[data[1]][data[0] + 1] == '#')
		data[2]++;
	if (data[1] < 3 && tetri[data[1] + 1][data[0]] == '#')
		data[2]++;
	if (data[5] == 0)
	{
		data[3] = data[0];
		data[4] = data[1];
		new = ft_tetnew((data[0] - data[3]), (data[1] - data[4]), lette);
		ft_tetadd(tet, new);
		data[5] = 1;
	}
	else
	{
		new = ft_tetnew((data[0] - data[3]), (data[1] - data[4]), lette);
		ft_tetadd(tet, new);
	}
}

/*
**data[0] = x, data[1] = y, data[2] = connect, data[3] = fpx, data[4] = fpy,
**data[5] = flag;
*/

int			valid_tetri(char **tetri, t_tet **tet, int lette)
{
	int		data[6];
	int		i;

	i = 0;
	while (i < 6)
		data[i++] = 0;
	*tet = NULL;
	while (data[1] < 4)
	{
		while (data[0] < 4)
		{
			if (tetri[data[1]][data[0]] == '#')
			{
				mktet(data, tetri, tet, lette);
			}
			data[0]++;
		}
		data[0] = 0;
		data[1]++;
	}
	if (data[2] < 3 || data[2] > 4)
		return (-1);
	return (1);
}
