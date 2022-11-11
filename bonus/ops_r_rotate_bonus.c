/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:50 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/11 16:31:14 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_stack **ptr)
{
	t_stack	*last;

	last = stacklast(*ptr);
	stackpop_last(ptr);
	stackadd_front(ptr, last);
}

void	rra(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	rotate(a);
}

void	rrb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
		return ;
	rotate(a);
	rotate(b);
}
