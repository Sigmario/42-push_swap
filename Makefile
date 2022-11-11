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
				ops_swap.c		\
				ops_push.c		\
				ops_rotate.c	\
				ops_r_rotate.c	\
				sort_2345.c		\
				sort_beyond.c	\

B_SRCDIR	= 	bonus/
B_SRC		=	push_swap_bonus.c		\
				get_values_bonus.c		\
				get_index_bonus.c		\
				ops_swap_bonus.c		\
				ops_push_bonus.c		\
				ops_rotate_bonus.c		\
				ops_r_rotate_bonus.c	\

OBJDIR		= 	obj/
OBJ			= 	$(addprefix $(OBJDIR), $(SRC:.c=.o))

B_OBJDIR	= 	$(OBJDIR)
B_OBJ		= 	$(addprefix $(B_OBJDIR), $(B_SRC:.c=.o))

NAME		= 	push_swap
B_NAME		= 	checker

LIBFT		=	./libft

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror -g

$(OBJDIR)%.o:	$(SRCDIR)%.c
					@mkdir -p $(OBJDIR)
					$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJDIR)%.o:	$(B_SRCDIR)%.c
					@mkdir -p $(B_OBJDIR)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ) libft/libft.a
					@$(MAKE) --no-print-directory -C $(LIBFT)
					$(CC) -g $^ -o $@

$(B_NAME):		$(B_OBJ) libft/libft.a
					@$(MAKE) --no-print-directory -C $(LIBFT)
					$(CC) -g $^ -o $@

all:			$(NAME) $(B_NAME)

bonus:			$(B_NAME)

libft/libft.a:
					@$(MAKE) --no-print-directory -C $(LIBFT) libft.a

clean:
					$(RM) -r $(OBJDIR)
					@$(RM) -r $(B_OBJDIR)
					$(RM) -r libft/obj/

fclean:			clean
					$(RM) $(NAME)
					$(RM) $(B_NAME)
					$(RM) libft/libft.a

re:				fclean all

.PHONY:			all bonus clean fclean re norminette