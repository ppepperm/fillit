/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:47:43 by ppepperm          #+#    #+#             */
/*   Updated: 2019/10/06 16:32:07 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define I_PIECE (int [8]) {0,0,0,1,0,2,0,3}
# define IH_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]) {0,0,1,0,0,1,1,1}
# define L_PIECE (int [8]) {0,0,0,1,0,2,1,2}
# define LR_PIECE (int [8]) {0,0,1,0,1,1,1,2}
# define LD_PIECE (int [8]) {0,0,1,0,2,0,0,1}
# define LL_PIECE (int [8]) {0,0,-2,1,-1,1,0,1}
# define J_PIECE (int [8]) {0,0,1,0,0,1,0,2}
# define JR_PIECE (int [8]) {0,0,0,1,-1,2,0,2}
# define JD_PIECE (int [8]) {0,0,0,1,1,1,2,1}
# define JL_PIECE (int [8]) {0,0,1,0,2,0,2,1}
# define T_PIECE (int [8]) {0,0,0,1,1,1,1,2}
# define TR_PIECE (int [8]) {0,0,1,0,-1,1,0,1}
# define TD_PIECE (int [8]) {0,0,-1,1,0,1,-1,2}
# define TL_PIECE (int [8]) {0,0,1,0,1,1,2,1}
# define S_PIECE (int [8]) {0,0,-1,1,0,1,1,1}
# define SR_PIECE (int [8]) {0,0,-1,1,0,1,0,2}
# define Z_PIECE (int [8]) {0,0,0,1,1,1,0,2}
# define ZR_PIECE (int [8]) {0,0,1,0,2,0,1,1}

# include "libft.h"
# include "colors.h"

typedef struct		s_tab
{
	char			**grid;
	int				size;
}					t_tab;

typedef struct		s_point
{
	int				i;
	int				j;
}					t_point;

typedef struct		s_tetrm
{
	int				*data;
	char			c;
	struct s_tetrm	*next;
}					t_tet;

t_tet				*tet_new(int *data, char c);
void				tet_push_back(t_tet **head, t_tet *new);
void				tet_free(t_tet **begin_list);
void				free_tab(void **tab, size_t h);
int					free_all(char **a, size_t i, void *b);

t_tet				*read_file(int fd);

int					compare(int *a);
void				next_dot(t_point *dot, t_tab *grid);
t_point				find_dot(t_tab *grid);
int					check_grid(t_tab *grid, t_tet *head);
int					set_data(char **tab, int *data,
		int *error_count, t_point *min);

t_tab				*new_tab(size_t size);
void				t_tab_free(t_tab *tab);
void				print_tab(t_tab *tab);

int					check_place(t_tab *grid, t_point pos, t_tet *node);
void				place_tet(t_tab *grid, t_point pos, t_tet *tet);
void				free_null(char **buff);
t_tet				*free_tet_null(t_tet **head, char **buff);

void				print_tabl(t_tab *tab);

t_tab				*do_solve(t_tet *head, int size);

#endif
