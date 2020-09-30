/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lemin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:45:41 by cghael            #+#    #+#             */
/*   Updated: 2020/09/02 15:45:43 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_free_print(t_print *print)
{
	t_print	*tmp_pr;
	t_step	*tmp_st;
	void	*del;

	tmp_pr = print;
	while (tmp_pr)
	{
		tmp_st = tmp_pr->step;
		while (tmp_st)
		{
			del = tmp_st;
			tmp_st = tmp_st->next;
			free(del);
		}
		del = tmp_pr;
		tmp_pr = tmp_pr->next;
		free(del);
	}
}

void		ft_free_lemin(t_lemin *lemin)
{
	int i;

	i = 0;
	if (lemin)
	{
		if (lemin->graph)
		{
			while (i < lemin->rooms)
			{
				if (lemin->graph[i].name)
					free(lemin->graph[i].name);
				if (lemin->graph[i].links)
					free(lemin->graph[i].links);
				i++;
			}
			free(lemin->graph);
		}
		if (lemin->print)
			ft_free_print(lemin->print);
		free(lemin);
	}
}
