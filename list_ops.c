/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:24:02 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/24 16:24:07 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*tet_new(int *data, char c)
{
	t_tet	*tmp;

	if(!(tmp = (t_tet*)malloc(sizeof(t_tet))) || !data)
		return (NULL);
	tmp->data = data;
	tmp->c = c;
	tmp->next = NULL;
	return (tmp);
}

void	tet_push_back(t_tet **head, t_tet *new)
{
	t_tet	*tmp;

	if (!(*head))
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	free_tab(void **tab, size_t h)
{
	while (h)
	{
		free(tab[h - 1]);
	}
	free(tab);
}

void	tet_free(t_tet **begin_list)
{
	t_tet *buff;

	if(!*begin_list)
		return ;
	buff = *begin_list;
	while (buff)
	{
		*begin_list = buff->next;
		free(buff->data);
		free(buff);
		buff = *begin_list;
	}
}
