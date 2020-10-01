/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_visual.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:12:43 by cghael            #+#    #+#             */
/*   Updated: 2020/10/01 19:12:44 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_run_visual(t_lemin *lemin)
{
	if (lemin->visual)
	{
		FILE *visualiser;
		visualiser = popen("./main.py", "r");
		pclose(visualiser);
	}
}
