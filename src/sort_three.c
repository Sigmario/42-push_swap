/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:06:47 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/27 17:16:05 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
