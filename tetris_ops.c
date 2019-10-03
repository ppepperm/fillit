/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:48:45 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/30 16:48:46 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int		check_place(t_tab *grid, t_point pos, t_tet *node)
{
	int *data;
	int ret;

	data = node->data;
	printf("CHECK_BEGIN %c\n",node->c);
	ret = 1;
	ret = ret && (grid->grid[pos.i + data[1]][pos.j + data[0]] == '.' && pos.i + data[1] < grid->size &&
				  pos.j + data[0] < grid->size);
	ret = ret && (grid->grid[pos.i + data[3]][pos.j + data[2]] == '.' && pos.i + data[3] < grid->size &&
				  pos.j + data[2] < grid->size);
	ret = ret && (grid->grid[pos.i + data[5]][pos.j + data[4]] == '.' && pos.i + data[5] < grid->size &&
				  pos.j + data[4] < grid->size);
	ret = ret && (grid->grid[pos.i + data[7]][pos.j + data[6]] == '.' && pos.i + data[7] < grid->size &&
				  pos.j + data[6] < grid->size);
	printf("CHECK_END %c %d\n",node->c, ret);
	return (ret);
}

void	place_tet(t_tab *grid, t_point pos, t_tet *tet)
{
	grid->grid[pos.i + tet->data[1]][pos.j + tet->data[0]] = tet->c;
	grid->grid[pos.i + tet->data[3]][pos.j + tet->data[2]] = tet->c;
	grid->grid[pos.i + tet->data[5]][pos.j + tet->data[4]] = tet->c;
	grid->grid[pos.i + tet->data[7]][pos.j + tet->data[6]] = tet->c;
}

int  find_place(t_tab *grid, t_tet *node, t_point *point)
{
	printf("FIND %c\n",node->c);
	while(point->i < grid->size)
	{
		while (point->j < grid->size)
		{
			if (check_place(grid, *point, node))
				return (1);
			point->j++;
		}
		point->j = 0;
		point->i++;
	}
	return (0);
}

void	remove_tet(t_tab *grid, t_point pos, t_tet *tet)
{
	grid->grid[pos.i + tet->data[1]][pos.j + tet->data[0]] = '.';
	grid->grid[pos.i + tet->data[3]][pos.j + tet->data[2]] = '.';
	grid->grid[pos.i + tet->data[5]][pos.j + tet->data[3]] = '.';
	grid->grid[pos.i + tet->data[7]][pos.j + tet->data[4]] = '.';
}
