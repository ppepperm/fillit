/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:56:59 by ppepperm          #+#    #+#             */
/*   Updated: 2019/10/06 16:41:13 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tab	*new_tab(size_t size)
{
	t_tab	*tmp;
	char	**plane;
	size_t	i;

	if (!(tmp = (t_tab*)malloc(sizeof(t_tab))))
		return (NULL);
	if (!(plane = (char**)malloc(sizeof(char*) * size)))
	{
		free(tmp);
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		if (!(plane[i] = (char*)malloc(sizeof(char) * (size + 1))))
		{
			free_all(plane, i, tmp);
			return (NULL);
		}
		ft_memset((void*)plane[i], '.', size);
		plane[i][size] = 0;
	}
	tmp->grid = plane;
	tmp->size = size;
	return (tmp);
}

int		free_all(char **a, size_t i, void *b)
{
	free_tab((void**)a, i);
	free(b);
	return (0);
}

void	t_tab_free(t_tab *tab)
{
	if (!tab)
		return ;
	free_tab((void**)tab->grid, tab->size);
	free(tab);
}

void	print_tab(t_tab *tab)
{
	int i;

	i = 0;
	while (i < tab->size)
	{
		ft_putendl(tab->grid[i]);
		i++;
	}
}

int		set_data(char **tab, int *data, int *error_count, t_point *min)
{
	t_point	dot;
	int		k;

	k = 0;
	dot.i = -1;
	while (++dot.i < 4)
	{
		dot.j = -1;
		while (++dot.j < 4)
		{
			if (tab[dot.i][dot.j] == '#')
			{
				(*error_count)++;
				if (*error_count > 4)
					return (free_all(tab, 4, data));
				if (dot.i < min->i)
					min->i = dot.i;
				if (dot.j < min->j)
					min->j = dot.j;
				data[k++] = dot.j;
				data[k++] = dot.i;
			}
		}
	}
	return (1);
}
