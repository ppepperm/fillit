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

int			get_size(t_tet *head)
{
	int		size;
	int		count;

	size = 0;
	count = 0;
	while (head)
	{
		count += 4;
		head = head->next;
	}
	while (size * size < count)
		size++;
	return(size);
}

t_tab		*fillit(t_tet *head)
{
	int		size;
	t_tab	*grid;

	size = get_size(head);
	grid = NULL;
	while (!grid)
	{
		if (!(grid = do_solve(head, size)))
			return (0);
		if (!check_grid(grid, head))
		{
			t_tab_free(grid);
			grid = NULL;
		}
		size++;
	}
	return (grid);
}

int		main(int ac, char **av)
{
	int		fd;
	t_tab	*grid;
	t_tet	*tmp;

	if (ac > 1)
	{
		fd = open(av[1], O_RDWR);
		tmp = read_file(fd);
		if (!tmp)
			ft_putstr("Error\n");
		grid = fillit(tmp);
		print_tab(grid);
		t_tab_free(grid);
		tet_free(&tmp);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
