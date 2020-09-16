/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_track.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:08:09 by cghael            #+#    #+#             */
/*   Updated: 2020/09/14 12:08:11 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_tracks		*ft_create_tracks(void)
{
	t_tracks	*tmp;

	tmp = NULL;
	if ((tmp = ft_memalloc(sizeof(t_tracks))) == NULL)
		return (NULL);
	tmp->next = NULL;
	tmp->path = NULL;
	tmp->cross = NULL;
	tmp->ants = NULL;
	return (tmp);
}

t_tracks		*ft_create_new_track(t_tracks **tracks)
{
	t_tracks	*current;
	t_tracks	*tmp;
	int			counter;

	counter = 1;
	if ((current = ft_create_tracks()) == NULL)
		return (NULL);
	if (*tracks == NULL)
		*tracks = current;
	else
	{
		counter++;
		tmp = *tracks;
		while (tmp->next)
		{
			tmp = tmp->next;
			counter++;
		}
		tmp->next = current;
	}
	current->num = counter;
	return (current);
}
