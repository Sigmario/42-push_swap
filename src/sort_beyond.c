/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_beyond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/10 15:21:52 by julmuntz         ###   ########.fr       */
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

static	t_stack	*sort_to_b(int pos, t_data *data, t_stack **a, t_stack **b)
{
	while (pos-- > 1)
		ra(a);
	pb(a, b);
	data->count_chunk++;
	return (*a);
}

static void	get_chunks(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_data	data;

	data.chunk = ft_sqrt(stacksize(*a) / 2);
	data.quarter = data.chunk;
	node = *a;
	data.count_chunk = 1;
	while (node)
	{
		if (data.count_chunk == data.chunk)
			data.chunk += data.quarter;
		else if (node->index <= data.chunk + 1)
			node = sort_to_b(node->pos, &data, a, b);
		else
			node = node->next;
	}
	stackclear(a);
}

static t_stack	*max1_or_max2(t_stack *node, t_data *data, t_stack **a,	\
															t_stack **b)
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
		data.max_index = get_1stmax(b);
		data.sec_max_index = get_2ndmax(b);
		node = max1_or_max2(node, &data, a, b);
	}
	stackclear(b);
}
