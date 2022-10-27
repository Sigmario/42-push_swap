/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:50 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/27 10:57:44 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **ptr)
{
	int	last;

	if (!*ptr)
		return ;
	last = stacklast(*ptr)->value;
	stackpop_last(ptr);
	stackadd_front(ptr, stacknew(last));
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
