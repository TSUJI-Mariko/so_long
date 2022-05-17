# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 10:53:33 by mtsuji            #+#    #+#              #
#    Updated: 2022/05/17 16:21:23 by mtsuji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	main.c	\
			create_trgb.c	\

OBJS	=	$(SRCS:.c=.o)

HEADER	=	./includes/

LIB_LINUX = -Lmlx_linux -lmlx -lz -lXext -lbsd -lX11

MLX_LINUX = ./mlx_linux/

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

