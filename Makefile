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

Name=my.a
HEADERS=header.h

SRC := cub.c
OBJ := $(SRC:.c=.o)
all:
	$(NAME)
$(NAME):
				gcc -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit ($SRC)
run:
	@ $(FLAGS) $(SRC) -o $(NAME)
	./cub3D 
clean:
		/bin/rm -f *.o 
fclean:	clean
		rm -f $(NAME)
re:	fclean all
bonus :
