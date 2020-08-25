/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_data_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:26:54 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 16:26:55 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_data	*ft_get_last_data_node(t_data *data)
{
	t_data *tmp;

	tmp = data;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
