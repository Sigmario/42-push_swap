# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 14:35:58 by julmuntz          #+#    #+#              #
#    Updated: 2022/09/29 15:06:44 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR		= 	src/
SRC			=	push_swap.c		\
				get_values.c	\
				get_index.c		\

OBJDIR		= 	obj/
OBJ			= 	$(addprefix $(OBJDIR), $(SRC:.c=.o))

NAME		= 	push_swap

LIBFT		=	./libft

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror -g

$(NAME):		$(OBJ) libft/libft.a
					@$(MAKE) --no-print-directory -C $(LIBFT)
					@$(CC) $^ -o $@

$(OBJDIR)%.o:	$(SRCDIR)%.c
					@mkdir -p $(OBJDIR)
					$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

libft/libft.a:
					@$(MAKE) --no-print-directory -C $(LIBFT) libft.a

clean:
					$(RM) -r $(OBJDIR)
					$(RM) -r libft/obj/

fclean:			clean
					$(RM) $(NAME)
					$(RM) libft/libft.a

re:				fclean all

.PHONY:			all clean fclean re norminette