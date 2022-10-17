/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/17 17:52:49 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_top(t_stack **a, t_stack **b, int i)
{
	while (i != 1)
	{
		ra(a);
		i--;
	}
	if ((!(*b)) || ((*a)->index > (*b)->index))
		pb(a, b);
	else if ((*a)->index < (*b)->index)
	{
		pb(a, b);
		rb(b);
	}
}

int	hold_first(t_stack **a, t_stack **b)
{
	int		loop;
	t_stack	*a_node;

	loop = TRUE;
	a_node = *a;
	while (loop)
	{
		while ((a_node)->index != (stacksize(a_node) / 2))
		{
			loop = FALSE;
			if (a_node && a_node->index >= 1 && a_node->index <= 20)
			{
				move_to_top(a, b, a_node->pos);
				loop = TRUE;
			}
			a_node = a_node->next;
			// ft_printf("%p", a_node);
		}
	}
	return (0);
}
