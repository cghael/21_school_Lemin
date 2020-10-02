/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_ants_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:41:29 by cghael            #+#    #+#             */
/*   Updated: 2020/09/16 13:41:31 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_create_ant_arrays(t_tracks *tracks)
{
	int			i;
	t_tracks	*tmp_tr;
	t_path		*tmp_p;

	tmp_tr = tracks;
	while (tmp_tr)
	{
		if (!(tmp_tr->ants = (t_ant*)ft_memalloc(sizeof(t_ant) * tmp_tr->len)))
			return (EXIT_FAILURE);
		tmp_p = tmp_tr->path;
		i = 0;
		while (tmp_p && i < tmp_tr->len)
		{
			tmp_tr->ants[i].room = tmp_p->to;
			i++;
			tmp_p = tmp_p->next;
		}
		tmp_tr = tmp_tr->next;
	}
	return (EXIT_SUCCESS);
}

void			ft_run_ants_run(t_lemin *lemin, t_tracks *tracks)
{
	if (ft_find_one_step_solution(lemin, tracks))
		return ;
	ft_sort_tracks(&tracks);
	if (EXIT_FAILURE == ft_create_ant_arrays(tracks))
		ft_error_n_exit("Error in ft_run_ants_run()\n", lemin, NULL, tracks);
	ft_ants_choose_ways(lemin, tracks);
	ft_ants_mooving(lemin, tracks);
}
