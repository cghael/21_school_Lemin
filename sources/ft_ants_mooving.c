/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_mooving.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:39:13 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 18:18:26 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			ft_ants_tap_tap(t_ant *ants, int len, t_lemin *lemin, \
															t_tracks *tracks)
{
	int				i;
	int				res;

	res = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (ants[i].ant)
		{
			ants[i + 1].ant = ants[i].ant;
			ft_init_n_add_step(lemin, ants[i + 1].ant, \
												ants[i + 1].room, tracks);
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

static int			ft_ants_try_step(t_lemin *lemin, t_tracks *tmp, \
														t_tracks *tracks)
{
	int				res;

	res = ft_ants_tap_tap(tmp->ants, tmp->len, lemin, tracks);
	if (res > 0)
	{
		tmp->running_ants--;
		return (1);
	}
	return (0);
}

static int			ft_new_ant_start_step(t_lemin *lemin, t_tracks *tmp, \
											int ant_number, t_tracks *tracks)
{
	tmp->ants[0].ant = ant_number;
	tmp->running_ants++;
	ft_init_n_add_step(lemin, tmp->ants[0].ant, tmp->ants[0].room, tracks);
	tmp->ant_num--;
	return (EXIT_SUCCESS);
}

void				ft_ants_mooving(t_lemin *lemin, t_tracks *tracks)
{
	int				ant_number;
	int				ant_start;
	int				ant_finish;
	t_tracks		*tmp;

	ant_number = 1;
	ant_start = lemin->ants;
	ant_finish = 0;
	while (ant_finish < lemin->ants)
	{
		tmp = tracks;
		ft_init_n_add_print(lemin, tracks);
		while (tmp)
		{
			if (tmp->running_ants)
				ant_finish += ft_ants_try_step(lemin, tmp, tracks);
			if (tmp->ant_num && ant_start)
			{
				ft_new_ant_start_step(lemin, tmp, ant_number, tracks);
				ant_number++;
				ant_start--;
			}
			tmp = tmp->next;
		}
	}
}
