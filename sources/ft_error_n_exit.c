/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_n_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:16:06 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:16:08 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
/*
static void	ft_free_type(void *mem, char *type) //todo
{
	if (ft_strequ(type, ROOM))
		ft_free_room();
	if (ft_strequ(type, LEMIN))
		fr_free_lemin();
}
*/
void		ft_error_n_exit(char *str, void *mem, char *type)
{
	write(2, str, ft_strlen(str));
	if (mem)
	{
//		if (ft_strequ(type, ROOM) || ft_strequ(type, LEMIN))
//			ft_free_type(mem, type);
//		else
			free(mem);
	}
	exit(1);
}
