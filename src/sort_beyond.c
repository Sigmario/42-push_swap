/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/30 21:04:39 by julmuntz         ###   ########.fr       */
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

	a_start = 0;
	b_start = 0;
	if (data->index >= (data->chunk - data->quarter + 1)
		&& data->index <= data->chunk)
	{
		while (++a_start < data->pos)
			ra(a);
		while (++b_start < data->pos)
			rb(b);
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
		data.max_index = get_max_index(b);
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

static void	*max1_or_max2(t_stack *node, t_data *data,
	t_stack **a, t_stack **b)
{
	if (data->sa_needed == FALSE && data->index == data->max_index)
		node = sort_to_a(node->pos, a, b);
	else if (data->sa_needed == TBD && data->index == data->sec_max_index)
	{
		node = sort_to_a(node->pos, a, b);
		data->sa_needed = TRUE;
	}
	else if (data->sa_needed == TRUE && data->index == data->max_index)
	{
		node = sort_to_a(node->pos, a, b);
		sa(a);
		data->sa_needed = FALSE;
	}
	else if (data->sa_needed == FALSE && data->index == data->sec_max_index)
	{
		node = sort_to_a(node->pos, a, b);
		data->sa_needed = TRUE;
	}
	else
		node = (node)->next;
	return (node);
}

void	sort_beyond(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*node;
	t_data	data;

	data.sa_needed = TBD;
	size = stacksize(*a);
	if (size > 5 && size < 100)
		get_chunks(2, a, b);
	else if (size >= 100 && size < 500)
		get_chunks(7.5, a, b);
	else if (size >= 500)
		get_chunks(11.5, a, b);
	node = *b;
	while (node)
	{
		data.index = node->index;
		data.size = stacksize(*b);
		data.max_index = get_max_index(b);
		data.sec_max_index = get_2ndmax_index(b);
		node = max1_or_max2(node, &data, a, b);
	}
}
