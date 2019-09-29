/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:48:24 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/25 15:48:26 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int		*digitalize(char **tab)
{
	int *data;
	int k;
	t_point dot;
	t_point min;
	int error_count;

	dot.i = 0;
	min.i = 4;
	min.j = 4;
	k = 0;
	error_count = 0;
	if (!(data = (int*)malloc(sizeof(int) * 8)))
		return (NULL);
	ft_bzero((void*)data, 8);
	while (dot.i < 4)
	{
		dot.j = 0;
		while (dot.j < 4)
		{
			if (tab[dot.i][dot.j] == '#')
			{
				error_count++;
				if (error_count > 4)
				{
					free(data);
					free_tab((void**)tab, 4);
					return (NULL);
				}
				if (dot.i < min.i)
					min.i = dot.i;
				if (dot.j < min.j)
					min.j= dot.j;
				data[k] = dot.j;
				data[k + 1] = dot.i;
				k += 2;
			}
			dot.j++;
		}
		dot.i++;
	}
	k = 0;
	if (error_count != 4)
	{
		free(data);
		free_tab((void**)tab, 4);
		return (NULL);
	}
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
	while(*str)
	{
		if (*str != '.' && *str != '#')
			return (1);
		str++;
	}
	return (0);
}

int 	read_tet(int fd, char ***s)
{
	char	*string;
	int ret;
	int		i;

	i = 0;
	if(!(*s = (char**)malloc(sizeof(char*) * 4)))
		return (-1);
	while (i < 4)
	{
		ret = get_next_line(fd, &string);
		if (ret == 0 && i == 0)
		{
			free_tab((void**)*s, i);
			return (0);
		}
		if (ret <= 0 && i != 0)
		{
			free_tab((void**)*s, i);
			return (-1);
		}
		if (ft_strlen(string) > 4 || test_for_symbols(string))
		{
			free_tab((void**)*s, i + 1);
			return (-1);
		}
		(*s)[i] = string;
		i++;
	}
	return (1);
}

t_tet	*read_file(int fd)
{
	t_tet	*head;
	t_tet	*node;
	char 	**tmp;
	char 	*buff;
	t_point dot;

	dot.i = 0;
	head = NULL;
	while (dot.i < 26 && (dot.j = read_tet(fd, &tmp)) > 0)
	{
		if(!(node = tet_new(digitalize(tmp), 'A' + dot.i)))
		{
			tet_free(&head);
			return (NULL);
		}
		tet_push_back(&head, node);
		if (get_next_line(fd,&buff) == -1)
		{
			tet_free(&head);
			free(buff);
			return (NULL);
		}
		else if (ft_strlen(buff) > 0)
		{
			tet_free(&head);
			free(buff);
			return (NULL);
		}
		free(buff);
		dot.i++;
	}
	return (head);
}