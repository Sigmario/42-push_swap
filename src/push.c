/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:59:36 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/09 17:39:22 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pop(t_stack **ptr)
{
	t_stack	*next_node;
	int		result;

	next_node = NULL;
	result = -1;
	if (*ptr == NULL)
		return (-1);
	next_node = (*ptr)->next;
	result = (*ptr)->value;
	free(*ptr);
	*ptr = next_node;
	return (result);
}

static void	push(t_stack **current, t_stack **adjacent)
{
	t_stack	*current_node;
	int		current_top;

	current_node = *current;
	current_top = current_node->value;
	stackadd_front(adjacent, stacknew(current_top));
	pop(current);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}
