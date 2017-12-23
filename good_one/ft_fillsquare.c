/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillsquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:47:44 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 11:57:12 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**i[0]=x, i[1]=y, i[2]=side, i[3]=lenght of the list, i[4]=no element used.
*/

static int		ft_pltet(t_tet *tet, char **tab, int *info)
{
	int		i;
	int		j;

	if (!tet)
		return (1);
	i = info[0] + (tet->x);
	j = info[1] + (tet->y);
	if (i >= info[2] || i < 0 || j >= info[2] || j < 0)
		return (0);
	if (tet->plc != 0)
		return (0);
	if (tab[j][i] != '.')
		return (0);
	if (ft_pltet(tet->next, tab, info) == 0)
		return (0);
	tab[j][i] = tet->let;
	tet->plc = 1;
	return (1);
}

static void		ft_tetcln(t_tet *tet, char **tab, int *i)
{
	int		x;
	int		y;

	while (tet != NULL)
	{
		tet->plc = 0;
		y = i[1] + tet->y;
		x = i[0] + tet->x;
		tab[y][x] = '.';
		tet = tet->next;
	}
}

static int		ft_spfnd(t_list *head, char **tab, int *i, int *xy)
{
	i[0] = xy[0];
	i[1] = xy[1];
	if (ft_pltet(head->content, tab, i) != 0)
	{
		if (ft_fillsquare(head->next, tab, i) == 1)
			return (1);
		i[0] = xy[0];
		i[1] = xy[1];
		ft_tetcln(head->content, tab, i);
	}
	return (0);
}

int				ft_fillsquare(t_list *head, char **tab, int *i)
{
	int		xy[2];

	xy[0] = 0;
	xy[1] = 0;
	if (head == NULL)
		return (1);
	while (xy[1] < i[2])
	{
		while (tab[xy[1]][xy[0]])
		{
			if (tab[xy[1]][xy[0]] == '.')
				if (ft_spfnd(head, tab, i, xy) == 1)
					return (1);
			xy[0]++;
		}
		xy[0] = 0;
		xy[1]++;
	}
	return (0);
}
