/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:26:57 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/11 16:31:11 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_stack **ptr)
{
	int	value;

	value = (*ptr)->value;
	stackpop(ptr);
	stackadd_back(ptr, stacknew(value));
}

void	ra(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	rotate(a);
}

void	rb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
		return ;
	rotate(a);
	rotate(b);
}
