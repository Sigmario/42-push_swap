/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/27 22:02:19 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	next_chunk(t_data *data)
{
	if (data->count < 2)
	{
		if (data->count == 2)
			return (0);
		else
		{
			data->count++;
			return (data->chunk += data->quarter);
		}
	}
	return (0);
}

static t_stack	*top(t_data *data, t_stack **a, t_stack **b)
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

void	get_chunks(t_stack **a, t_stack **b)
{
	int		i;
	t_data	data;
	t_stack	*node;

	i = 0;
	data.count = 0;
	node = *a;
	data.quarter = stacksize(*a) / 4;
	data.chunk = data.quarter;
	while (node)
	{
		if (i == data.chunk)
			data.chunk = next_chunk(&data);
		else if (node->index >= (data.chunk - data.quarter + 1)
			&& node->index <= data.chunk)
		{
			data.value = node->value;
			data.index = node->index;
			data.pos = node->pos;
			node = top(&data, a, b);
			i++;
		}
		else
			(node) = (node)->next;
	}
}
