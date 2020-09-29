/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tracks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:14:06 by cghael            #+#    #+#             */
/*   Updated: 2020/09/16 14:14:07 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_swap_two_tracks(t_tracks **tracks, t_tracks *current)
{
	t_tracks	*tmp;
	t_tracks	*prev;

	tmp = *tracks;
	while (tmp->next->next != current)
		tmp = tmp->next;
	prev = tmp->next;
	tmp->next = current;
	prev->next = current->next;
	current->next = prev;

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
