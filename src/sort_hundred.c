/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/27 23:50:24 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		i;

	i = 1;
	get_chunks(a, b);
	current = *b;
	while (current)
	{
		if (current->pos == stacksize(current))
		{
			while (i < current->pos)
			{
				rb(b);
				i++;
			}
			pa(a, b);
			i = 1;
		}
		current = current->next;
	}
}
