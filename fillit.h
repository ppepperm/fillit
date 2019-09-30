/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:47:43 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/25 16:47:46 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define I_PIECE (int [8]) {0,0,0,1,0,2,0,3}
# define IH_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]) {0,0,1,0,0,1,1,1}
# define L_PIECE (int [8]) {0,0,0,1,0,2,1,2}
# define LR_PIECE (int [8]) {0,0,1,0,2,0,0,1}
# define LD_PIECE (int [8]) {0,0,1,0,1,1,1,2}
# define LL_PIECE (int [8]) {2,0,0,1,1,1,2,1}
# define J_PIECE (int [8]) {1,0,1,1,0,2,1,2}
# define JR_PIECE (int [8]) {0,0,0,1,1,1,2,1}
# define JD_PIECE (int [8]) {0,0,1,0,0,1,0,2}
# define JL_PIECE (int [8]) {0,0,1,0,2,0,2,1}
# define T_PIECE (int [8]) {1,0,0,1,1,1,2,1}
# define TR_PIECE (int [8]) {0,0,0,1,1,1,0,2}
# define TD_PIECE (int [8]) {0,0,1,0,2,0,1,1}
# define TL_PIECE (int [8]) {1,0,0,1,1,1,1,2}
# define S_PIECE (int [8]) {1,0,2,0,0,1,1,1}
# define SR_PIECE (int [8]) {0,0,0,1,1,1,1,2}
# define Z_PIECE (int [8]) {0,0,1,0,1,1,2,1}
# define ZR_PIECE (int [8]) {1,0,0,1,1,1,0,2}
# include "libft.h"

typedef struct	s_tab
{
	char	**grid;
	int		size;
}				t_tab;

typedef struct	s_tetrm
{
	int		*data;
	char	c;
	struct	s_tetrm *next;
}				t_tet;

typedef struct 	s_point
{
	int	i;
	int j;
}				t_point;

t_tet	*tet_new(int *data, char c);
void	tet_push_back(t_tet **head, t_tet *new);
void	tet_free(t_tet **begin_list);
void	free_tab(void **tab, size_t h);

t_tet	*read_file(int fd);
void print_ban(int *ban);

int compare(int *a);

t_tab	*new_tab(size_t size);
void	t_tab_free(t_tab *tab);
void	resize_tab(t_tab **tab, size_t new_size);
void	print_tab(t_tab *tab);

int		check_place(t_tab *grid, t_point pos, int *data);
void	place_tet(t_tab *grid, t_point pos, t_tet *tet);

#endif