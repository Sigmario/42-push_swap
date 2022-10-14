/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:17:14 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/14 18:48:25 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_five(t_stack **a, t_stack **b)
{
	if (stacksize(*a) != 5)
		return (ft_printf("Function 'sort_five' only works with 5 values.\n"), \
		exit(EXIT_FAILURE), 0);

	puts("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

	pb(a, b);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	pb(a, b);

	// puts("sort_three:");
	// sort_three(a);
	
	// pa(a, b);
	// pa(a, b);
	// puts("pa\npa\n");

	// puts("\nA:");
	// ft_printf("index: %d - Value: %d\n", (*a)->index, (*a)->value);
	// ft_printf("index: %d - Value: %d\n", (*a)->next->index, (*a)->next->value);
	// ft_printf("index: %d - Value: %d\n", (*a)->next->next->index, (*a)->next->next->value);
	// ft_printf("index: %d - Value: %d\n", (*a)->next->next->next->index, (*a)->next->next->next->value);
	// ft_printf("index: %d - Value: %d\n", (*a)->next->next->next->next->index, (*a)->next->next->next->next->value);

	puts("\nB:");
	ft_printf("index: %d - Value: %d\n", (*b)->index, (*b)->value);
	ft_printf("index: %d - Value: %d\n", (*b)->next->index, (*b)->next->value);
	ft_printf("index: %d - Value: %d\n", (*b)->next->index, (*b)->next->next->value);
	ft_printf("index: %d - Value: %d\n", (*b)->next->index, (*b)->next->next->next->value);
	ft_printf("index: %d - Value: %d\n", (*b)->next->index, (*b)->next->next->next->next->value);

	puts("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

	// sa(a);
	// rra(a);
	// sa(a);
	// ra(a);
	// ra(a);

	// puts("A:");
	// ft_printf("index: %d - Value: %d\n", (*a)->index, (*a)->value);
	// ft_printf("index: %d - Value: %d\n", (*a)->next->index, (*a)->next->value);
	// ft_printf("index: %d - Value: %d\n", (*a)->next->next->index, (*a)->next->next->value);
	// ft_printf("index: %d - Value: %d\n", (*a)->next->next->next->index, (*a)->next->next->next->value);
	// ft_printf("index: %d - Value: %d\n", (*a)->next->next->next->next->index, (*a)->next->next->next->next->value);

	puts("\nB:");
	ft_printf("index: %d - Value: %d\n", (*b)->index, (*b)->value);
	ft_printf("index: %d - Value: %d\n", (*b)->next->index, (*b)->next->value);
	ft_printf("index: %d - Value: %d\n", (*b)->next->index, (*b)->next->next->value);
	ft_printf("index: %d - Value: %d\n", (*b)->next->index, (*b)->next->next->next->value);
	ft_printf("index: %d - Value: %d\n", (*b)->next->index, (*b)->next->next->next->next->value);

	puts("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	return (0);
}
