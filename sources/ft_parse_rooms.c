/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:24:58 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 16:25:01 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_is_room(t_data *last)
{

}

void			ft_parse_rooms(t_lemin *lemin, t_data **data)
{
	t_data	*last;
	int		res;

	if (!ft_get_data(data))
	{
		ft_free_data(*data);
		ft_error_n_exit("Error in ft_parse_rooms()\n", lemin, LEMIN);
	}
	last = ft_get_last_data_node(*data);
	while ((res = ft_is_room(last)) == 1)
	{
		if (!ft_get_data(data))
		{
			ft_free_data(*data);
			ft_error_n_exit("Error in ft_parse_rooms()\n", lemin, LEMIN);
		}
		last = ft_get_last_data_node(*data);
	}
	if (res == 0) //rooms are ends
		return ;
	else // (-1) bad input
		//todo free n exit
}
