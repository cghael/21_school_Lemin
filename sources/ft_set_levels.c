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

static int		ft_first_lvl_set(t_lemin *lemin)
{
	int i;

	i = 0;
	while (i < lemin->rooms)
	{
		if (lemin->graph[lemin->start].links[i].lk == 1)
		{
			if (i == lemin->end)
				return (1);
			lemin->graph[i].level = 1;
		}
		i++;
	}
	return (0);
}

static int		ft_set_not_first_levels(t_lemin *lemin, int lvl)
{
	int	i;
	int	j;

	j = 0;
	while (j < lemin->rooms)
	{
		i = 0;
		if (lemin->graph[j].level == lvl)
		{
			while (i < lemin->rooms)
			{
				if (lemin->graph[j].links[i].lk == 1 \
					&& lemin->graph[i].level == 0 && i != lemin->start)
				{
					if (i == lemin->end)
						return (1);
					lemin->graph[i].level = lvl + 1;
				}
				i++;
			}
		}
		j++;
	}
	return (0);
}

int		ft_set_levels(t_lemin *lemin, int lvl)
{
	if (lvl == 0)
	{
		if (ft_first_lvl_set(lemin))
			return (lvl);
	}
	else
	{
		if (ft_set_not_first_levels(lemin, lvl))
			return (lvl);
	}
//	ft_print_matrix(lemin->graph, lemin->rooms);
	return (ft_set_levels(lemin, lvl + 1));
}
