/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:59:13 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:59:14 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_add_tmp_to_data(t_data *tmp, t_data **data)
{
	t_data *begin;

	begin = *data;
	if (begin == NULL)
		*data = tmp;
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = tmp;
	}
}

int				ft_get_data(t_data **data)
{
	t_data	*tmp;

	tmp = (t_data*)ft_memalloc(sizeof(t_data));
	if (!tmp)
		return (1);
	if (ft_get_next_line(0, &(tmp->content)) != 1)
		return (1);
	ft_add_tmp_to_data(tmp, data);
	return (0);
}
