/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:25:57 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/07 16:02:04 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack **ptr, int size)
{
	t_stack	*end;
	t_stack	*current;
	int		min_value;

	end = NULL;
	while (size > 0)
	{
		current = *ptr;
		min_value = INT_MIN;
		while (current)
		{
			if (current->value == INT_MIN && current->index == 0)
				current->index = 1;
			if (current->value > min_value && current->index == 0)
			{
				min_value = current->value;
				end = current;
				current = *ptr;
			}
			current = current->next;
		}
		if (end)
			end->index = size;
		size--;
	}
}

void	*max1_or_max2(t_stack *node, t_data *data, t_stack **a, t_stack **b)
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

int	get_1stmax(t_stack **ptr)
{
	t_stack	*current;
	int		max_value_pos;

	get_pos(ptr);
	max_value_pos = INT_MIN;
	current = *ptr;
	while (current)
	{
		if (current->index > max_value_pos)
			max_value_pos = current->index;
		current = current->next;
	}
	return (max_value_pos);
}

int	get_2ndmax(t_stack **ptr)
{
	int		size;
	t_stack	*current;
	int		max_value_pos;
	int		second_max_value_pos;

	get_pos(ptr);
	size = stacksize(*ptr);
	if (size < 2)
		return (0);
	max_value_pos = INT_MIN;
	second_max_value_pos = INT_MIN;
	current = *ptr;
	while (current)
	{
		if (current->index > max_value_pos)
		{
			second_max_value_pos = max_value_pos;
			max_value_pos = current->index;
		}
		else if (current->index > second_max_value_pos
			&& current->index != max_value_pos)
			second_max_value_pos = current->index;
		current = current->next;
	}
	return (second_max_value_pos);
}

void	get_pos(t_stack **ptr)
{
	t_stack	*current;
	int		count;

	current = *ptr;
	count = 1;
	while (current)
	{
		current->pos = count;
		current = current->next;
		count++;
	}
}
