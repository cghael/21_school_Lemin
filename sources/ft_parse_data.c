/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:46:15 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 17:45:27 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_print_data(t_data *data)
{
	t_data	*tmp;
	int		counter;

	tmp = data;
	counter = data->counter;
	while (counter)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
		counter--;
	}
}

static t_data	*ft_copy_ants_data(t_data *data, t_lemin *lemin)
{
	t_data	*tmp;
	t_data	*new_data;
	int		counter;

	new_data = NULL;
	counter = data->counter;
	while (counter)
	{
		if ((tmp = (t_data*)ft_memalloc(sizeof(t_data))) == NULL)
		{
			ft_free_data(&tmp);
			ft_error_n_exit("Error in ft_copy_ants_data()\n", \
														lemin, &data, NULL);
		}
		tmp->content = NULL;
		tmp->next = NULL;
		tmp->back = NULL;
		tmp->content = ft_strdup(data->content);
		ft_add_tmp_to_data(tmp, &new_data);
		data = data->next;
		counter--;
	}
	return (new_data);
}

t_lemin			*ft_parse_data(t_lemin *lemin)
{
	t_data	*data;
	t_data	*tmp;

	data = NULL;
	ft_parse_ants(lemin, &data);
	tmp = ft_copy_ants_data(data, lemin);
	ft_free_data(&data);
	ft_parse_rooms(lemin, &data);
	ft_create_graph(lemin, &data);
	ft_parse_links(lemin, &data);
	if (!lemin->visual && lemin->fd_sol == 1)
	{
		ft_print_data(tmp);
		ft_print_data(data);
		ft_printf("\n");
	}
	ft_free_data(&tmp);
	ft_free_data(&data);
	return (lemin);
}
