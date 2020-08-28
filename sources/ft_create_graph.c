/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:51:21 by cghael            #+#    #+#             */
/*   Updated: 2020/08/28 12:51:23 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_count_name_len(const char *str, int *len_name, int *len_x)
{
	int i;

	i = 0;
	while (str[i] != ' ')
		i++;
	*len_name = i;
	i++;
	while (str[i] != ' ')
		i++;
	*len_x = i;
}

static int		ft_copy_data_to_array(t_room *room, char *str, char command)
{
	int		len_name;
	int		len_x;

	ft_count_name_len(str, &len_name, &len_x);
	if (!(room->name = (char*)ft_memalloc(sizeof(len_name))))
		return (FALSE);
	room->name = ft_strncpy(room->name, str, len_name - 1);
	room->x = ft_atoi(&str[len_name]);
	room->y = ft_atoi(&str[len_x]);
	if (command == 's' || command == 'e')
		room->state = (command == 's') ? START : END;
	return (TRUE);
}

static void		ft_fill_graph(t_lemin *lemin, t_data **data)
{
	t_data	*tmp;
	int		i;
	int		rooms;

	i = 0;
	rooms = lemin->rooms;
	if (!(*data)->command)
	{
		if (FALSE == ft_copy_data_to_array(&lemin->graph[0], (*data)->content, '0'))
		{
			ft_free_data(data);
			ft_error_n_exit("Error in ft_create_graph()\n", lemin, LEMIN);
		}
		rooms--;
		i++;
	}
	tmp = (*data)->next;
	while (tmp != *data && rooms)
	{
		if (!tmp->command)
		{
			if (FALSE == ft_copy_data_to_array(&lemin->graph[i], tmp->content, tmp->back->command))
			{
				ft_free_data(data);
				ft_error_n_exit("Error in ft_create_graph()\n", lemin, LEMIN);
			}
			rooms--;
			i++;
		}
		tmp = tmp->next;
	}
}

void			ft_create_graph(t_lemin *lemin, t_data **data)
{
	int i;

	i = 0;
	if (!(lemin->graph = (t_room*)ft_memalloc(sizeof(t_room) * lemin->rooms)))
	{
		ft_free_data(data);
		ft_error_n_exit("Error in ft_create_graph()\n", lemin, LEMIN);
	}
	while (i < lemin->rooms)
	{
		if (!(lemin->graph[i].links = (int*)ft_memalloc(sizeof(int) * lemin->rooms)))
		{
			while (--i >= 0)
				free(lemin->graph[i].links);
			ft_free_data(data);
			ft_error_n_exit("Error in ft_create_graph()\n", lemin, LEMIN);
		}
		i++;
	}
	ft_fill_graph(lemin, data);
}
