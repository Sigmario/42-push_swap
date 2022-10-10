/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:50 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/10 17:40:58 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **ptr)
{
	t_stack	*node;
	int		last;

	if (!*ptr)
		return ;
	node = stacklast(*ptr);
	last = node->value;
	stackadd_front(ptr, stacknew(last));
	while ((*ptr)->next != NULL)
	{
		if ((*ptr)->next == NULL)
			stackpop(ptr);
		(*ptr) = (*ptr)->next;
	}
}

void	rra(t_stack **a)
{
	rotate(a);
}

void	rrb(t_stack **b)
{
	rotate(b);
}
