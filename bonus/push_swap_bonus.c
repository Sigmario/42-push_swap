/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:29:06 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/29 16:12:30 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_input(char *input, t_stack **a, t_stack **b)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rrr(a, b);
	else
		return (FALSE);
	return (TRUE);
}

static int	get_input(t_stack **a, t_stack **b)
{
	char	*input;

	while (TRUE)
	{
		input = get_next_line(STDIN_FILENO);
		if (!input)
			break;
		if (check_input(input, a, b) == FALSE)
		{
			free(input);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
			return (FALSE);
		}
		free(input);
	}
	return (TRUE);
}

int	main(int arc, char **arv)
{
	t_stack		stack;
	int			size;

	if (arc > 1)
	{
		ft_bzero(&stack, sizeof(t_stack));
		stack.a = get_values(arc - 1, arv);
		stack.b = NULL;
		size = stacksize(stack.a);
		get_pos(&stack.a);
		get_index(&stack.a, size);
		if (sorted(&stack.a) == TRUE)
			return (ft_putstr_fd("OK\n", STDOUT_FILENO), 0);
		else if (get_input(&stack.a, &stack.b) == TRUE)
		{
			if (sorted(&stack.a) == FALSE)
				return (ft_putstr_fd("KO\n", STDOUT_FILENO), 0);
		}
		else
			return (ft_putstr_fd("OK\n", STDOUT_FILENO), 0);
		stackclear(&stack.a);
		stackclear(&stack.b);
	}
	return (0);
}
