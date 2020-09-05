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

static int		ft_write_path(t_lemin *lemin, int lvl, t_path **path)
{
	int		i;

	i = 0;
	if (lvl == 0)
	{
		if (!ft_add_path(path, lemin->graph[lemin->start].name))
			return (1);
		return (0);
	}
	if ((*path)->name == lemin->graph[lemin->end].name)
	{
		ft_add_to_end(); //todo
		while (i < lemin->rooms)
		{
			if (lemin->graph[lemin->end].links[i].lk == 1 \
			&& lemin->graph[i].level == lvl)
			{
				if (!(ft_add_path(path, lemin->graph[i].name)))
					return (1);
//			lemin->graph[lemin->end].links[i].way = 1;
				break ;
			}
			i++;
		}
	}
	else

	return (ft_write_path(lemin, lvl - 1, path));
}

void			ft_find_paths(t_lemin *lemin)
{
	int		lvl;
	t_path	*path;

	path = NULL;//todo add end
	lvl = ft_set_levels(lemin, 0);
	ft_print_matrix(lemin->graph, lemin->rooms);
	ft_write_path(lemin, lvl, &path); //todo if error
	ft_print_path(path);
}
