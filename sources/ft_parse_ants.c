/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:57:17 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:57:19 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_data	*ft_get_last_line(t_data *data)
{
	t_data *tmp;

	tmp = data;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void		ft_parse_ants(t_lemin *lemin, t_data **data)
{
	t_data	*last;

	while (lemin->ants == 0)
	{
		if (ft_get_data(data))
		{
			ft_free_data(*data);
			ft_error_n_exit("Error in ft_parse_ants()\n", lemin, LEMIN);
		}
		last = ft_get_last_line(*data);
		if (!ft_str_is_int(last->content) && last->content[0] != '#')
		{
			ft_free_data(*data);
			ft_error_n_exit(BAD_INPUT, lemin, LEMIN);
		}
		else if (last->content[0] != '#')
		{
			lemin->ants = ft_atoi(last->content);
			if (lemin->ants < 1)
			{
				ft_free_data(*data);
				ft_error_n_exit(ANTS_NOT_VALID, lemin, LEMIN);
			}
		}
	}
}
