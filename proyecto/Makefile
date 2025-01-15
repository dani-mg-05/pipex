# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damedina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 18:31:59 by damedina          #+#    #+#              #
#    Updated: 2024/07/24 23:45:03 by damedina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
BONUS_MARKER = .bonus_done

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = src
OBJ_DIR = obj

BONUS_SRC_DIR = bonus
BONUS_OBJ_DIR = bonus_obj

SRC =	$(SRC_DIR)/pipex.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/split_modified.c

BONUS_SRC =	$(BONUS_SRC_DIR)/pipex_bonus.c \
			$(BONUS_SRC_DIR)/utils_bonus.c \
			$(BONUS_SRC_DIR)/split_modified_bonus.c \
			$(BONUS_SRC_DIR)/free_malloc_bonus.c \
			$(BONUS_SRC_DIR)/get_next_line_bonus.c \
			$(BONUS_SRC_DIR)/child_processes_bonus.c \
			$(BONUS_SRC_DIR)/get_vars_bonus.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS_MARKER)

$(BONUS_MARKER): $(BONUS_NAME)
	@cp $(BONUS_NAME) $(NAME)
	@touch $(BONUS_MARKER)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(BONUS_OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(RM) $(BONUS_MARKER)
	make fclean -C $(LIBFT_DIR)

re: fclean	all

.PHONY: all clean fclean re bonus
