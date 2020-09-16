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

static void			ft_count_path_len(t_tracks *tracks)
{
	t_tracks	*tmp_tr;
	t_path		*tmp_p;

	tmp_tr = tracks;
	while (tmp_tr)
	{
		tmp_tr->len = 0;
		tmp_p = tmp_tr->path;
		while (tmp_p)
		{
			tmp_tr->len++;
			tmp_p = tmp_p->next;
		}
		tmp_tr = tmp_tr->next;
	}
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

t_tracks			*ft_find_paths(t_lemin *lemin)
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
		if (current->cross)
			ft_change_cross_ways(current, tracks, lemin);
		ft_count_path_len(tracks);
		//todo count DO WE NEED any more ways (steps & ants)!!!!!
		ft_print_matrix(lemin->graph, lemin->rooms, 1); //todo del
		ft_print_path(lemin->graph, tracks); //todo del
		ft_clear_lvls(lemin);
		ft_print_matrix(lemin->graph, lemin->rooms, 1);
		lvl = ft_set_levels(lemin, 0);
	}
//	ft_free_tracks(tracks);
	return (tracks);
}
