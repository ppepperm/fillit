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

int			error_print(void)
{
	ft_putstr("error\n");
	return (0);
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
	return (size);
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

int			check_endl(int fd, t_tet *head)
{
	int		t_count;
	int		n_count;
	char	buff[1024];
	int		i;

	ft_bzero(buff, 1024);
	read(fd, buff, 1023);
	t_count = 0;
	n_count = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			n_count++;
		i++;
	}
	while (head)
	{
		t_count++;
		head = head->next;
	}
	return (n_count == t_count * 4 + t_count - 1);
}

int			main(int ac, char **av)
{
	int		fd;
	t_tab	*grid;
	t_tet	*tmp;

	if (ac == 2 && (fd = open(av[1], O_RDWR)) > 0)
	{
		tmp = read_file(fd);
		if (!tmp)
			return (error_print());
		close(fd);
		fd = open(av[1], O_RDWR);
		if (!check_endl(fd, tmp))
		{
			tet_free(&tmp);
			return (error_print());
		}
		grid = fillit(tmp);
		print_tab(grid);
		t_tab_free(grid);
		tet_free(&tmp);
	}
	else if (ac != 2)
		ft_putstr("usage: ./fillit input_file\n");
	else
		return (error_print());
}
