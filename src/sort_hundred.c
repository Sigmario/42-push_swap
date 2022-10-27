/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/27 11:57:51 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	next_chunk(int count, int chunk, int quarter)
{
	int	next;

	next = chunk;
	next += quarter;
	if (count == 4)
		return (0);
	if (count < 4)
	{
		count++;
		chunk += quarter;
	}
	return (next);
}

static void	save1(t_data *data, int chunk, int quarter)
{
			data->chunk = chunk;
			data->quarter = quarter;
}

static void	save2(t_data *data, int index, int pos)
{
			data->index = index;
			data->pos = pos;
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

int	sort_hundred(t_stack **a, t_stack **b)
{
	int		i;
	t_data	data;
	int		chunk;
	t_stack	*node;
	int		quarter;

	i = 0;
	data.count = 0;
	node = *a;
	quarter = stacksize(*a) / 4;
	chunk = quarter;
	while (node)
	{
		if (i == chunk)
			chunk = next_chunk(data.count, chunk, quarter);
		if (node->index >= (chunk - quarter + 1) && node->index <= chunk)
		{
			save1(&data, chunk, quarter);
			save2(&data, node->index, node->pos);
			node = top(&data, a, b);
			++i;
		}
		else
			(node) = (node)->next;
	}
	return (0);
}
