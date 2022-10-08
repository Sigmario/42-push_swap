/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:59:36 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/08 23:58:44 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **current, t_stack **adjacent)
{
	t_stack *current_node;
	int current_top;

	current_node = *current;
	current_top = current_node->value;
	stackadd_front(adjacent, stacknew(current_top));
	current_node = current_node->next;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}
