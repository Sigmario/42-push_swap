/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/07 16:01:43 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra_or_rra(t_stack *node, t_stack *r_node, t_data *data)
{
	data->ra_count = 1;
	data->rra_count = 2;
	get_index(&node, stacksize(node));
	while (node)
	{
		if ((node->index >= (data->chunk - data->quarter)
				&& node->index <= data->chunk))
			break ;
		node = node->next;
		data->ra_count++;
	}
	stackrev(r_node);
	get_index(&r_node, stacksize(r_node));
	while (r_node)
	{
		if ((r_node->index >= (data->chunk - data->quarter)
				&& r_node->index <= data->chunk))
			break ;
		r_node = r_node->next;
		data->rra_count++;
	}
}

t_stack	*sort_to_a(int pos, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	while (i++ < pos)
		rb(b);
	pa(a, b);
	while (--i > 1)
		rrb(b);
	return (*b);
}

static	t_stack	*sort_to_b(t_data *data, t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*r_node;

	node = stackcopy(*a);
	r_node = stackcopy(*a);
	ra_or_rra(node, r_node, data);
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
	pb(a, b);
	return (*a);
}

static void	get_chunks(t_stack **a, t_stack **b)
{
	t_data	data;
	t_stack	*node;

	data.quarter = ft_sqrt(stacksize(*a)) / 2;
	data.chunk = data.quarter;
	node = *a;
	while (node)
	{
		if (node->index >= (data.chunk - data.quarter))
			node = sort_to_b(&data, a, b);
		else
			node = node->next;
	}
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
