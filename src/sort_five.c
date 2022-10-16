/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:17:14 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/16 22:29:09 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_five3(t_stack **a, t_stack **b)
{
	return (sort_three(a), pa(a, b), pa(a, b), 0);
}

static int	sort_five2(t_stack **a, t_stack **b)
{
	if ((*a)->index == 2)
		return (pb(a, b), sort_five3(a, b));
	if ((*a)->next->index == 2)
		return (sa(a), pb(a, b), sort_five3(a, b));
	if ((*a)->next->next->index == 2)
		return (ra(a), sa(a), pb(a, b), rra(a), sort_five3(a, b));
	if ((*a)->next->next->next->index == 2)
		return (rra(a), rra(a), pb(a, b), ra(a), sort_five3(a, b));
	return (0);
}

int	sort_five(t_stack **a, t_stack **b)
{
	if (stacksize(*a) != 5)
		return (ft_printf("Function 'sort_five' only works with 5 values.\n"), \
		exit(EXIT_FAILURE), 0);
	if ((*a)->index == 1)
		return (pb(a, b), sort_five2(a, b));
	if ((*a)->next->index == 1)
		return (sa(a), pb(a, b), sort_five2(a, b));
	if ((*a)->next->next->index == 1)
		return (ra(a), sa(a), pb(a, b), rra(a), sort_five2(a, b));
	if ((*a)->next->next->next->index == 1)
		return (rra(a), rra(a), pb(a, b), ra(a), sort_five2(a, b));
	if ((*a)->next->next->next->next->index == 1)
		return (rra(a), pb(a, b), sort_five2(a, b));
	return (0);
}
