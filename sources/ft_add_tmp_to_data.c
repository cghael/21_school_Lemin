/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tmp_to_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:34:26 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 16:34:28 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_add_tmp_to_data(t_data *tmp, t_data **data)
{
	t_data *begin;

	begin = *data;
	if (begin == NULL)
	{
		tmp->next = tmp;
		tmp->back = tmp;
		*data = tmp;
	}
	else
	{
		(*data)->back->next = tmp;
		tmp->back = (*data)->back;
		(*data)->back = tmp;
		tmp->next = *data;
	}
	(*data)->counter++;
}
