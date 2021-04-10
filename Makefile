# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquamar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 10:17:56 by aquamar           #+#    #+#              #
#    Updated: 2021/03/30 10:18:00 by aquamar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS=header.h

SRC := cub.c
OBJ := obj

$(OBJ)/%.o:	$(SRC)/%.c
	$(CC) -I$(SRC) -c $< -o $@
GCC = gcc   -c $(SRC)
all:
	$(GCC) $(SRCS)
clean:
		/bin/rm -f *.o 
fclean:	clean
		rm -f $(NAME)
re:	fclean all
bonus :
