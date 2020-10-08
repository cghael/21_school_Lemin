/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:34:46 by cghael            #+#    #+#             */
/*   Updated: 2020/10/06 18:45:14 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_parse_links(t_lemin *lemin, t_data **data)
{
	int		res;

	while (ft_is_link(data, lemin) == 1 && res)
	{
		if ((res = ft_get_data(data, lemin->fd_map)) == -1)
			ft_error_n_exit("Error in ft_parse_links()\n", lemin, data, NULL);
		else if (res == 0)
			return ;
	}
	ft_error_n_exit(LINK_NOT_VALID, lemin, data, NULL);
}
