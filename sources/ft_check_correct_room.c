/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_correct_room.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:44:23 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 17:50:41 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_name_is_valid(char *name, t_data *data)
{
	int		counter;
	t_data	*tmp;

	tmp = data;
	counter = data->counter - 1;
	while (counter && tmp != data->back)
	{
		if (ft_strncmp(name, tmp->content, ft_strlen(name)) == FALSE \
			&& tmp->content[ft_strlen(name)] == ' ')
			return (0);
		counter--;
		tmp = tmp->next;
	}
	if (name[0] == 'L' || ft_strchr(name, '-'))
		return (0);
	return (1);
}

static int		ft_coords_are_valid(char *x, char *y)
{
	if (FALSE == ft_str_is_int(x) || FALSE == ft_str_is_int(y))
		return (0);
	if (x[0] < 0 || y[0] < 0)
		return (0);
	return (1);
}

int				ft_check_correct_room(t_data **data)
{
	char	**str;

	str = NULL;
	str = ft_strsplit((*data)->back->content, ' ');
	if (!str)
		return (0);
	if (FALSE == ft_coords_are_valid(str[1], str[2]) \
		|| FALSE == ft_name_is_valid(str[0], *data))
	{
		ft_free_two_dem_str(str);
		return (0);
	}
	ft_free_two_dem_str(str);
	return (1);
}
