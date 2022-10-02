/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:00 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/29 16:04:35 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_top(t_stack *top)
{
	t_stack	*temp;

	if (top)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}

void	display_stack(t_stack *top)
{
	t_stack	*current;

	if (!top)
		return ;
	current = top;
	while (current->next)
	{
		ft_printf("%d -> ", current->value);
		current = current->next;
	}
	ft_printf("%d\n", current->value);
}

void	array_to_list(t_data *data, t_stack **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ps_lstadd_back(ptr, ps_lstnew(data->array[i]));
		i++;
	}
}

int	number_of_elements(t_stack *top)
{
	t_stack	*current;
	int		count;

	count = 0;
	current = top;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
