/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_choice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:22:15 by julmuntz          #+#    #+#             */
/*   Updated: 2024/05/18 15:27:39 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	closest(t_data *data, int top, int bottom)
{
	if (top < bottom)
	{
		data->r_needed = TRUE;
		data->rr_needed = FALSE;
		return (top);
	}
	else
	{
		data->rr_needed = TRUE;
		data->r_needed = FALSE;
		return (bottom + 1);
	}
}

int	ra_or_rra(t_data *data, t_stack **a)
{
	int		top;
	int		bottom;
	t_stack	*node;

	top = -1;
	bottom = -1;
	node = *a;
	while (node)
	{
		if (node->index <= data->c1
			&& node->index > data->c1 - data->quarter)
		{
			if (top == -1)
				top = node->pos;
			bottom = node->pos;
		}
		node = node->next;
	}
	bottom = (data->size - bottom) + 1;
	return (closest(data, top, bottom));
}

int	ra_or_rra2(t_data *data, t_stack **a)
{
	int		top;
	int		bottom;
	t_stack	*node;

	top = -1;
	bottom = -1;
	node = *a;
	while (node)
	{
		if (node->index <= data->c2
			&& node->index > data->c2 - data->quarter)
		{
			if (top == -1)
				top = node->pos;
			bottom = node->pos;
		}
		node = node->next;
	}
	bottom = (data->size - bottom) + 1;
	return (closest(data, top, bottom));
}

int	rb_or_rrb(t_data *data, t_stack **b)
{
	int		top;
	int		bottom;
	t_stack	*top_node;
	t_stack	*bottom_node;

	top_node = *b;
	while (top_node)
	{
		if (top_node->index == data->max_pos)
		{
			top = top_node->pos;
			break ;
		}
		top_node = top_node->next;
	}
	bottom_node = *b;
	while (bottom_node)
	{
		if (bottom_node->index == data->max_pos)
			bottom = bottom_node->pos;
		bottom_node = bottom_node->next;
	}
	bottom = (data->size - bottom) + 1;
	return (closest(data, top, bottom));
}
