/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:06:47 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/13 15:19:55 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack **ptr)
{
	t_stack	*node;
	int		first;
	int		second;
	int		third;

	node = *ptr;
	first = node->index;
	second = node->next->index;
	third = node->next->next->index;
	if (first > second && second < third && third > first)
		return (sa(ptr), ft_printf("sa\n"), 0);
	if (first > second && second < third && third < first)
		return (ra(ptr), ft_printf("ra\n"), 0);
	if (first < second && second > third && third < first)
		return (rra(ptr), ft_printf("rra\n"), 0);
	if (first < second && second > third && third > first)
		return (sa(ptr), ra(ptr), ft_printf("sa\nra\n"), 0);
	if (first > second && second > third && third < first)
		return (ra(ptr), sa(ptr), ft_printf("ra\nsa\n"), 0);
	return (0);
}
