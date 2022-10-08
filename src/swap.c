/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:37:22 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/08 18:58:16 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *node)
{
	int	first;
	int	second;

	if (!node)
		return ;
	first = node->value;
	if (!node->next)
		return ;
	second = node->next->value;
	node->value = second;
	node->next->value = first;
}

void	sa(t_stack **a)
{
	t_stack	*node;

	node = *a;
	swap(node);
}

void	sb(t_stack **b)
{
	t_stack	*node;

	node = *b;
	swap(node);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
