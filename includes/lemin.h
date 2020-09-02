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

# define HELP			"use flag -v for visualizer\n"
# define ANTS_NOT_VALID	"Error. Please, enter the number of ants correctly.\n"
# define ROOM_NOT_VALID	"Error. Please, enter rooms carefully\n"
# define LINK_NOT_VALID	"Error. Please, enter links carefully\n"
# define BAD_INPUT		"Error. Bad input.\n"
# define IS_BUSY		1
# define IS_FREE		0
# define START			2
# define END			-1

# define ROOM			"t_room"
# define LEMIN			"t_lemin"
# define DATA			"t_data"
# define EASY_FREE		NULL

/*
**--------------------------------structs---------------------------------------
*/

typedef struct			s_data
{
	char				*content;
	int					counter;
	char				command;
	struct s_data		*next;
	struct s_data		*back;
}						t_data;

typedef struct			s_room
{
	int					x;
	int					y;
	int					state;
	int					weight;
	char				*name;
	int					*links;
}						t_room;

typedef struct			s_lemin
{
	int					visual;
	int					ants;
	int					rooms;
	int					start;
	int					end;
	t_room				*graph;
}						t_lemin;

/*
**-------------------------------functions--------------------------------------
*/

t_lemin					*ft_lemin_init(void);

void					ft_error_n_exit(char *str, t_lemin *lemin, t_data **data);
void					ft_free_data(t_data **data);
void					ft_free_lemin(t_lemin *lemin);
void					ft_free_room(t_room *room);

void					ft_check_flags(t_lemin *lemin, int argc, char *argv[]);
t_lemin					*ft_parse_data(t_lemin *lemin);
int						ft_get_data(t_data **data);
void					ft_parse_ants(t_lemin *lemin, t_data **data);
void					ft_parse_rooms(t_lemin *lemin, t_data **data);
int						ft_check_correct_room(t_data **data);
int						ft_is_link(t_data **data, t_lemin *lemin);
void					ft_create_graph(t_lemin *lemin, t_data **data);
void					ft_parse_links(t_lemin *lemin, t_data **data);

#endif
