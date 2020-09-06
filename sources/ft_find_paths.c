/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:16:45 by cghael            #+#    #+#             */
/*   Updated: 2020/09/04 15:16:46 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path		*ft_add_path(t_path **path, char *name)
{
	t_path *tmp;

	if (!(tmp = ft_memalloc(sizeof(t_path))))
		return (NULL);
	tmp->name = name;
	tmp->next = NULL;
	if (*path)
		tmp->next = *path;
	*path = tmp;
	return (*path);
}

static int		ft_find_from_room(t_lemin *lemin, int lvl, int to, \
																t_path **path)
{
	int from;

	from = 0;
	while (from < lemin->rooms)
	{
		if (lemin->graph[to].links[from].lk == 1 \
			&& lemin->graph[from].level == lvl \
			&& lemin->graph[from].links[to].way < 1)
		{
			if (!ft_add_path(path, lemin->graph[from].name))
				return (-1);
			lemin->graph[from].links[to].way = 1;
			lemin->graph[to].links[from].way = -1;
			return (from);
		}
		from++;
	}
	return (-1);
}

static int		ft_write_path(t_lemin *lemin, int lvl, t_path **path)
{
	int	to;

	to = lemin->end;
	while (lvl > 0)
	{
		if ((to = ft_find_from_room(lemin, lvl, to, path)) == -1)
			return (EXIT_FAILURE);
		lvl--;
	}
	if (!ft_add_path(path, lemin->graph[lemin->start].name))
		return (EXIT_FAILURE);
	lemin->graph[to].links[lemin->start].way = -1;
	lemin->graph[lemin->start].links[to].way = 1;
	return (EXIT_SUCCESS);
}

void			ft_find_paths(t_lemin *lemin)
{
	int		lvl;
	t_path	*path;

	path = NULL;
	if (!ft_add_path(&path, lemin->graph[lemin->end].name))
	{
		//todo free path
		ft_error_n_exit("Error in ft_find_paths()\n", lemin, NULL);
	}
	lvl = ft_set_levels(lemin, 0);
	if (lvl == -1)
	{
		//todo if not found lvl
		return ;
	}
	ft_print_matrix(lemin->graph, lemin->rooms, 0);
	if (EXIT_FAILURE == ft_write_path(lemin, lvl, &path)) //todo if error
	{
		//todo free path
		ft_error_n_exit("Error in ft_find_paths()\n", lemin, NULL);
	}
	ft_print_matrix(lemin->graph, lemin->rooms, 1);
	ft_print_path(path);
}
