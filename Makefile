# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by cmalfroy          #+#    #+#              #
#    Updated: 2018/03/01 11:05:24 by cmalfroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2018/02/09 16:49:06 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= checker
CFLAGS += -Werror -Wextra -Wall
RCFLAGS = -O2 -fomit-frame-pointer
DCFLAGS = -g3 -DDEBUG
SCFLAGS = -fsanitize=address,undefined -ferror-limit=5
CC ?= gcc
MAKE += -j4

INC_PATH = include
SRC_PATH = src
OBJ_DIR ?= obj
OBJ_PATH ?= obj/rel
3TH_PATH =

LIBS =
ifneq (,$(findstring dev,$(NAME)))
LIB_NAME = $(addsuffix .dev, $(LIBS))
else ifneq (,$(findstring san,$(NAME)))
LIB_NAME = $(addsuffix .san, $(LIBS))
else
LIB_NAME = $(LIBS)
endif
LIB_NAME =
3TH_NAME =
SRC_NAME = \
    checker.c \

3TH = $(addprefix $(3TH_PATH)/, $(3TH_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
LNK = $(addprefix -L, $(3TH))
INC = $(addprefix -I, $(INC_PATH) $(addsuffix /include, $(3TH)))
LIB = $(addprefix -l, $(LIB_NAME))
DEP = $(OBJ:%.o=%.d)

all:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th);)
endif
	@+$(MAKE) $(NAME) "CFLAGS = $(RCFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"

dev:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) dev;)
endif
	@+$(MAKE) $(NAME).dev "NAME = $(NAME).dev" "CFLAGS = $(DCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/dev"

san:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) san;)
endif
	@+$(MAKE) $(NAME).san "NAME = $(NAME).san" "CFLAGS = $(SCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/san"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(LNK) $(OBJ) $(LIB) -o $(NAME)
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): exe"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(shell dirname $@)
	@printf "\r%-20s$<\n" "$(NAME):"
	@$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@
	@printf "\033[A\033[2K"

clean:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) clean;)
endif
	@rm -rf $(OBJ_PATH)
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): $@"

fclean:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) fclean;)
endif
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): $@"

re: fclean all

-include $(DEP)

.PHONY: all, dev, san, $(NAME), clean, fclean, re
