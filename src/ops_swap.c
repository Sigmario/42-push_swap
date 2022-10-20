/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:37:22 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/20 11:16:13 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **ptr)
{
	int	first;
	int	first_index;
	int	second;
	int	second_index;

	if (!*ptr)
		return ;
	first = (*ptr)->value;
	first_index = (*ptr)->index;
	if (!(*ptr)->next)
		return ;
	second = (*ptr)->next->value;
	second_index = (*ptr)->next->index;
	(*ptr)->value = second;
	(*ptr)->index = second_index;
	(*ptr)->next->value = first;
	(*ptr)->next->index = first_index;
	get_pos(ptr);
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
