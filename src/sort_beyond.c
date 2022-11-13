/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/13 15:41:56 by julmuntz         ###   ########.fr       */
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

static	t_stack	*sort_to_b(t_data *data, t_stack **a, t_stack **b)
{
	int	pos;

	pos = ra_or_rra(data, a);
	if (data->r_needed == TRUE && data->rr_needed == FALSE)
	{
		while (pos-- > 1)
			ra(a);
	}
	else if (data->rr_needed == TRUE && data->r_needed == FALSE)
	{
		while (pos-- > 1)
			rra(a);
	}
	pb(a, b);
	data->count_chunk++;
	return (*a);
}

static void	get_chunks(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_data	data;

	data.chunk = ft_sqrt(stacksize(*a)) * 2;
	data.quarter = data.chunk;
	node = *a;
	data.count_chunk = 0;
	while (node)
	{
		data.size = stacksize(*a);
		if (data.count_chunk == data.chunk)
			data.chunk += data.quarter;
		else if (node->index <= data.chunk)
			node = sort_to_b(&data, a, b);
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
