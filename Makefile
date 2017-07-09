# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qviguier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 11:53:38 by qviguier          #+#    #+#              #
#    Updated: 2016/01/12 11:59:58 by ddevico          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all

SRC_PATH = src
SRC_NAME = 	lem_in.c get_next_line.c ft_readmap.c ft_utils.c ft_managestruct.c ft_algo.c

INC_PATH = include
INC_NAME = 	lem_in.h get_next_line.h ft_printf.h libft.h

OBJ_PATH = objects

CPPFLAGS = -Iinclude

LIB_PATH = libraries
LIB_NAME = libftprintf.a

NAME = lem-in

CC = clang

CFLAGS = -Werror -Wall -Wextra -g

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: $(NAME) norminette1 norminette2

$(NAME): $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))
	@echo LINKING FILLER FROM OBJECTS FILES...
	@$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LIB)
	@echo SUCCESS !

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo COMPILING $(@)...
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $? -o $(@) -c

clean:
	@rm -f $(OBJ)
	@echo OBJECTS FILES DELETION COMPLETE !
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo EXECUTABLE DELETED !

re: fclean all

norminette1:
	@echo --------------------------------------------------------------------
	@norminette $(SRC)
norminette2:
	@echo --------------------------------------------------------------------
	@norminette $(INC)
	@echo --------------------------------------------------------------------