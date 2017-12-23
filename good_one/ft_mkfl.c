/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkfl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:36:06 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 12:03:17 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_mkfl(t_list **head)
{
	int		i[5];
	int		lst;
	int		j;
	char	**tab;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = ft_lstcnt(*head);
	i[4] = 0;
	lst = ft_lstcnt(*head);
	tab = ft_srcsqr(head, i + 2);
	while (ft_fillsquare(*head, tab, i) == 0)
	{
		i[0] = 0;
		i[1] = 0;
		i[4] = 0;
		tab = ft_srcsqr(head, i + 2);
	}
	j = 0;
	while (j < i[2])
		ft_putendl(tab[j++]);
	ft_frsqr(&tab, i[2]);
}
