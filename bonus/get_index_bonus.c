/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:25:57 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/10 18:28:43 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		if (current->index >= max_value_pos)
		{
			second_max_value_pos = max_value_pos;
			max_value_pos = current->index;
		}
		else if (current->index >= second_max_value_pos
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
