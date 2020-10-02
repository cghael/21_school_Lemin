/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_choose_ways.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:51:35 by ksemele           #+#    #+#             */
/*   Updated: 2020/10/02 17:51:59 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_tracks		*ft_smallest_tmp(t_tracks *tracks)
{
	t_tracks		*tmp;
	t_tracks		*smallest;

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

void				ft_ants_choose_ways(t_lemin *lemin, t_tracks *tracks)
{
	t_tracks		*tmp;
	int				ants;

	ants = lemin->ants;
	while (ants)
	{
		tmp = ft_smallest_tmp(tracks);
		tmp->ant_num++;
		ants--;
	}
}
