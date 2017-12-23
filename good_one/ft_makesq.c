/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makesq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:06:59 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 11:58:35 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_fitpt(char *new, int size)
{
	int		i;

	i = 0;
	while (i < size)
		new[i++] = '.';
	new[i] = '\0';
	return (new);
}

/*
**the following function build a square full of point.
*/

char		**ft_makesq(int side)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(side * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < side)
	{
		tab[i] = ft_strnew(side);
		if (!tab[i])
			return (NULL);
		tab[i] = ft_fitpt(tab[i], side);
		i++;
	}
	return (tab);
}
