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

static int		ft_is_command_or_comment(t_data **data, t_lemin *lemin)
{
	if ((*data)->back->content[1] != '#')
		(*data)->back->command = 'c';
	else
	{
		if (ft_strequ((*data)->back->content, "##start"))
		{
			(*data)->back->command = 's';
			if (lemin->start == 0)
				lemin->start = 1;
			else
				return (-1);
		}
		else if (ft_strequ((*data)->back->content, "##end"))
		{
			(*data)->back->command = 'e';
			if (lemin->end == 0)
				lemin->end = 1;
			else
				return (-1);
		}
	}
	return (1);
}

/*
** RETURN	1	if last->content room or command or comment
**			0	if lat->content is link
**			-1	if last->content is bad input or room name is exist yet or room
**				name starts with 'L' or empty line
*/

static int		ft_is_room(t_data **data, t_lemin *lemin)
{
	if ((*data)->back->content[0] == '#')
		return (ft_is_command_or_comment(data, lemin));
	else
	{
		if (ft_word_count((*data)->back->content, ' ') != 3)
		{
			if (ft_word_count((*data)->back->content, '-') == 2)
				return (0);
			else
				return (-1);
		}
		if (ft_check_correct_room(data))
			lemin->rooms++;
		else
			return (-1);
		return (1);
	}
}

void			ft_parse_rooms(t_lemin *lemin, t_data **data)
{
	int		res;

	if (!ft_get_data(data))
		ft_error_n_exit("Error in ft_parse_rooms()\n", lemin, data, NULL);
	while ((res = ft_is_room(data, lemin)) == 1)
	{
		if (ft_get_data(data) < 1)
			ft_error_n_exit("Error in ft_parse_rooms()\n", lemin, data, NULL);
	}
	if (res == 0)
	{
		if (lemin->rooms < 1 || lemin->start == 0 || lemin->end == 0)
			ft_error_n_exit(ROOM_NOT_VALID, lemin, data, NULL);
	}
	else if (res == -1)
		ft_error_n_exit(ROOM_NOT_VALID, lemin, data, NULL);
}
