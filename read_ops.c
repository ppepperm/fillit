/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:48:24 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/29 19:19:33 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int		*digitalize(char **tab)
{
	int		*data;
	int		k;
	int		error_count;
	t_point	min;

	error_count = 0;
	min.i = 4;
	min.j = 4;
	if (!(data = (int*)malloc(sizeof(int) * 8)))
		return (NULL);
	ft_bzero((void*)data, 8);
	if (!set_data(tab, data, &error_count, &min))
		return (NULL);
	k = 0;
	if (error_count != 4)
		return (free_all_ret(tab, 4, data));
	while (k < 8)
	{
		data[k] -= min.j;
		data[k + 1] -= min.i;
		k += 2;
	}
	free_tab((void**)tab, 4);
	return (data);
}

int		test_for_symbols(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#')
			return (1);
		str++;
	}
	return (0);
}

int		check_line(int ret, char ***s, char *string, int i)
{
	if (ret <= 0 && i != 0)
	{
		free_tab((void**)*s, i);
		return (-1);
	}
	if (ft_strlen(string) != 4 || test_for_symbols(string))
	{
		free(string);
		free_tab((void**)*s, i);
		return (-1);
	}
	return (1);
}

int		read_tet(int fd, char ***s)
{
	char	*string;
	int		ret;
	int		i;

	i = -1;
	if (!(*s = (char**)malloc(sizeof(char*) * 4)))
		return (-1);
	while (++i < 4)
	{
		ret = get_next_line(fd, &string);
		if (ret == 0 && i == 0)
		{
			free_tab((void**)*s, i);
			return (0);
		}
		if (check_line(ret, s, string, i) < 0)
			return (-1);
		(*s)[i] = string;
	}
	return (1);
}

t_tet	*read_file(int fd)
{
	t_tet	*head;
	t_tet	*node;
	char	**tmp;
	char	*buff;
	t_point	dot;

	dot.i = -1;
	head = NULL;
	buff = NULL;
	while (++dot.i < 26 && (dot.j = read_tet(fd, &tmp)) > 0)
	{
		if (!(node = tet_new(digitalize(tmp), 'A' + dot.i)))
			return (free_tet_null(&head, &buff));
		tet_push_back(&head, node);
		if (compare(node->data) == 0)
			return (free_tet_null(&head, &buff));
		if (get_next_line(fd, &buff) == -1 || ft_strlen(buff) > 0)
			return (free_tet_null(&head, &buff));
		if (buff)
			free_null(&buff);
	}
	if (dot.j < 0)
		return (free_tet_null(&head, &buff));
	return (head);
}
