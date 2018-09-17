# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 17:15:14 by asamir-k          #+#    #+#              #
#    Updated: 2018/09/17 17:09:45 by asamir-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
GCC= GCC
HEADER= fdf.h
FLAGS = -Wall -Werror -Wextra
LIB_PATH= INCLUDES/libft/
AR:= ar rc
RL= ranlib
COMP= /usr/local/include
MLXLIB= -lmlx -framework Opengl -framework Appkit
SRC=SRCS/main.c \
	SRCS/linedrawer.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c $(HEADER)
	Make -C INCLUDES/libft
	@gcc $(FLAGS) -o $@ -c $< -I $(LIB_PATH)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft $(MLXLIB) -I $(COMP)
	@echo "\033[32;1;4mYoyoyoyoyoyoyo\033[0m]"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all