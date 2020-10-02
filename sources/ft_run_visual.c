/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_visual.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:12:43 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 17:48:47 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

FILE *g_visualiser;

/*
** func using system popen() g_visualiser is a 'tread' with running
** a visualiser process.
** this global variable need to close thread after close visualiser!
*/

void		ft_run_visual(t_lemin *lemin)
{
	if (lemin->visual)
	{
		g_visualiser = popen("./main.py", "r");
		pclose(g_visualiser);
	}
}
