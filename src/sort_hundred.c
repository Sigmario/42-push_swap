/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/26 12:28:13 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*top(int chunk, int quarter, int index, int pos, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	if (index >= (chunk - quarter + 1) && index <= chunk)
	{
		while (i < pos)
		{
			ra(a);
			i++;
		}
		pb(a, b);
	}
	return (*a);
}

int	sort_hundred(t_stack **a, t_stack **b)
{
	int		i;
	int		count;
	int		chunk;
	int		quarter;
	t_stack *current;

	i = 1;
	count = 0;
	current = *a;
	quarter = stacksize(*a) / 4;
	chunk = quarter;
	while (current)
	{
		get_index(current, stacksize(current));
		if (i == chunk)
		{
			count++;
			if (count >= 4)
				return (0);
			else if (count < 4)
				chunk += quarter;
		}
		else if (current->index >= (chunk - quarter + 1) && current->index <= chunk)
		{
			current = top(chunk, quarter, (current)->index, (current)->pos, a, b);
			i++;
		}
		(current) = (current)->next;
	}
	return (0);
}
