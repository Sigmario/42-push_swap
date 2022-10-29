/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/29 22:15:04 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static t_stack	*sort_to_a(int pos, t_stack **a, t_stack **b)
// {
// 	int	i;

// 	i = 1;
// 	while (i < pos)
// 	{
// 		rb(b);
// 		i++;
// 	}
// 	pa(a, b);
// 	while (i > 1)
// 	{
// 		rrb(b);
// 		i--;
// 	}
// 	return (*b);
// }

static t_stack	*sort_to_b(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	while (i < data->pos)
	{
		ra(a);
		i++;
	}
	pb(a, b);
	return (*a);
}

static t_stack	*r_sort_to_b(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < data->pos)
	{
		rra(a);
		i++;
	}
	pb(a, b);
	return (*a);
}

static t_stack	*choose(t_data *data, t_stack **a)
{
	int		top;
	t_stack	*node;
	int		bottom;
	t_stack	*rev;

	node = stackcopy(*a);
	rev = stackcopy(*a);
	get_index(&node, stacksize(node));
	get_pos(&rev);
	get_pos(&node);
	stackrev(rev);
	get_index(&rev, stacksize(rev));
	while (node)
	{
		if (node->index >= data->chunk - data->quarter + 1
			&& node->index <= data->chunk)
		{
			top = node->pos;
			break ;
		}
		node = node->next;
	}
	while (rev)
	{
		if (rev->index >= data->chunk - data->quarter + 1
			&& rev->index <= data->chunk)
		{
			bottom = rev->pos;
			break ;
		}
		rev = rev->next;
	}
	if (top <= bottom)
	{
		data->pos = top;
		data->bool = TOP;
	}
	else if (bottom < top)
	{
		data->pos = bottom;
		data->bool = BOTTOM;
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
		if (i == data.chunk)
			data.chunk += data.quarter;
		else if (data.bool == TOP)
		{
			sort_to_b(&data, a, b);
			node = choose(&data, a);
			i++;
		}
		else if (data.bool == BOTTOM)
		{
			r_sort_to_b(&data, a, b);
			node = choose(&data, a);
			i++;
		}
		else
			node = choose(&data, a);
	}
}

void	sort_beyond(t_stack **a, t_stack **b)
{
	int		size;
	// t_stack	*node;
	// t_data	data;

	size = stacksize(*a);
	if (size <= 100)
		get_chunks(4, a, b);
	if (size <= 500)
		get_chunks(4, a, b);
	// node = *b;
	// while (node)
	// {
	// 	data.pos = node->pos;
	// 	data.index = node->index;
	// 	data.size = stacksize(*b);
	// 	data.max_pos = max_value_pos(b);
	// 	if (data.index == data.size)
	// 		node = sort_to_a(node->pos, a, b);
	// 	else
	// 		(node) = (node)->next;
	// }
}
