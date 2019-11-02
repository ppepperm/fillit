/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:24:02 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/29 18:23:11 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		pass(t_tet *node, t_tab *grid, t_point pos)
{
	if (grid->grid[pos.i][pos.j] != '.')
		return (0);
	if (!check_place(grid, pos, node))
		return (0);
	place_tet(grid, pos, node);
	return (1);
}

t_tab	*reverse(t_tab *grid, t_tet *node)
{
	t_point tmp;

	tmp.i = 0;
	while (tmp.i < grid->size)
	{
		tmp.j = 0;
		while (tmp.j < grid->size)
		{
			if (grid->grid[tmp.i][tmp.j] == node->c)
				grid->grid[tmp.i][tmp.j] = '.';
			tmp.j++;
		}
		tmp.i++;
	}
	return (grid);
}

t_tab	*solve(t_tet *node, t_tab *grid, t_point pos)
{
	t_point tmp;

	tmp.i = pos.i;
	tmp.j = pos.j;
	if (!node || (tmp.i + 1 == grid->size && tmp.j + 1 == grid->size))
		return (grid);
	if (pass(node, grid, pos))
	{
		if (check_grid(solve(node->next, grid, find_dot(grid)), node))
			return (grid);
		else
			grid = reverse(grid, node);
	}
	next_dot(&tmp, grid);
	return (solve(node, grid, tmp));
}

t_tab	*do_solve(t_tet *head, int size)
{
	t_point point;
	t_tab	*grid;

	point.i = 0;
	point.j = 0;
	if (!(grid = new_tab(size)))
		return (NULL);
	grid = solve(head, grid, point);
	return (grid);
}
