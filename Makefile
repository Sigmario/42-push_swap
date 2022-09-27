# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 14:35:58 by julmuntz          #+#    #+#              #
#    Updated: 2022/09/27 11:26:34 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR		= 	src/
SRC			=	push_swap.c		\
				errors.c		\
				ops.c			\
				array_to_list.c	\

OBJDIR		= 	obj/
OBJ			= 	$(addprefix $(OBJDIR), $(SRC:.c=.o))

NAME		= 	push_swap

LIBFT		=	./libft

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror 

$(NAME):		$(OBJ) libft/libft.a
					@$(MAKE) --no-print-directory -C $(LIBFT)
					@$(CC) $^ -o $@

$(OBJDIR)%.o:	$(SRCDIR)%.c
					@mkdir -p $(OBJDIR)
					$(CC) $(CFLAGS)-c $< -o $@

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

norminette :
				@norminette libft/*.c
				@norminette libft/*.h
				@norminette src/*.c
				@norminette src/*.h	

.PHONY:			all clean fclean re norminette