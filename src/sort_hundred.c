/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/18 14:59:27 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_hundred(t_stack **a, t_stack **b)
{
	int	quart;
	int	bucket[5];
	int	count;

	quart = (stacksize(*a) / 4);
	bucket[1] = 1;
	bucket[2] = quart * 2;
	bucket[3] = quart * 2 + 1;
	bucket[4] = quart * 4;
	count = quart;
	while (*a)
	{
		while (count <= stacksize(*a))
		{
			if ((*a)->index >= bucket[1] && (*a)->index <= bucket[2])
			{
				pb(a, b);
				rb(b);
			}
			else if ((*a)->index >= bucket[3] && (*a)->index <= bucket[4])
				pb(a, b);
			else
				ra(a);
			count++;
		}
		bucket[1] -= quart;
		bucket[2] += quart;
		bucket[3] -= quart;
		bucket[4] += quart;
		count = 0;
	}
	return (0);
}
