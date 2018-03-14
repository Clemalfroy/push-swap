# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2018/02/20 12:04:56 by mc               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = checker

NAME2 = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIB = libft

LDFLAGS = -Llibft

LDLIBS = -lft

SRC_PATH = src

SRC_NAME = \
    checker.c dlist.c dlst2.c getlist.c pushs.c rotate.c rrotate.c swaps.c \
    algo.c actions.c \

SRC_NAME2 = \
    pushswap.c dlist.c dlst2.c getlist.c pushs.c rotate.c rrotate.c swaps.c \
    sorting.c

AR = ar rc

INC_LIB = -I libft/include

CPPFLAGS = -I include

OBJ_PATH = obj

OBJ_PATH2 = obj2

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_NAME2 = $(SRC_NAME2:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC2 = $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@echo "Executable "$(NAME)" made"

$(NAME2): $(OBJ2)
	@make -C $(LIB)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@echo "Executable "$(NAME2)" made"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<

$(OBJ_PATH2)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH2) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<

clean:
	@make fclean -C $(LIB)
	@rm -f $(OBJ) $(OBJ2)
	@rm -rf $(OBJ_PATH) || true
	@rm -rf $(OBJ_PATH2) || true
	@echo $(OBJ_PATH)" et "$(OBJ_PATH2)" supprimé !"

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@echo "Executable de "$(NAME)" et "$(NAME2)" supprimé !"

re: fclean all
	@echo "Make re done !"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)