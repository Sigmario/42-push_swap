/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2345.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:17:14 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/30 04:06:37 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish(t_stack **a, t_stack **b)
{
	if (stacksize(*b) == 1)
		return (sort_3(a), pa(a, b));
	if (stacksize(*b) == 2)
		return (sort_3(a), pa(a, b), pa(a, b));
}

void	sort_2(t_stack **a)
{
	if (stacksize(*a) != 2)
		return ;
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int		first;
	int		second;
	int		third;

	if (stacksize(*a) != 3)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && third > first)
		return (sa(a));
	if (first < second && second > third && third > first)
		return (sa(a), ra(a));
	if (first > second && second < third && third < first)
		return (ra(a));
	if (first < second && second > third && third < first)
		return (rra(a));
	if (first > second && second > third && third < first)
		return (sa(a), rra(a));
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	i;

	if (*b)
		i = 2;
	if (!*b)
		i = 1;
	if (stacksize(*a) != 4)
		return ;
	if ((*a)->index == i)
		return (pb(a, b), finish(a, b));
	if ((*a)->next->index == i)
		return (sa(a), pb(a, b), finish(a, b));
	if ((*a)->next->next->index == i)
		return (ra(a), sa(a), pb(a, b), finish(a, b));
	if ((*a)->next->next->next->index == i)
		return (rra(a), pb(a, b), finish(a, b));
}

void	sort_5(t_stack **a, t_stack **b)
{
	if (stacksize(*a) != 5)
		return ;
	if ((*a)->index == 1)
		return (pb(a, b), sort_4(a, b));
	if ((*a)->next->index == 1)
		return (sa(a), pb(a, b), sort_4(a, b));
	if ((*a)->next->next->index == 1)
		return (ra(a), sa(a), pb(a, b), sort_4(a, b));
	if ((*a)->next->next->next->index == 1)
		return (rra(a), rra(a), pb(a, b), sort_4(a, b));
	if ((*a)->next->next->next->next->index == 1)
		return (rra(a), pb(a, b), sort_4(a, b));
}
