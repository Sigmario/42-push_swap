/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2024/05/18 16:15:46 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*sort_to_a(t_data *data, t_stack **a, t_stack **b)
{
	int	pos;

	pos = rb_or_rrb(data, b);
	if (data->r_needed == TRUE && data->rr_needed == FALSE)
	{
		while (pos-- > 1)
			rb(b);
	}
	else if (data->rr_needed == TRUE && data->r_needed == FALSE)
	{
		while (pos-- > 1)
			rrb(b);
	}
	pa(a, b);
	return (*b);
}

static void	update_count_chunk(int is_second, t_stack **b, int *count_chunk)
{
	if (is_second)
	{
		(*count_chunk)--;
		rb(b);
	}
	else
		(*count_chunk)++;
}

static t_stack	*sort_to_b(
	t_data *data, t_stack **a, t_stack **b, int is_second)
{
	int	pos;
	int	*count_chunk;

	if (is_second)
	{
		pos = ra_or_rra2(data, a);
		count_chunk = &data->count_chunk2;
	}
	else
	{
		pos = ra_or_rra(data, a);
		count_chunk = &data->count_chunk1;
	}
	while (pos-- > 1)
	{
		if (data->r_needed == TRUE && data->rr_needed == FALSE)
			ra(a);
		else if (data->rr_needed == TRUE && data->r_needed == FALSE)
			rra(a);
	}
	pb(a, b);
	update_count_chunk(is_second, b, count_chunk);
	return (*a);
}

static void	get_chunks(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_data	data;

	data.quarter = ft_sqrt(stacksize(*a)) * 2;
	node = *a;
	data.c1 = stacksize(*a) / 2;
	data.count_chunk1 = stacksize(*a) / 2;
	data.c2 = (stacksize(*a) / 2) + data.quarter;
	data.count_chunk2 = (stacksize(*a) / 2) + data.quarter;
	while (node)
	{
		data.size = stacksize(*a);
		if (data.count_chunk1 == data.c1)
			data.c1 += data.quarter;
		if (data.count_chunk2 == data.c2)
			data.c2 -= data.quarter;
		if (node->index <= data.c1 && node->index > data.c1 - data.quarter)
			node = sort_to_b(&data, a, b, 0);
		else if (node->index <= data.c2 && node->index > data.c2 - data.quarter)
			node = sort_to_b(&data, a, b, 1);
		else
			node = node->next;
	}
	stackclear(a);
}

void	sort_beyond(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_data	data;

	get_chunks(a, b);
	node = *b;
	while (node)
	{
		data.max_pos = get_max_index(b);
		data.size = stacksize(*b);
		node = sort_to_a(&data, a, b);
	}
	stackclear(b);
}
