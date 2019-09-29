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
# include "libft.h"

typedef struct	s_tetrm
{
	long		*data;
	char	c;
	struct	s_tetrm *next;
}				t_tet;

typedef struct 	s_point
{
	int	i;
	int j;
}				t_point;

t_tet	*tet_new(long *data, char c);
void	tet_push_back(t_tet **head, t_tet *new);
void	tet_free(t_tet **begin_list);
void	free_tab(void **tab, size_t h);

t_tet	*read_file(int fd);
void print_ban(long *ban);

#endif
