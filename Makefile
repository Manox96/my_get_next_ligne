# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 16:37:13 by aennaqad          #+#    #+#              #
#    Updated: 2023/12/06 23:00:23 by aennaqad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = get_next_ligne.c 
OBJ = $(SRC:.c = .o)
NAME = get_next_ligne.a
AR = ar -rcs
RM = rm -rf

%.o : %.c get_next_ligne.h
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: all fclean

.PHONY : all clean fclean re
