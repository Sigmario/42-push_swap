/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:50 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/11 15:26:04 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **ptr)
{
	t_stack	*node;

	if (!*ptr)
		return ;
	node = stacklast(*ptr);
	stackpop_last(ptr);
	stackadd_front(ptr, stacknew(node->value));
}

void	rra(t_stack **a)
{
	rotate(a);
}

void	rrb(t_stack **b)
{
	rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
