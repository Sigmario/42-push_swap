/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:50 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/14 18:05:44 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **ptr)
{
	t_stack	*node;
	int		index;
	int		last;

	if (!*ptr)
		return ;
	node = *ptr;
	index = stacklast(node)->index;
	last = stacklast(node)->value;
	stackpop_last(&node);
	stackadd_front(ptr, stacknew(last));
	(*ptr)->index = index;
}

void	rra(t_stack **a)
{
	rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rrr\n");
}
