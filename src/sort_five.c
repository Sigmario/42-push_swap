/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:17:14 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/13 20:59:09 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_five(t_stack **a, t_stack **b)
{
	if (stacksize(*a) != 5)
		return (ft_printf("Function 'sort_five' only works with 5 values.\n"), \
		exit(EXIT_FAILURE), 0);
	pb(a, b);
	pb(a, b);
	ft_printf("pb\npb\n");
	sort_three(a);
	pa(a, b);
	ft_printf("pa\n");
	// if ((*a)->index < (*a)->next->index && (*a)->index < (*a)->next->next->next->index)
	// if ((*a)->index < (*a)->next->index && (*a)->next->index > (*a)->next->next->next->index)
	// {
	// 	ra(a);
	// 	ft_printf("sa\nra\n");
	// }
	if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->next->index)
	{
		ra(a);
		ft_printf("ra\n");

		ft_printf("1: %d\n", (*a)->next->next->next->index);
		ft_printf("2: %d\n", (*a)->next->next->index);
		ft_printf("3: %d\n", (*a)->next->index);
		ft_printf("4: %d\n", (*a)->index);
	}
	else if ((*a)->index > (*a)->next->index && (*a)->index < (*a)->next->next->next->index)
	{
		sa(a);
		pa(a, b);
		rra(a);
		sa(a);
		ra(a);
		ra(a);
		ft_printf("sa\npa\nrra\nsa\nra\nra\n");
	}
	return (0);
}
