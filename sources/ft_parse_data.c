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

static void		ft_print_data(t_data *data, int ants)
{
	t_data	*tmp;
	int		counter;

	tmp = data;
	counter = data->counter;
	ft_printf("%d\n", ants);
	while (counter)
	{
		if (tmp->command != 'c')
			ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
		counter--;
	}
	ft_printf("\n");
}

t_lemin			*ft_parse_data(t_lemin *lemin)
{
	t_data	*data;

	data = NULL;
	ft_parse_ants(lemin, &data);
	ft_free_data(&data);
	ft_parse_rooms(lemin, &data);
	ft_create_graph(lemin, &data);
	ft_parse_links(lemin, &data);
	if (!lemin->visual && !lemin->fd_map && lemin->fd_sol == 1)
		ft_print_data(data, lemin->ants);
	ft_free_data(&data);
	return (lemin);
}
