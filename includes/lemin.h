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
# define START			2
# define END			-1

/*
**--------------------------------structs---------------------------------------
*/

typedef struct			s_step
{
	int					ant;
	int					room;
	struct s_step		*next;
}						t_step;

typedef struct			s_print
{
	struct s_step		*step;
	struct s_print		*next;
}						t_print;

typedef struct			s_path
{
	int					from;
	int					to;
	int					num;
	struct s_path		*next;
}						t_path;

typedef struct			s_ant
{
	int					room;
	int					ant;
}						t_ant;

typedef struct			s_tracks
{
	t_path				*path;
	t_path				*cross;
	t_ant				*ants;
	int					ant_num;
	int					running_ants;
	int					len;
	int					num;
	struct s_tracks		*next;
}						t_tracks;

typedef struct			s_link
{
	int					lk;
	int					way;
}						t_link;

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
	int					level;
	char				*name;
	t_link				*links;
}						t_room;

typedef struct			s_lemin
{
	int					visual;
	t_print				*print;
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
void					ft_error_n_exit(char *str, t_lemin *lemin, t_data **data, t_tracks *tracks);
void					ft_free_data(t_data **data);
void					ft_free_lemin(t_lemin *lemin);
void					ft_free_room(t_room *room);
void					ft_free_tracks(t_tracks *tracks);

void					ft_check_flags(t_lemin *lemin, int argc, char *argv[]);
t_lemin					*ft_parse_data(t_lemin *lemin);
int						ft_get_data(t_data **data);
void					ft_parse_ants(t_lemin *lemin, t_data **data);
void					ft_parse_rooms(t_lemin *lemin, t_data **data);
int						ft_check_correct_room(t_data **data);
int						ft_is_link(t_data **data, t_lemin *lemin);
void					ft_create_graph(t_lemin *lemin, t_data **data);
void					ft_parse_links(t_lemin *lemin, t_data **data);

void					ft_print_matrix(t_room *graph, int counter, int way);
void					ft_print_path(t_room *graph, t_tracks *tracks);

t_tracks				*ft_create_new_track(t_tracks **tracks);
t_tracks				*ft_find_paths(t_lemin *lemin);
t_tracks				*ft_write_path(t_lemin *lemin, int lvl, t_tracks **tracks);
int						ft_set_levels(t_lemin *lemin, int lvl);
void					ft_change_cross_ways(t_tracks *current, t_tracks *tracks, t_lemin *lemin);
void					ft_run_ants_run(t_lemin *lemin, t_tracks *tracks);
void					ft_sort_tracks(t_tracks **tracks);

int						ft_decision_to_countinue(t_tracks **tracks, int ants);
void					ft_ants_choose_ways(t_lemin *lemin, t_tracks *tracks);
void					ft_ants_mooving(t_lemin *lemin, t_tracks *tracks);

#endif
