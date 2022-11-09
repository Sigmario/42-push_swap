/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:59:36 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/09 18:26:12 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **current, t_stack **adjacent)
{
	int	value;

	value = (*current)->value;
	stackpop(current);
	stackadd_front(adjacent, stacknew(value));
	get_pos(current);
}

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(a, b);
	ft_printf("pb\n");
}
