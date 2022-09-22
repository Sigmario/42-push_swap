# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 14:35:58 by julmuntz          #+#    #+#              #
#    Updated: 2022/09/22 15:24:26 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	src/push_swap.c		\
				src/errors.c		\
				src/ops.c			\

OBJDIR		= 	obj/

OBJ			= 	$(addprefix $(OBJDIR), $(SRC:.c=.o))

NAME		= 	push_swap

LIBFT		=	./libft

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror 

$(OBJDIR)%.o:	%.c
					@mkdir -p $(OBJDIR)
					@mkdir -p $(OBJDIR)/src/
					$(CC) -c -I $(LIBFT) $< -o $@
					$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):		$(OBJ)
					cd $(LIBFT) && $(MAKE)
					$(CC) $(OBJ) libft/libft.a -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

all:			$(NAME)

clean:
					$(RM) -r $(OBJDIR)
					cd $(LIBFT) && $(MAKE) clean

fclean:			clean
					$(RM) $(NAME)
					cd $(LIBFT) && $(MAKE) fclean

re:				fclean all

norminette :
				@norminette libft/*.c
				@norminette libft/*.h
				@norminette src/*.c
				@norminette src/*.h	

.PHONY:			all clean fclean re norminette