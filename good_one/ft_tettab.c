/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tettab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:39:20 by blebrass          #+#    #+#             */
/*   Updated: 2017/12/20 12:01:14 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_tab(char *tetri)
{
	char	**tab;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	tab = (char**)malloc(3 * sizeof(char*));
	while (i < 4)
		tab[i++] = (char*)malloc(3 * sizeof(char));
	i = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			tab[x][y] = tetri[i];
			y++;
			i++;
		}
		y = 0;
		x++;
		i++;
	}
	return (tab);
}
