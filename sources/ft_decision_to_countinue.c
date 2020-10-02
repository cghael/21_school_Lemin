/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decision_to_countinue.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:46:48 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 17:49:31 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_tracks		*ft_find_longest_track(t_tracks *tracks)
{
	t_tracks		*tmp;
	t_tracks		*longest;

	tmp = tracks->next;
	longest = tracks;
	while (tmp)
	{
		if (longest->len < tmp->len)
			longest = tmp;
		tmp = tmp->next;
	}
	return (longest);
}

int					ft_decision_to_countinue(t_tracks **tracks, int ants)
{
	t_tracks		*tmp;
	t_tracks		*longest;
	t_tracks		*free;
	int				res;

	res = 1;
	tmp = *tracks;
	longest = ft_find_longest_track(*tracks);
	while (tmp)
	{
		res += longest->len - tmp->len;
		if (res > ants)
		{
			tmp = *tracks;
			while (tmp->next != longest)
				tmp = tmp->next;
			free = tmp->next;
			ft_free_tracks(free);
			tmp->next = NULL;
			return (EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
