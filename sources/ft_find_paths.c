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

void				ft_count_p_len(t_tracks	*tracks)
{
	t_tracks *tmp1;
	t_path *tmp2;
	int counter;

	tmp1 = tracks;
	while (tmp1)
	{
		counter = 0;
		tmp2 = tmp1->path;
		while (tmp2)
		{
			counter++;
			tmp2 = tmp2->next;
		}
		ft_printf(">>>\np_len = %d\n", counter);
		tmp1 = tmp1->next;
	}
	ft_printf("-------END ITERATION-------\n\n");
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
//		ft_print_matrix(lemin->graph, lemin->rooms, 0); //todo del
		if ((current = ft_write_path(lemin, lvl, &tracks)) == NULL)
			ft_error_n_exit("Error in ft_write_paths()\n", lemin, NULL, tracks);
		ft_count_p_len(tracks);//todo del
		ft_count_path_len(tracks);
		if (EXIT_FAILURE == ft_decision_to_countinue(&tracks, lemin->ants))
		{
			ft_count_p_len(tracks);//todo del
			return (tracks);
		}
		if (current->cross)
		{
//			if (lvl == 126)
//				ft_printf("");
			ft_change_cross_ways(current, tracks, lemin);
			ft_printf("CROSS>>>\n");//todo del
			ft_count_p_len(tracks);//todo del
		}
		ft_count_path_len(tracks);
		//todo count DO WE NEED any more ways (steps & ants)!!!!!
//		ft_print_matrix(lemin->graph, lemin->rooms, 1); //todo del
//		ft_print_path(lemin->graph, tracks); //todo del
		ft_clear_lvls(lemin);
//		ft_print_matrix(lemin->graph, lemin->rooms, 1);
		lvl = ft_set_levels(lemin, 0);
	}
//	ft_free_tracks(tracks);
	return (tracks);
}
