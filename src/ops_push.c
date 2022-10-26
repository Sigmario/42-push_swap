/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:59:36 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/26 12:32:35 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **current, t_stack **adjacent)
{
	t_stack	*first_node;
	int		first_index;
	t_stack	*second_node;
	int		second_index;

	if (!*current)
		return ;
	first_node = *current;
	first_index = (*current)->index;
	second_node = (*current)->next;
	second_index = (*current)->next->index;
	(*current)->next = *adjacent;
	*adjacent = first_node;
	*current = second_node;
	(*adjacent)->index = first_index;
	(*current)->index = second_index;
	get_pos(current);
	get_pos(adjacent);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}
