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
	i = 0;
	while (i < size)
	{
		if (!(plane[i] = (char*)malloc(sizeof(char) * (size + 1))))
		{
			free_tab((void**)plane, i);
			free(tmp);
			return (NULL);
		}
		ft_memset((void*)plane[i], '.', size);
		plane[i][size] = 0;
		i++;
	}
	tmp->grid = plane;
	tmp->size = size;
	return (tmp);
}

void	t_tab_free(t_tab *tab)
{
	if (!tab)
		return ;
	free_tab((void**)tab->grid, tab->size);
	free(tab);
}

void	resize_tab(t_tab **tab, size_t new_size)
{
	t_tab_free(*tab);
	*tab = new_tab(new_size);
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
