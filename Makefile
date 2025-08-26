# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 03:29:05 by iokuno            #+#    #+#              #
#    Updated: 2025/08/26 21:12:39 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := split_shell.a

CC       := cc
CFLAGS   := -Wall -Wextra -Werror -Iinc -MMD -MP

AR       := ar rcs
RM       := rm -rf

INC_DIR  := inc
SRC_DIR  := src
OBJ_DIR  := obj

SRCS     := $(SRC_DIR)/split_shell.c \
		$(SRC_DIR)/all_free.c \
		$(SRC_DIR)/balanced_quotes.c \
		$(SRC_DIR)/is_delim_top.c \
		$(SRC_DIR)/is_visible.c \
		$(SRC_DIR)/read_token.c \
		$(SRC_DIR)/skip_set.c \
		$(SRC_DIR)/t_buf.c \
		$(SRC_DIR)/t_vec.c \
		$(SRC_DIR)/update_state.c

OBJS     := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS     := $(OBJS:.o=.d)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re