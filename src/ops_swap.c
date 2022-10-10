/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:37:22 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/10 17:41:30 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **ptr)
{
	t_stack	*node;
	int		first;
	int		second;

	if (!*ptr)
		return ;
	node = *ptr;
	first = node->value;
	if (!node->next)
		return ;
	second = node->next->value;
	node->value = second;
	node->next->value = first;
}

void	sa(t_stack **a)
{
	swap(a);
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
