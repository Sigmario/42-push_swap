/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/30 14:29:03 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*sort_to_a(int pos, t_stack **a, t_stack **b)
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

static t_stack	*sort_to_b(t_data *data, t_stack **a, t_stack **b)
{
	int	a_start;
	int	b_start;

	a_start = 1;
	b_start = 1;
	if (data->index >= (data->chunk - data->quarter + 1)
		&& data->index <= data->chunk)
	{
		while (a_start < data->pos)
		{
			ra(a);
			a_start++;
		}
		while (b_start < a_start)
		{
			rb(b);
			b_start++;
		}
		pb(a, b);
		while (b_start > 1)
		{
			rrb(b);
			b_start--;
		}
	}
	return (*a);
}

static void	get_chunks(int times, t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*node;
	t_data	data;

	i = 0;
	node = *a;
	data.quarter = stacksize(*a) / times;
	data.chunk = data.quarter;
	while (node)
	{
		data.pos = node->pos;
		data.index = node->index;
		data.max_pos = get_max_pos(b);
		if (i == data.chunk)
			data.chunk += data.quarter;
		else if (node->index >= (data.chunk - data.quarter + 1)
			&& node->index <= data.chunk)
		{
			node = sort_to_b(&data, a, b);
			i++;
		}
		else
			(node) = (node)->next;
	}
}

void	sort_beyond(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*node;
	t_data	data;

	size = stacksize(*a);
	if (size <= 100)
		get_chunks(5, a, b);
	if (size > 100)
		get_chunks(11, a, b);
	node = *b;
	while (node)
	{
		data.index = node->index;
		data.size = stacksize(*b);
		data.max_pos = get_max_pos(b);
		if (data.index == data.size)
			node = sort_to_a(node->pos, a, b);
		else
			(node) = (node)->next;
	}
}
