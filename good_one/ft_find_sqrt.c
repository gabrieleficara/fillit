/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:03:44 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 11:57:29 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_find_sqrt find the first number with a sqrt >= of n
*/

int		ft_find_sqrt(int n)
{
	int		i;

	i = ft_sqrt(n);
	while (i == 0)
		i = ft_sqrt(++n);
	return (i);
}
