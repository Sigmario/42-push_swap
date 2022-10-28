/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/28 12:42:10 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*push_to_a(t_data_b *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	if (data->index == data->size)
	{
		while (i < data->size)
		{
			rb(b);
			i++;
		}
		pa(a, b);
	}
	data->size = stacksize(*b);
	return (*b);
}

void	sort_hundred(t_stack **a, t_stack **b)
{
	int			i;
	t_stack		*node;
	t_data_b	data;

	get_chunks(a, b);
	i = 0;
	node = *b;
	while (node)
	{
		data.size = max_value_pos(b);
		if (node->index == data.size)
		{
			data.value = node->value;
			data.index = node->index;
			data.pos = node->pos;
			node = push_to_a(&data, a, b);
			i++;
		}
		else
			(node) = (node)->next;
	}
}
