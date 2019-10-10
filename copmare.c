/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copmare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:59:05 by ppepperm          #+#    #+#             */
/*   Updated: 2019/10/06 16:10:46 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compare_two(int *a, int *b)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

int		compare(int *a)
{
	int ret;

	ret = 0;
	ret = ret || compare_two(a, I_PIECE);
	ret = ret || compare_two(a, IH_PIECE);
	ret = ret || compare_two(a, O_PIECE);
	ret = ret || compare_two(a, L_PIECE);
	ret = ret || compare_two(a, LR_PIECE);
	ret = ret || compare_two(a, LD_PIECE);
	ret = ret || compare_two(a, LL_PIECE);
	ret = ret || compare_two(a, J_PIECE);
	ret = ret || compare_two(a, JR_PIECE);
	ret = ret || compare_two(a, JD_PIECE);
	ret = ret || compare_two(a, JL_PIECE);
	ret = ret || compare_two(a, T_PIECE);
	ret = ret || compare_two(a, TR_PIECE);
	ret = ret || compare_two(a, TD_PIECE);
	ret = ret || compare_two(a, TL_PIECE);
	ret = ret || compare_two(a, S_PIECE);
	ret = ret || compare_two(a, SR_PIECE);
	ret = ret || compare_two(a, Z_PIECE);
	ret = ret || compare_two(a, ZR_PIECE);
	return (ret);
}

void	next_dot(t_point *dot, t_tab *grid)
{
	if (dot->j + 1 == grid->size)
	{
		dot->j = 0;
		dot->i++;
	}
	else
		dot->j++;
}

void	prev_dot(t_point *dot, t_tab *grid)
{
	if (dot->j - 1 < 0)
	{
		dot->j = 0;
		if (dot->i != 0)
			dot->i--;
	}
	else
		dot->j--;
}

void find_dot(t_tab *grid, t_point *pos) {
	t_point tmp;

	tmp.i = 0;
	while (tmp.i < grid->size) {
		tmp.j = 0;
		while (tmp.j < grid->size) {
			if (grid->grid[tmp.i][tmp.j] == '.') {
				pos->i = tmp.i;
				pos->j = tmp.j;
				return;
			}
			tmp.j++;
		}
		tmp.i++;
	}
}