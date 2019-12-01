/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:33:58 by snorcros          #+#    #+#             */
/*   Updated: 2019/10/06 16:42:56 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_color_print(char c)
{
	if (c == '.')
		ft_putstr(WHITE);
	else if ((c - 65) % 7 == 0)
		ft_putstr(RED);
	else if ((c - 65) % 7 == 1)
		ft_putstr(GREEN);
	else if ((c - 65) % 7 == 2)
		ft_putstr(YELLOW);
	else if ((c - 65) % 7 == 3)
		ft_putstr(CYAN);
	else if ((c - 65) % 7 == 4)
		ft_putstr(MAGENTA);
	else if ((c - 65) % 7 == 5)
		ft_putstr(BLUE);
	else if ((c - 65) % 7 == 6)
		ft_putstr(PURPLE);
	ft_putchar(c);
}

void		print_tabl(t_tab *tab)
{
	int i;
	int j;

	i = 0;
	ft_putstr("\e[1;1H\e[2J");
	while (i < tab->size)
	{
		j = 0;
		while (tab->grid[i][j])
		{
			set_color_print(tab->grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr(EOC);
}

int			*free_all_ret(char **tab, int a, int *data)
{
	free_all(tab, a, data);
	return (NULL);
}
