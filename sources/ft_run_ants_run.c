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

static t_tracks	*ft_smallest_tmp(t_tracks *tracks)
{
	t_tracks	*tmp;
	t_tracks	*smallest;

	tmp = tracks;
	smallest = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if ((tmp->len + tmp->ant_num) < (smallest->len + smallest->ant_num))
			smallest = tmp;
	}
	return (smallest);
}

static void		ft_ants_choose_ways(t_lemin *lemin, t_tracks *tracks)
{
	t_tracks	*tmp;
	int			ants;

	ants = lemin->ants;
	while (ants)
	{
		tmp = ft_smallest_tmp(tracks);
		tmp->ant_num++;
		ants--;
	}
}

static int		ft_ants_tap_tap(t_ant *ants, int len, t_room *graph)
{
	int		i;
	int		res;

	res = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (ants[i].ant)
		{
			ants[i + 1].ant = ants[i].ant;
			ft_printf("L%d-%s ", ants[i + 1].ant, graph[ants[i+1].room].name);
			ants[i].ant = 0;
			if (i + 2 == len)
			{
				res++;
				ants[i + 1].ant = 0;
			}
		}
		i--;
	}
	return (res);
}

static void		ft_ants_mooving(t_lemin *lemin, t_tracks *tracks)
{
	int			ant_number;
	int			ant_start;
	int			ant_finish;
	t_tracks	*tmp;

	ant_number = 1;
	ant_start = lemin->ants;
	ant_finish = 0;
	while (ant_finish < lemin->ants)
	{
		tmp = tracks;
		while (tmp)
		{
			if (tmp->running_ants)
			{
				if (ft_ants_tap_tap(tmp->ants, tmp->len, lemin->graph))
				{
					ant_finish++;
					tmp->running_ants--;
				}
			}
			if (tmp->ant_num && ant_start)
			{
				tmp->ants[0].ant = ant_number;
				tmp->running_ants++;
				ft_printf("L%d-%s ", tmp->ants[0].ant, lemin->graph[tmp->ants[0].room].name);
				ant_number++;
				ant_start--;
				tmp->ant_num--;
			}
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}

void			ft_run_ants_run(t_lemin *lemin, t_tracks *tracks)
{
	ft_sort_tracks(&tracks);
	if (EXIT_FAILURE == ft_create_ant_arrays(tracks))
		ft_error_n_exit("Error in ft_run_ants_run()\n", lemin, NULL, tracks);
	ft_ants_choose_ways(lemin, tracks);
	ft_ants_mooving(lemin, tracks);
}
