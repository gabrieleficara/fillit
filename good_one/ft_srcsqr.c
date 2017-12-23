/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrsqr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:45:51 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 11:58:50 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_srcsqr(t_list **head, int *side)
{
	if (*side == 0)
	{
		*side = ft_find_sqrt(4 * ft_lstcnt(*head));
		return (ft_makesq(*side));
	}
	(*side)++;
	return (ft_makesq(*side));
}
