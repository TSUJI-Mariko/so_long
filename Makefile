# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 10:53:33 by mtsuji            #+#    #+#              #
#    Updated: 2022/06/06 23:31:16 by mtsuji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	./srcs/so_long.c	\
			./srcs/key_hook.c	\
			./srcs/error_message.c\
			./srcs/actions.c	\
			./srcs/drawing.c	\
			./srcs/render_map.c	\
			./srcs/init_images.c	\
			./bonus/printer_ascii.c	\
			./bonus/action_enemy.c	\

OBJS	=	$(SRCS:.c=.o)

HEADER	=	./includes/

LIB_LINUX = -Lminilibx-linux  -lmlx -lz -lXext -lX11

MLX_LINUX = ./minilibx-linux/

LIBFT	=	./libft/

LIBFT_A	=	./libft/libft.a

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address 

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT) $(LIB) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(LIBFT)
			@make -C $(MLX_LINUX)
			@make -C $(LIBFT)
			ar rcs $(LIBFT_A) $(OBJS)
			ranlib $(LIBFT_A)
			$(CC) $(CFLAGS) $(OBJS) $(LIB_LINUX) $(LIBFT_A) -o $(NAME)

all:	$(NAME)

clean:
		$(MAKE) clean -C $(LIBFT)
		$(MAKE) clean -C $(MLX_LINUX)
		$(RM) $(OBJS)

fclean:	clean
		$(MAKE) fclean -C $(LIBFT)
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

