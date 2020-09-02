/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:49:21 by cghael            #+#    #+#             */
/*   Updated: 2020/09/02 15:49:23 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_free_room(t_room *room)
{
	if (room)
	{
		if (room->name)
			free(room->name);
		if (room->links)
			free(room->links);
		free(room);
	}
}
