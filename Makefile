# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 14:35:58 by julmuntz          #+#    #+#              #
#    Updated: 2022/09/21 13:51:12 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c		\
				errors.c		\
				ops.c			\

OBJDIR		= 	obj/

OBJS		= 	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

NAME		= 	push_swap

LIBFT		=	./libft

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror 

$(OBJDIR)%.o:	%.c
					@mkdir -p $(OBJDIR)
					$(CC) -c -I $(LIBFT) $< -o $@
					$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):		$(OBJS)
					cd $(LIBFT) && $(MAKE)
					$(CC) $(OBJS) libft/libft.a -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

all:			$(NAME)

clean:
					$(RM) -r $(OBJDIR)
					cd $(LIBFT) && $(MAKE) clean

fclean:			clean
					$(RM) $(NAME)
					cd $(LIBFT) && $(MAKE) fclean

re:				fclean all

norminette :
				@norminette libft
				@norminette *.c
				@norminette *.h	

.PHONY:			all clean fclean re norminette