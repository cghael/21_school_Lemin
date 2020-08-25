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

NAME = cghael.filler

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIBRARIES = -lftprintf -L$(LIBFTPRINTF_DIR) -lft -L$(LIBFT_DIR)
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFTPRINTF_HEADERS) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./ft_printf/libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

LIBFTPRINTF = $(LIBFTPRINTF_DIR)libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf/
LIBFTPRINTF_HEADERS = $(LIBFTPRINTF_DIR)includes/

HEADERS_LIST = filler.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = sources/
SRC_LIST = main.c \
			ft_parse_player.c \
			ft_parse_plateau_size.c \
			ft_parse_piece_size.c \
			ft_parse_piece.c \
			ft_parse_map.c \
			ft_make_map.c \
			ft_free_filler.c \
			ft_error_msg.c \
			ft_create_map.c \
			ft_count_coords.c \
			ft_check_numbers_or_colon.c

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
