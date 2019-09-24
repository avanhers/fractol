# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avanhers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 09:15:22 by avanhers          #+#    #+#              #
#    Updated: 2019/09/24 15:28:11 by avanhers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG),yes)
	$(CFLAGS) += -g -DDEBUG #-fsanitize=address
else
	$(CFLAGS) += -O2 -flto -march=native
endif

NAME = fractol

MLX = mlx/libmlx.a
LIBFT = libft/libft.a
FRAMEWORK = -framework OpenGL -framework APPkit

SRC_NAME =	main.c			\
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

SRC_DIR = src
BUILD_DIR = obj
INC_DIR = include

OBJ = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.o))
DPD = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.d))

opti:
	@$(MAKE) -j all

debug:
	@$(MAKE) opti DEBUG=yes

all:
	@$(MAKE) all -C libft
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@echo "\033[2K \033[A"
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FRAMEWORK) $(MLX)
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(MLX) $(LIBFT)
	@mkdir -p $(BUILD_DIR)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -rf $(BUILD_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(LIBFT)
	@echo "\033[31m[$(LIBFT)]: deleted\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

re : fclean all

.PHONY: all, clean, fclean, re
-include $(DPD)
