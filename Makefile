# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 14:35:58 by julmuntz          #+#    #+#              #
#    Updated: 2022/07/30 15:09:37 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c				\

OBJS		= 	$(SRCS:.c=.o)

NAME		= 	libftpushswap.a

LIBFT		=	./libft

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror

.c.o :
	$(CC) -c -I $(LIBFT) $< -o $@

$(NAME):		$(OBJS)
					cd $(LIBFT) && $(MAKE)
					cp libft/libft.a $(NAME)
					ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
					$(RM) -r $(OBJS)
					cd $(LIBFT) && $(MAKE) clean

fclean:			clean
					$(RM) $(NAME)
					cd $(LIBFT) && $(MAKE) fclean

re:				fclean all

.PHONY:			all clean fclean re