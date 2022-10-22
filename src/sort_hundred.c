/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/22 20:37:32 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*top(int quarter, int index, int pos, t_stack **a, t_stack **b)
{
	int	i;
	int	chunk;

	i = 1;
	chunk = quarter;
	if (index > (chunk - quarter) && index < chunk)
	{
		while (i < pos)
		{
			ra(a);
			i++;
		}
		pb(a, b);
	}
	printf("chunk: %d\tpos: %d\tindex: %d\n", chunk, pos, index);
	printf("------\n\n");
	return (*a);
}

// static t_stack	*bottom(int quarter, int index, int chunk, int pos, t_stack **a, t_stack **b)
// {
// 	int i;

// 	i = 1;
// 	if (index > (chunk - quarter) && index < chunk)
// 	{
// 		while (i < pos)
// 		{
// 			rra(a);
// 			i++;
// 		}
// 		pb(a, b);
// 	}
// 	printf("chunk: %d\tpos: %d\tindex: %d\n", chunk, pos, index);
// 	printf("------\n\n");
// 	return (*a);
// }

static t_stack	*sort_quarter(int chunk, t_stack **a, t_stack **b)
{
	int		i;
	int		quarter;
	t_stack	*current;
	// t_stack	*r_current;

	i = 1;
	current = *a;
	// r_current = stacklast(*a);
	// r_current = r_current->next;
	quarter = stacksize(*a) / 4;
	while (current)
	{
		if (i == chunk)
			return (*a);
		else if (current->index > (chunk - quarter) && current->index < chunk)
		{
			current = top(quarter, current->index, current->pos, a, b);
			// current = bottom(quarter, r_current->index, chunk, r_current->pos, a, b);
			i++;
		}
		current = current->next;
		// r_current = current->next;
	}
	return (*a);
}

int	sort_hundred(t_stack **a, t_stack **b)
{
	int quarter;

	quarter = stacksize(*a) / 4;
	*a = sort_quarter(quarter, a, b);
	// *a = sort_quarter(quarter * 2, a, b);
	// *a = sort_quarter(quarter * 3, a, b);
	// *a = sort_quarter(quarter * 4, a, b);
	return (0);
}