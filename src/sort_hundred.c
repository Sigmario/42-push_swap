/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/20 19:16:50 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top(t_stack **ptr, int count, t_stack **a, t_stack **b)
{
	int i;

	i = 1;
	get_index(*ptr, stacksize(*ptr));
	if ((*ptr)->index <= (*ptr)->chunk)
	{
		while (i < count)
		{
			ra(a);
			i++;
		}
		pb(a, b);
	}
	printf("------\n");
	printf("\t\t\t\t\tvalue: %d\n", (*ptr)->value);
	printf("\t\t\t\t\t\t\tindex: %d\n", (*ptr)->index);
	printf("\t\tchunk: %d\n", (*ptr)->chunk);
	printf("count: %d\n", count);
}

int	sort_hundred(t_stack **a, t_stack **b)
{
	int		i;
	int		tmp;
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
		if (current->index <= chunk)
		{
			tmp = current->index;
			current->pos = (*a)->pos;
			current->chunk = chunk;
			top(&current, i, a, b);
			current->index = tmp;
			printf("count: %d\tchunk: %d\tpos: %d\tvalue: %d\tindex: %d\n", i, chunk, current->pos, current->value, current->index);
			printf("------\n\n");
			(*a)->pos = current->pos;
			i++;
		}
		if (i == chunk)
		{
			if (limit != 2)
			{
				limit++;
				chunk += quarter;
			}
			else
				limit = 2;
		}
		current = current->next;
	}
	return (0);
}
