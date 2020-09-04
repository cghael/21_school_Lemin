/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:38:54 by cghael            #+#    #+#             */
/*   Updated: 2020/09/04 15:38:56 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_print_matrix(t_room *graph, int counter)
{
	int i;
	int j;

	i = 0;

	ft_printf("%10c", ' ');
	while (i < counter)
	{
		ft_printf("\e[1;31m%10s\e[m", graph[i].name);
		i++;
	}
	ft_printf("\n\n");
	i = 0;
	while (i < counter)
	{
		j = 0;
		if (graph[i].state == START)
			ft_printf("\e[1;31m(S)%4c%d%c%s\e[m", '(', graph[i].level, ')', graph[i].name);
		else if (graph[i].state == END)
			ft_printf("\e[1;31m(E)%4c%d%c%s\e[m", '(', graph[i].level, ')', graph[i].name);
		else
			ft_printf("\e[1;31m%7c%d%c%s\e[m", '(', graph[i].level, ')', graph[i].name);
		while (j < counter)
		{
			ft_printf("%10d", graph[i].links[j]);
			j++;
		}
		ft_printf("\n\n");
		i++;
	}
	ft_printf("\n");
}


void	ft_print_path(t_path *path)
{
	while (path)
	{
		ft_printf("-%s", path->name);
		path = path->next;
	}
}