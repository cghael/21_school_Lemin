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

t_return			ft_return(int res, int cross)
{
	t_return	tmp;
	tmp.cross = cross;
	tmp.res = res;
	return (tmp);
}

static t_path		*ft_add_path(t_path **path, char *name, int from, int to)
{
	t_path *tmp;

	if (!(tmp = ft_memalloc(sizeof(t_path))))
		return (NULL);
	tmp->from = from;
	tmp->to = to;
	tmp->name = name;
	tmp->next = NULL;
	if (*path)
		tmp->next = *path;
	*path = tmp;
	return (*path);
}

static t_return 	ft_find_from_room(t_lemin *lemin, int lvl, int to, \
																t_path **path)
{
	int			from;
	int			cross;

	cross = 0;
	from = 0;
	while (from < lemin->rooms)
	{
		if (lemin->graph[to].links[from].lk == 1 \
			&& lemin->graph[from].level == lvl \
			&& lemin->graph[from].links[to].way < 1)
		{
			(*path)->from = from;
			if (!ft_add_path(path, lemin->graph[from].name, 0, from))
				return (ft_return(-1, 0));
			//todo if we met -1
			if (lemin->graph[from].links[to].way == -1)
				cross = 1;
			lemin->graph[from].links[to].way = 1;
			lemin->graph[to].links[from].way = -1;
			return (ft_return(from, cross));
		}
		from++;
	}
	return (ft_return(-1, 0));
}

t_return		ft_write_path(t_lemin *lemin, int lvl, t_path **path)
{
	int			to;
	t_return	ret;

	to = lemin->end;
	if (!ft_add_path(path, lemin->graph[lemin->end].name, 0, lemin->end))
		return (ft_return(EXIT_FAILURE, 0));
	while (lvl > 0)
	{
		ret = ft_find_from_room(lemin, lvl, to, path);
		if (ret.res == -1)
			return (ft_return(EXIT_FAILURE, 0));
		to = ret.res;
		lvl--;
	}
	(*path)->from = lemin->start;
	lemin->graph[to].links[lemin->start].way = -1;
	lemin->graph[lemin->start].links[to].way = 1;
	return (ft_return(EXIT_SUCCESS, 0));
}
