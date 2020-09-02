/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:46:15 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:46:17 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_print_matrix(t_room *graph, int counter)
{
	int i;
	int j;

	i = 0;

	ft_printf("   ");
	while (i < counter)
	{
		ft_printf("%3s", graph[i].name);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < counter)
	{
		j = 0;
		ft_printf("%3s", graph[i].name);
		while (j < counter)
		{
			ft_printf("%3d", graph[i].links[j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

t_lemin			*ft_parse_data(t_lemin *lemin)
{
	t_data	*data;

	data = NULL;
	ft_parse_ants(lemin, &data);
	ft_free_data(&data);
	ft_parse_rooms(lemin, &data); //todo coords are same in diff rooms
	ft_create_graph(lemin, &data);
	ft_parse_links(lemin, &data);
	ft_print_matrix(lemin->graph, lemin->rooms);
	ft_free_data(&data);
	return (lemin);
}
