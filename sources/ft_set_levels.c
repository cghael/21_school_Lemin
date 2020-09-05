/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_levels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:27:54 by cghael            #+#    #+#             */
/*   Updated: 2020/09/04 16:27:55 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#define END_FOUND	-1
#define LVL_FOUND	1
#define NOT_FOUND	0

static int		ft_first_lvl_set(t_lemin *lemin)
{
	int 	i;
	int		find;

	i = 0;
	find = NOT_FOUND;
	while (i < lemin->rooms)
	{
		if (lemin->graph[lemin->start].links[i].lk == 1)
		{
			if (i == lemin->end)
				return (END_FOUND);
			lemin->graph[i].level = 1;
			find = LVL_FOUND;
		}
		i++;
	}
	return (find ? LVL_FOUND : NOT_FOUND);
}

static int		ft_set_lvl_on_links(t_lemin *lemin, int j, int lvl)
{
	int i;
	int find;

	find = NOT_FOUND;
	i = 0;
	while (i < lemin->rooms)
	{
		if (lemin->graph[j].links[i].lk == 1 \
					&& lemin->graph[i].level == 0 && i != lemin->start)
		{
			if (i == lemin->end)
				return (END_FOUND);
			lemin->graph[i].level = lvl + 1;
			find = LVL_FOUND;
		}
		i++;
	}
	return (find);
}

static int		ft_set_not_first_levels(t_lemin *lemin, int lvl)
{
	int	j;
	int	find;

	j = 0;
	find = NOT_FOUND;
	while (j < lemin->rooms)
	{
		if (lemin->graph[j].level == lvl)
		{
			find = ft_set_lvl_on_links(lemin, j, lvl);
			if (find == END_FOUND)
				return (END_FOUND);
		}
		j++;
	}
	return (find ? LVL_FOUND : NOT_FOUND);
}

int		ft_set_levels(t_lemin *lemin, int lvl)
{
	int	res;

	if (lvl == 0)
	{
		res = ft_first_lvl_set(lemin);
		if (res == END_FOUND)
			return (lvl);
		else if (res == NOT_FOUND)
			return (-1);
	}
	else
	{
		res = ft_set_not_first_levels(lemin, lvl);
		if (res == END_FOUND)
			return (lvl);
		else if (res == NOT_FOUND)
			return (-1);
	}
	return (ft_set_levels(lemin, lvl + 1));
}
