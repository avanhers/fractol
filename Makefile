# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avanhers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 09:15:22 by avanhers          #+#    #+#              #
#    Updated: 2019/05/10 18:00:55 by avanhers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

SRCS=	main.c			\
     	julia.c			\
 		event.c			\
		thread.c		\
		set_up.c		\
		set_up2.c		\
		mandelbrot.c	\
		draw.c			\
		color.c			\
		choose.c		\
		burning_ship.c	\
		celtic_mandelbrot.c \
		phoenix.c		\
		tricorn.c		\
		queen.c			\
		cross.c			\
		mouse_event.c	\
		key_event.c

OBJS= $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC= gcc

all : $(NAME)

$(NAME) : $(OBJS)
	make -sC libft
	$(CC)  -o $(NAME) $(SRCS)  libft/libft.a \
	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

$(OBJS) : $(SRCS)
	$(CC) -c $(FLAGS) $(SRCS) -I /usr/local/include/ 

clean :
	make -sC libft clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
