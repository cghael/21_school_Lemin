# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghael <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 12:00:54 by cghael            #+#    #+#              #
#    Updated: 2020/07/24 12:00:57 by cghael           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIBRARIES = -lftprintf -L$(LIBFTPRINTF_DIR) -lft -L$(LIBFT_DIR)
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFTPRINTF_HEADERS) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./21_school_ft_printf/libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

LIBFTPRINTF = $(LIBFTPRINTF_DIR)libftprintf.a
LIBFTPRINTF_DIR = ./21_school_ft_printf/
LIBFTPRINTF_HEADERS = $(LIBFTPRINTF_DIR)includes/

HEADERS_LIST = lemin.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = sources/
SRC_LIST =	main.c \
			ft_add_tmp_to_data.c \
			ft_lemin_init.c \
			ft_error_n_exit.c \
			ft_check_flags.c \
			ft_parse_data.c \
			ft_parse_ants.c \
			ft_get_data.c \
			ft_free_data.c \
			ft_parse_rooms.c \
			ft_get_last_data_node.c \
			ft_check_correct_room.c \
			ft_is_link.c \
			ft_create_graph.c \
			ft_parse_links.c \
			ft_free_lemin.c \
			ft_find_paths.c \
			ft_set_levels.c \
			ft_free_tracks.c \
			ft_write_path.c \
			ft_create_new_track.c \
			ft_change_cross_ways.c \
			ft_run_ants_run.c \
			ft_sort_tracks.c \
			ft_decision_to_countinue.c \
			ft_ants_choose_ways.c \
			ft_ants_mooving.c \
			ft_print_steps.c \
			ft_write_usage_n_exit.c \
			ft_create_n_open_file.c \
			ft_you_were_warned.c \
			ft_run_visual.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "\n$(NAME): $(GRN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GRN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GRN)$(OBJ_DIR) created$(END)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(LIBFTPRINTF):
	@echo "$(NAME_PS): $(GRN)Creating $(LIBFTPRINTF)...$(END)"
	@$(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBFTPRINTF_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) deleted$(END)"
	@echo "$(NAME): $(RED)*.o files deleted$(END)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBFTPRINTF_DIR) fclean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) deleted$(END)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
