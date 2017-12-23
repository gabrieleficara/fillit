/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:05:13 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 12:07:17 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_tet
{
	int				x;
	int				y;
	int				plc;
	int				let;
	struct s_tet	*next;
}					t_tet;

void				ft_tetadd(t_tet **alst, t_tet *ne);
t_tet				*ft_tetnew(int x, int y, int let);

char				**ft_srcsqr(t_list **head, int *side);
char				**ft_makesq(int side);
int					ft_find_sqrt(int n);
int					ft_fillsquare(t_list *head, char **tab, int *i);
void				ft_mkfl(t_list **head);
void				ft_frsqr(char ***sqr, int side);

char				**create_tab(char *tetri);
int					read_file(char **argv);
int					check_input(char *tetri, int rev);
int					valid_tetri(char **tetri, t_tet **tet, int lette);
int					ft_error(void);

#endif
