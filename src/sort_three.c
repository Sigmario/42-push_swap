/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:06:47 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/13 20:33:26 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack **a)
{
	int		first;
	int		second;
	int		third;

	if (stacksize(*a) != 3)
		return (ft_printf("Function 'sort_three' only works with 3 values.\n"), \
		exit(EXIT_FAILURE), 0);
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
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
