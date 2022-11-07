/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/07 15:20:03 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*sort_to_a(int pos, t_stack **a, t_stack **b)
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
	int top;
	int bottom;
	t_stack *node;
	t_stack *r_node;

	top = 1;
	bottom = 2;
	node = stackcopy(*a);
	get_index(&node, stacksize(node));
	while (node)
	{
		if ((node->index >= (data->chunk - data->quarter)
			&& node->index <= data->chunk))
			break ;
		node = node->next;
		top++;
	}
	r_node = stackcopy(*a);
	stackrev(r_node);
	get_index(&r_node, stacksize(r_node));
	while (r_node)
	{
		if ((r_node->index >= (data->chunk - data->quarter)
			&& r_node->index <= data->chunk))
			break ;
		r_node = r_node->next;
		bottom++;
	}
	if (top <= bottom)
	{
		while (top-- > 1)
			ra(a);
		pb(a, b);
		return (*a);
	}
	else if (bottom < top)
	{
		while (bottom-- > 1)
			rra(a);
		pb(a, b);
		return (*a);
	}
	return (0);
}

static void	get_chunks(t_stack **a, t_stack **b)
{
	t_data data;
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
	t_stack	*node;
	t_data	data;

	get_chunks(a, b);
	node = *b;
	data.sa_needed = TBD;
	while (node)
	{
		data.index = node->index;
		data.size = stacksize(*b);
		data.max_index = get_max_index(b);
		data.sec_max_index = get_2ndmax_index(b);
		node = max1_or_max2(node, &data, a, b);
	}
	stackclear(b);
}
