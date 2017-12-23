/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:26:31 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 12:00:25 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*ft_tetnew(int x, int y, int let)
{
	t_tet	*new;

	new = (t_tet *)malloc(sizeof(t_tet));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->plc = 0;
	new->let = let;
	new->next = NULL;
	return (new);
}
