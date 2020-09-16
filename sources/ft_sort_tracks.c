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

static void	ft_sort_first_two(t_tracks **tracks)
{
	t_tracks	*current;
	t_tracks	*next;
	t_tracks	*prev;

	prev = *tracks;
	current = (*tracks)->next;
	if (prev->len > current->len)
	{
		if (current->next)
		{
			next = current->next;
			prev->next = next;
			current->next = prev;
			*tracks = current;
		}
		else
		{
			prev->next = current->next;
			current->next = prev;
			*tracks = current;
		}
	}
}

static t_tracks		*ft_swap_to_tracks(t_tracks *current, t_tracks *prev)
{
	t_tracks	*next;

	next = current->next;
	prev->next = next;
	current->next = next->next;
	next->next = current;
	return (next);
}

void		ft_sort_tracks(t_tracks **tracks)
{
	int			flag;
	t_tracks	*current;
	t_tracks	*prev;

	flag = 1;
	if (!(*tracks)->next)
		return ;
	ft_sort_first_two(tracks);
	prev = *tracks;
	current = (*tracks)->next;
	while (flag)
	{
		flag = 0;
		while (current->next)
		{
			if (current->len > current->next->len)
			{
				current = ft_swap_to_tracks(current, prev);
				flag = 1;
			}
			current = current->next;
			prev = prev->next;
		}
	}
}
