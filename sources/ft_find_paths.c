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

static int			ft_count_path_len(t_path *path)
{
	int		len;
	t_path	*tmp;

	len = 0;
	tmp = path;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len); //count steps
}

static void			ft_clear_lvls(t_lemin *lemin)
{
	int i;

	i = 0;
	while (i < lemin->rooms)
	{
		lemin->graph[i].level = 0;
		i++;
	}
}

void				ft_find_paths(t_lemin *lemin)
{
	int			lvl;
	t_tracks	*tracks;
	t_tracks	*current;

	tracks = NULL;
	lvl = ft_set_levels(lemin, 0);
	while (lvl >= 0)
	{
		ft_print_matrix(lemin->graph, lemin->rooms, 0); //todo del
		if ((current = ft_write_path(lemin, lvl, &tracks)) == NULL)
			ft_error_n_exit("Error in ft_write_paths()\n", lemin, NULL, tracks);
		current->len = ft_count_path_len(current->path);
		//todo count DO WE NEED any more ways (steps & ants)
		if (current->cross)
			ft_change_cross_ways(current, tracks);
		ft_print_matrix(lemin->graph, lemin->rooms, 1); //todo del
		ft_print_path(lemin->graph, current->path, current->len); //todo del
		ft_clear_lvls(lemin);
		lvl = ft_set_levels(lemin, 0);
	}
	ft_free_tracks(tracks);
}
