/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:53:27 by blebrass          #+#    #+#             */
/*   Updated: 2017/12/20 12:00:35 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	addlst(t_tet **tet, t_list **list)
{
	t_list	*new;
	t_list	*ptr;

	new = (t_list*)malloc(sizeof(t_list));
	new->content = *tet;
	new->next = NULL;
	if (*list == NULL)
		ft_lstadd(list, new);
	else
	{
		ptr = *list;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

static int	nbcheck(int *i, char *tetri, int ret, char ***tab)
{
	*i = check_input(tetri, ret);
	if (*i == -1 || *tab == NULL)
		return (-1);
	*tab = create_tab(tetri);
	return (1);
}

static int	rdfl(int fd, int tet_count, char *tetri, t_list **list)
{
	int			ret;
	char		**tab;
	int			lette;
	t_tet		**tet;
	int			i;

	lette = 'A';
	tet = (t_tet **)malloc(sizeof(t_tet *));
	ret = read(fd, tetri, 21);
	if (ret < 20)
		return (ft_error());
	tetri[ret] = '\0';
	while (ret > 0)
	{
		if (nbcheck(&i, tetri, ret, &tab) == -1)
			return (-1);
		if (valid_tetri(tab, tet, lette++) == -1)
			return (ft_error());
		addlst(tet, list);
		tet_count++;
		ret = read(fd, tetri, 21);
		tetri[ret] = '\0';
	}
	return ((i == 1) ? ft_error() : tet_count);
}

int			read_file(char **argv)
{
	int			fd;
	int			tet_count;
	char		*tetri;
	t_list		**list;

	list = (t_list**)malloc(sizeof(t_list *));
	*list = NULL;
	tet_count = 0;
	tetri = (char*)malloc((20 + 2) * sizeof(char));
	fd = open(argv[1], O_RDONLY);
	if (rdfl(fd, tet_count, tetri, list) == -1)
		return (-1);
	if (tet_count > 26)
		return (ft_error());
	ft_mkfl(list);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (-1);
	}
	read_file(argv);
	return (0);
}
