/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:11:29 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 12:11:31 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

/*
**--------------------------------headers---------------------------------------
*/

# include "ft_printf.h"
# include "ft_get_next_line.h"

/*
**--------------------------------defines---------------------------------------
*/

# define HELP		"use flag -v for visualizer\n"
# define IS_BUSY	1
# define IS_FREE	0

# define ROOM		"t_room"
# define LEMIN		"t_lemin"
# define EASY_FREE	NULL

/*
**--------------------------------structs---------------------------------------
*/

typedef struct		s_room
{
	int				x;
	int				y;
	int				state;
	int				weight;
	int				*links;
}					t_room;

typedef struct		s_lemin
{
	int				visual;
	int				ants;
	int				start;
	int				end;
	t_room			*graph;
}					t_lemin;

/*
**-------------------------------functions--------------------------------------
*/

t_lemin				*ft_lemin_init(void);
void				ft_error_n_exit(char *str, void *mem, char *type);
void				ft_check_flags(t_lemin *lemin, int argc, char *argv[]);
t_lemin				*ft_parse_data(t_lemin *lemin);

#endif
