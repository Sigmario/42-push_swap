/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:06:47 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/13 16:20:40 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack **a)
{
	t_stack	*node;
	int		first;
	int		second;
	int		third;

	node = *a;
	first = node->index;
	second = node->next->index;
	if (first > second && !node->next->next)
		return (sa(a), ft_printf("sa\n"), 0);
	third = node->next->next->index;
	if (first > second && second < third && third < first)
		return (ra(a), ft_printf("ra\n"), 0);
	if (first < second && second > third && third < first)
		return (rra(a), ft_printf("rra\n"), 0);
	if (first > second && second < third && third > first)
		return (sa(a), ft_printf("sa\n"), 0);
	if (first < second && second > third && third > first)
		return (sa(a), ra(a), ft_printf("sa\nra\n"), 0);
	if (first > second && second > third && third < first)
		return (ra(a), sa(a), ft_printf("ra\nsa\n"), 0);
	return (0);
}
