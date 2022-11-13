/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:25:57 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/13 15:41:26 by julmuntz         ###   ########.fr       */
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
			else if (current->value > min_value && current->index == 0)
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

int	get_max_index(t_stack **ptr)
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
