/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decision_to_countinue.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:46:48 by cghael            #+#    #+#             */
/*   Updated: 2020/09/29 11:46:51 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_tracks	*ft_find_longest_track(t_tracks *tracks)
{
	t_tracks	*tmp;
	t_tracks	*longest;

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

int			ft_decision_to_countinue(t_tracks **tracks, int ants)
{
	t_tracks	*tmp;
	t_tracks	*longest;
	int			res;

	res = 1;
	tmp = *tracks;
	longest = ft_find_longest_track(*tracks);
	while (tmp)
	{
		res += longest->len - tmp->len;
		ft_printf("ANTS = %d, RES = %d\n\n", ants, res);
		if (res > ants)
		{
			tmp = *tracks;
			while (tmp->next != longest)
				tmp = tmp->next;
			//todo free tracks
			tmp->next = NULL;
			return (EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
