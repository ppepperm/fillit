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

int		check(t_tab *grid, t_point pos, t_tet *node, int i)
{
	int *data;

	data = node->data;
	if (!(pos.i + data[i + 1] < grid->size && pos.j + data[i] < grid->size) \
	|| pos.i + data[i + 1] < 0 || pos.j + data[i] < 0)
		return (0);
	else if (grid->grid[pos.i + data[i + 1]][pos.j + data[i]] != '.')
		return (0);
	return (1);
}

int		check_place(t_tab *grid, t_point pos, t_tet *node)
{
	if (!check(grid, pos, node, 0))
		return (0);
	if (!check(grid, pos, node, 2))
		return (0);
	if (!check(grid, pos, node, 4))
		return (0);
	if (!check(grid, pos, node, 6))
		return (0);
	return (1);
}

void	place_tet(t_tab *grid, t_point pos, t_tet *tet)
{
	grid->grid[pos.i + tet->data[1]][pos.j + tet->data[0]] = tet->c;
	grid->grid[pos.i + tet->data[3]][pos.j + tet->data[2]] = tet->c;
	grid->grid[pos.i + tet->data[5]][pos.j + tet->data[4]] = tet->c;
	grid->grid[pos.i + tet->data[7]][pos.j + tet->data[6]] = tet->c;
}

void	free_null(char **buff)
{
	free(*buff);
	*buff = NULL;
}

t_tet	*free_tet_null(t_tet **head, char **buff)
{
	if (*buff)
		free_null(buff);
	tet_free(head);
	return (NULL);
}
