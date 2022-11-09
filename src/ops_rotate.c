/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:26:57 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/09 05:57:19 by julmuntz         ###   ########.fr       */
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

void	ra(t_stack **a)
{
	if (!(*a)->next)
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (!(*b)->next)
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if (!(*a)->next || !(*b)->next)
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
