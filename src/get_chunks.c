/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/28 22:28:03 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*push_to_b(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	if (data->index >= (data->chunk - data->quarter + 1)
		&& data->index <= data->chunk)
	{
		while (i < data->pos)
		{
			ra(a);
			i++;
		}
		pb(a, b);
	}
	return (*a);
}

void	get_chunks(int times, t_stack **a, t_stack **b)
{
	int			i;
	t_stack		*node;
	t_data	data;

	i = 0;
	node = *a;
	data.quarter = stacksize(*a) / times;
	data.chunk = data.quarter;
	while (node)
	{
		if (i == data.chunk)
			data.chunk += data.quarter;
		else if (node->index >= (data.chunk - data.quarter + 1)
			&& node->index <= data.chunk)
		{
			data.value = node->value;
			data.index = node->index;
			data.pos = node->pos;
			node = push_to_b(&data, a, b);
			i++;
		}
		else
			(node) = (node)->next;
	}
}
