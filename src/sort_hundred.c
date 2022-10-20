/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/20 23:12:21 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top(int index, int chunk, int pos, t_stack **a)
{
	int i;

	i = 1;
	if (index <= chunk)
	{
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	// get_index(*a, stacksize(*a));
	printf("chunk: %d\tpos: %d\tindex: %d\n", chunk, pos, index);
	printf("------\n\n");
}

int	sort_hundred(t_stack **a, t_stack **b)
{
	int		i;
	int		index;
	int		limit;
	t_stack	*current;
	int		quarter;
	int		chunk;

	i = 1;
	limit = 1;
	current = *a;
	quarter = stacksize(*a) / 4;
	chunk = quarter;
	while (current)
	{
		if (i == chunk)
		{
			limit++;
			if (limit != 2)
			{
				chunk += quarter;
			}
			else
				limit = 2;
		}
		if (current->index <= chunk)
		{
			index = current->index;
			current->pos = (*a)->pos;
			if (i <= chunk)
			{
				top(index, chunk, current->pos, a);
				pb(a, b);
			}
			(*a)->pos = current->pos;
			// printf("count: %d\tchunk: %d\tpos: %d\tvalue: %d\tindex: %d\n", i, current->chunk, current->pos, current->value, index);
			// printf("------\n\n");
			i++;
		}
		current = current->next;
	}
	return (0);
}
