/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:14:09 by ppepperm          #+#    #+#             */
/*   Updated: 2019/10/07 17:05:22 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

void	print_ban(int *ban)
{
	int bann = 0;

	while (bann < 8)
	{
		printf("%d ", ban[bann]);
		bann++;
	}
	printf("\n");
}

int		solve(t_tet *head, t_tab *grid, t_tet *node, t_point *pos)
{
	if (node == NULL)
		return (1);
	else if (!find_place(grid, node, pos))
	{
		printf("CANT_PLACE %c\n", node->c);
		return (0);
	}
	else
	{
		place_tet(grid, *pos, node);
		printf("PASS %c\n", node->c);
		printf("%d %d %c\n", node->pos.i, node->pos.j, node->c);
		print_tab(grid);
		if (!solve(head, grid, node->next, pos))
		{
			remove_tet(grid, *pos, node);
			//printf("REMOVED\n");
			next_dot(pos, grid);
			if (!solve(head, grid, node, pos))
			{
				printf("%d %d %c\n", node->prev->pos.i, node->prev->pos.j, node->prev->c);
				remove_tet(grid, node->prev->pos, node->prev);
				ft_putendl("REMOVED_PREV");
				next_dot(&(node->prev->pos), grid);
				printf("%d %d %c\n", node->prev->pos.i, node->prev->pos.j, node->prev->c);
				if (!solve(head, grid, node->prev, &(node->prev->pos))) {
					//print_tabl(grid);
					pos->i = 0;
					pos->j = 0;
					resize_tab(&grid, grid->size + 1);
					printf("RESIZED_GRID_AT %c\n", node->c);
					return (solve(head, grid, head, pos));
				}
			}
		}
		return (1);
	}
}

int		main(int ac, char **av)
{
	int		fd;
	t_tab	*grid;
	t_tet	*tmp;
	t_tet	*freedom;
	t_point	ban;

	if (ac > 1)
	{
		fd = open(av[1], O_RDWR);
		tmp = read_file(fd);
		freedom = tmp;
		ban.j = 0;
		ban.i = 0;
		grid = new_tab(4);
		if (!tmp)
			ft_putstr("Error\n");
		while (tmp)
		{
			printf("%c ", tmp->c);
			print_ban(tmp->data);
			tmp = tmp->next;
		}
		solve(freedom, grid, freedom, &ban);
		t_tab_free(grid);
		tet_free(&freedom);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
