/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/09 05:51:48 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_to_a(int pos, t_stack **a, t_stack **b)
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

static	t_stack	*sort_to_b(t_data *data, t_stack **a, t_stack **b)
{
	t_stack *node;
	t_stack *copy;
	t_stack *r_node;
	t_stack *r_copy;

	copy = stackcopy(*a);
	node = copy;
	data->ra_count = 1;
	get_index(node, stacksize(node));
	while (node)
	{
		if (node->index <= data->quarter)
			break ;
		node = node->next;
		data->ra_count++;
	}
	r_copy = stackcopy(*a);
	r_node = r_copy;
	data->rra_count = 2;
	stackrev(r_node);
	get_index(r_node, stacksize(r_node));
	while (r_node)
	{
		if (r_node->index <= data->quarter)
			break ;
		r_node = r_node->next;
		data->rra_count++;
	}
	if (data->ra_count <= data->rra_count)
	{
		while (data->ra_count-- > 1)
			ra(a);
	}
	else if (data->rra_count < data->ra_count)
	{
		while (data->rra_count-- > 1)
			rra(a);
	}
	data->count_chunk++;
	pb(a, b);
	return (*a);
}

static void	get_chunks(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_data	data;

	data.quarter = ft_sqrt(stacksize(*a) / 2);
	data.chunk = data.chunk;
	node = *a;
	data.count_chunk = 0;
	while (node)
	{
		if (data.count_chunk == data.chunk)
			data.chunk += data.quarter;
		if (node->index <= data.chunk)
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
	data.sa_needed = TBD;
	while (node)
	{
		data.index = node->index;
		data.size = stacksize(*b);
		data.max_index = get_1stmax(b);
		data.sec_max_index = get_2ndmax(b);
		node = max1_or_max2(node, &data, a, b);
	}
	stackclear(b);
}
