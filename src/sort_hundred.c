/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/28 21:36:05 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*push_to_a(int pos, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	while (i < pos)
	{
		rb(b);
		i++;
	}
	pa(a, b);
	while (i > 1)
	{
		rrb(b);
		i--;
	}
	return (*b);
}

void	sort_hundred(t_stack **a, t_stack **b)
{
	t_stack		*node;
	t_data		data;

	get_chunks(a, b);
	node = *b;
	while (node)
	{
		data.pos = node->pos;
		data.index = node->index;
		data.size = stacksize(*b);
		data.max_pos = max_value_pos(b);
		if (data.index == data.size)
			node = push_to_a(node->pos, a, b);
		else
			(node) = (node)->next;
	}
}
