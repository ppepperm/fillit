/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:48:45 by ppepperm          #+#    #+#             */
/*   Updated: 2019/10/06 16:32:38 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int		check_place(t_tab *grid, t_point pos, t_tet *node)
{
	int *data;
	int ret;

	data = node->data;
	if (!(pos.i + data[1] < grid->size && pos.j + data[0] < grid->size))
		return (0);
	else if (grid->grid[pos.i + data[1]][pos.j + data[0]] != '.')
		return (0);
	if (!(pos.i + data[3] < grid->size && pos.j + data[2] < grid->size))
		return (0);
	else if (grid->grid[pos.i + data[3]][pos.j + data[2]] != '.')
		return (0);
	if (!(pos.i + data[5] < grid->size && pos.j + data[4] < grid->size))
		return (0);
	else if (grid->grid[pos.i + data[5]][pos.j + data[4]] != '.')
		return (0);
	if (!(pos.i + data[7] < grid->size && pos.j + data[6] < grid->size))
		return (0);
	else if (grid->grid[pos.i + data[7]][pos.j + data[6]] != '.')
		return (0);
	return (1);
}

void	place_tet(t_tab *grid, t_point pos, t_tet *tet)
{
	grid->grid[pos.i + tet->data[1]][pos.j + tet->data[0]] = tet->c;
	grid->grid[pos.i + tet->data[3]][pos.j + tet->data[2]] = tet->c;
	grid->grid[pos.i + tet->data[5]][pos.j + tet->data[4]] = tet->c;
	grid->grid[pos.i + tet->data[7]][pos.j + tet->data[6]] = tet->c;
	tet->pos.i = pos.i;
	tet->pos.j = pos.j;
}