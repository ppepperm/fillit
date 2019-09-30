/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:14:09 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/29 18:20:45 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

void print_ban(int *ban)
{
	int bann = 0;
	while (bann < 8)
	{
		printf("%d ",ban[bann]);
		bann++;
	}
	printf("\n");

}

int		solve (t_tet *head, t_tab *grid, t_tet *node)
{
	t_point pos;


}

int main(int ac, char **av)
{
	int fd;
	t_tet *tmp;
	t_tet *freedom;

	if (ac > 1)
	{
		fd = open(av[1],O_RDWR);
		tmp = read_file(fd);
		freedom = tmp;
		if (!tmp)
			ft_putstr("Error\n");
		while (tmp)
		{
			printf("%c ", tmp->c);
			print_ban(tmp->data);
			tmp = tmp->next;
		}
		tet_free(&freedom);
	}
	else
		ft_putstr("Error\n");

	return (0);
}