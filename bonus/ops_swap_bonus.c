/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:37:22 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/11 16:31:10 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(t_stack **ptr)
{
	int	first;
	int	second;

	if (!*ptr)
		return ;
	first = (*ptr)->value;
	if (!(*ptr)->next)
		return ;
	second = (*ptr)->next->value;
	(*ptr)->value = second;
	(*ptr)->next->value = first;
}

void	sa(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	swap(a);
}

void	sb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
		return ;
	swap(a);
	swap(b);
}
