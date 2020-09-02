/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:01:41 by cghael            #+#    #+#             */
/*   Updated: 2020/08/26 16:01:42 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_get_index_of_room(char *str, t_lemin *lemin)
{
	int	counter;
	int	index;

	index = 0;
	counter = lemin->rooms;
	while (counter)
	{
		if (ft_strequ(lemin->graph[index].name, str))
			return (index);
		index++;
		counter--;
	}
	return (-1);
}

static int	ft_write_link(char **str, t_lemin *lemin)
{
	int	i;
	int	j;

	i = ft_get_index_of_room(str[0], lemin);
	j = ft_get_index_of_room(str[1], lemin);
	if (i < 0 || j < 0)
		return (FALSE);
	lemin->graph[i].links[j] = 1;
	lemin->graph[j].links[i] = 1;
	return (TRUE);
}

int			ft_is_link(t_data **data, t_lemin *lemin)
{
	char	**str;

	str = NULL;
	if ((*data)->back->content[0] == '#')
		(*data)->back->command = 'c';
	else
	{
		if (ft_word_count((*data)->back->content, '-') != 2)
			return (-1);
		if (!(str = ft_strsplit((*data)->back->content, '-')))
			return (-1);
		if (FALSE == ft_write_link(str, lemin))
		{
			ft_free_two_dem_str(str);
			return (-1);
		}
		ft_free_two_dem_str(str);
	}
	return (1);
}
