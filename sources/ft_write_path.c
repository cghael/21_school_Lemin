/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:48:24 by cghael            #+#    #+#             */
/*   Updated: 2020/09/07 13:48:26 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			ft_add_new_cross_link(t_tracks **current, int from, \
																int to, int way)
{
	t_path	*tmp;
	t_path	*begin;

	if (!(tmp = ft_memalloc(sizeof(t_path))))
		return (EXIT_FAILURE);
	tmp->from = to;
	tmp->to = from;
	tmp->num = -way;
	tmp->next = NULL;
	begin = (*current)->cross;
	if ((*current)->cross == NULL)
		(*current)->cross = tmp;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = tmp;
	}
	return (EXIT_SUCCESS);
}

static t_path		*ft_add_path(t_path *path, int from, int to)
{
	t_path *tmp;

	if (!(tmp = ft_memalloc(sizeof(t_path))))
		return (NULL);
	tmp->from = from;
	tmp->to = to;
	tmp->next = NULL;
	if (path)
		tmp->next = path;
	path = tmp;
	return (path);
}

static t_path 		*ft_find_from_room(t_lemin *lemin, int lvl, int to, \
															t_tracks **cur)
{
	int			from;

	from = 0;
	while (from < lemin->rooms)
	{
		if (lemin->graph[to].links[from].lk == 1 \
			&& lemin->graph[from].level == lvl \
			&& lemin->graph[from].links[to].way < 1)
		{
			(*cur)->path->from = from;
			if (((*cur)->path = ft_add_path((*cur)->path, 0, from)) == NULL)
				return (NULL);
			if (lemin->graph[from].links[to].way < 0)
			{
				if (EXIT_FAILURE == ft_add_new_cross_link(cur, from, to, \
											lemin->graph[from].links[to].way))
					return (NULL);
			}
			lemin->graph[from].links[to].way = (*cur)->num;
			lemin->graph[to].links[from].way = -(*cur)->num;
			return ((*cur)->path);
		}
		from++;
	}
	return (NULL);
}

t_tracks			*ft_write_path(t_lemin *lemin, int lvl, t_tracks **tracks)
{
	int			to;
	t_tracks	*current;

	current = ft_create_new_track(tracks);
	to = lemin->end;
	if ((current->path = ft_add_path(current->path, 0, lemin->end)) == NULL)
		return (NULL);
	while (lvl > 0)
	{
		if((ft_find_from_room(lemin, lvl, to, &current)) == NULL)
			return (NULL);
		to = current->path->next->from;
		lvl--;
	}
	current->path->from = lemin->start;
	lemin->graph[to].links[lemin->start].way = -current->num;
	lemin->graph[lemin->start].links[to].way = current->num;
	return (current);
}
