/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:14:09 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/18 17:36:36 by ppepperm         ###   ########.fr       */
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

int main(int ac, char **av)
{
	int fd;
	t_tet *tmp;

	if (ac)
	{
		fd = open(av[1],O_RDWR);
		tmp = read_file(fd);
		while (tmp)
		{
			printf("%c ", tmp->c);
			print_ban(tmp->data);
			tmp = tmp->next;
		}
		return 0;
	}
	return (0);
}