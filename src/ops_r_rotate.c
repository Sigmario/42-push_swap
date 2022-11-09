/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:50 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/09 05:57:38 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **ptr)
{
	int	value;

	value = (*ptr)->value;
	stackpop(ptr);
	stackadd_back(ptr, stacknew(value));
}

void	rra(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rrr\n");
}
