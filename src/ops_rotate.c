/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:26:57 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/28 11:52:18 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **ptr)
{
	t_stack	*first;

	first = (*ptr);
	stackpop(ptr);
	stackadd_back(ptr, stacknew(first->value));
}

void	ra(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
