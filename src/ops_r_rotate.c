/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:50 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/19 20:38:12 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **ptr)
{
	int	index;
	int	last;

	if (!*ptr && !(*ptr)->next)
		return ;
	index = stacklast(*ptr)->index;
	last = stacklast(*ptr)->value;
	stackpop_last(ptr);
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
