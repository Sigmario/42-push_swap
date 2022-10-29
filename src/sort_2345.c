/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:17:14 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/29 01:00:29 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	finish(t_stack **a, t_stack **b)
{
	if (*b && !(*b)->next)
		return (sort_three(a), pa(a, b), 0);
	else
		return (sort_three(a), pa(a, b), pa(a, b), 0);
}

int	sort_two(t_stack **a)
{
	if (stacksize(*a) != 2)
		return (0);
	if ((*a)->index > (*a)->next->index)
		sa(a);
	return (0);
}

int	sort_three(t_stack **a)
{
	int		first;
	int		second;
	int		third;

	if (stacksize(*a) != 3)
		return (0);
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && third < first)
		return (ra(a), 0);
	if (first < second && second > third && third < first)
		return (rra(a), 0);
	if (first > second && second < third && third > first)
		return (sa(a), 0);
	if (first < second && second > third && third > first)
		return (sa(a), ra(a), 0);
	if (first > second && second > third && third < first)
		return (ra(a), sa(a), 0);
	return (0);
}

int	sort_four(t_stack **a, t_stack **b, int index)
{
	if (stacksize(*a) != 4)
		return (0);
	if ((*a)->index == index)
		return (pb(a, b), finish(a, b));
	if ((*a)->next->index == index)
		return (sa(a), pb(a, b), finish(a, b));
	if ((*a)->next->next->index == index)
		return (ra(a), sa(a), pb(a, b), rra(a), finish(a, b));
	if ((*a)->next->next->next->index == index)
		return (rra(a), pb(a, b), finish(a, b));
	return (0);
}

int	sort_five(t_stack **a, t_stack **b)
{
	if (stacksize(*a) != 5)
		return (0);
	if ((*a)->index == 1)
		return (pb(a, b), sort_four(a, b, 2));
	if ((*a)->next->index == 1)
		return (sa(a), pb(a, b), sort_four(a, b, 2));
	if ((*a)->next->next->index == 1)
		return (ra(a), sa(a), pb(a, b), rra(a), sort_four(a, b, 2));
	if ((*a)->next->next->next->index == 1)
		return (rra(a), rra(a), pb(a, b), ra(a), sort_four(a, b, 2));
	if ((*a)->next->next->next->next->index == 1)
		return (rra(a), pb(a, b), sort_four(a, b, 2));
	return (0);
}
