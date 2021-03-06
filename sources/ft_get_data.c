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

int				ft_get_data(t_data **data, int fd)
{
	t_data	*tmp;
	int		res;

	tmp = (t_data*)ft_memalloc(sizeof(t_data));
	if (!tmp)
		return (0);
	tmp->content = NULL;
	tmp->next = NULL;
	tmp->back = NULL;
	if ((res = ft_get_next_line(fd, &(tmp->content))) < 1)
	{
		free(tmp->content);
		free(tmp);
		return (res);
	}
	ft_add_tmp_to_data(tmp, data);
	return (res);
}
