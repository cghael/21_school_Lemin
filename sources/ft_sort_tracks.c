/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tracks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:14:06 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 17:40:18 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_swap_two_tracks(t_tracks **tracks, t_tracks *current)
{
	t_tracks	*tmp;
	t_tracks	*prev;

	tmp = *tracks;
	if (tmp->next == current)
	{
		tmp->next = current->next;
		*tracks = current;
		current->next = tmp;
	}
	else
	{
		while (tmp->next != current)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		tmp->next = current->next;
		prev->next = current;
		current->next = tmp;
	}
}

void		ft_sort_tracks(t_tracks **tracks)
{
	int			flag;
	t_tracks	*current;
	t_tracks	*prev;

	flag = 1;
	if (!(*tracks)->next)
		return ;
	while (flag)
	{
		flag = 0;
		prev = *tracks;
		current = (*tracks)->next;
		while (current)
		{
			if (current->len < prev->len)
			{
				ft_swap_two_tracks(tracks, current);
				flag = 1;
			}
			prev = current;
			current = current->next;
		}
	}
}
