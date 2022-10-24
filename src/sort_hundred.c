/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:33:30 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/24 20:49:08 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	top_or_bottom(int chunk, int quarter, t_stack **a)
{
	int		boolean;
	t_stack *current;
	t_stack *reverse;
	int		u_count;
	int		b_count;

	current = stackcopy(*a);
	reverse = stackcopy(*a);
	boolean = 0;
	u_count = 0;
	b_count = 0;
	get_index(current, stacksize(current));
	stackrev(&reverse);
	get_index(reverse, stacksize(reverse));
	while (current && reverse)
	{
		if (u_count <= b_count)
			return (1);
		if (b_count <= u_count)
			return (2);
		else if (current->index >= (chunk - quarter) && current->index <= chunk)
		{
			get_index(current, stacksize(current));
			stackrev(&reverse);
			get_index(reverse, stacksize(reverse));
			printf("TOOOOOOOOOOOOPquarter: %d\tchunk: %d\tpos: %d\tindex: %d\n", quarter, chunk, current->pos, current->index);
			u_count = current->pos;
		}
		else if (reverse->index >= (chunk - quarter) && reverse->index <= chunk)
		{
			get_index(current, stacksize(current));
			stackrev(&reverse);
			get_index(reverse, stacksize(reverse));
			printf("BOTTTTTTTTTOMquarter: %d\tchunk: %d\tpos: %d\tindex: %d\n", quarter, chunk, reverse->pos, reverse->index);
			b_count = reverse->pos;
		}
		current = current->next;
		reverse = reverse->next;
	}
	return (0);
}

static t_stack	*top(int chunk, int quarter, int index, int pos, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	if (index >= (chunk - quarter) && index <= chunk)
	{
		while (i < pos)
		{
			ra(a);
			// printf("TTTTTTTTTTTchunk: %d\tpos: %d\tindex: %d\n", chunk, pos, index);
			// printf("------\n\n");
			i++;
		}
		pb(a, b);
	}
	get_index(*a, stacksize(*a));
	get_index(*b, stacksize(*b));
	return (*a);
}

static t_stack	*bottom(int chunk, int quarter, int index, int pos, t_stack **a, t_stack **b)
{
	int	i;

	i = stacksize(*a);
	if (index >= (chunk - quarter) && index <= chunk)
	{
		while (i > pos)
		{
			rra(a);
			// printf("BBBBBBBBchunk: %d\tpos: %d\tindex: %d\n", chunk, pos, index);
			// printf("------\n\n");
			i--;
		}
		pb(a, b);
	}
	get_index(*a, stacksize(*a));
	get_index(*b, stacksize(*b));
	return (*a);
}

int	sort_hundred(t_stack **a, t_stack **b)
{
	int		i;
	int		count;
	int		chunk;
	int		quarter;
	t_stack **current;

	i = 1;
	count = 1;
	current = a;
	quarter = stacksize(*a) / 4;
	chunk = quarter;
	while (*current)
	{
		if (i == chunk)
		{
			count++;
			if (count > 4)
				return (0);
			else if (count <= 4)
				chunk += quarter;
		}
		else if (top_or_bottom(chunk, quarter, a) == 1 && (*current)->index >= (chunk - quarter) && (*current)->index <= chunk)
		{
			get_index(*current, stacksize(*current));
			printf("TTTTTTTTTTchunk: %d\tpos: %d\tindex: %d\n", chunk, (*current)->pos, (*current)->index);
			*current = top(chunk, quarter, (*current)->index, (*current)->pos, a, b);
			i++;
		}
		else if (top_or_bottom(chunk, quarter, a) == 2 && (*current)->index >= (chunk - quarter) && (*current)->index <= chunk)
		{
			get_index(*current, stacksize(*current));
			printf("BBBBBBBBchunk: %d\tpos: %d\tindex: %d\n", chunk, (*current)->pos, (*current)->index);
			*current = bottom(chunk, quarter, (*current)->index, (*current)->pos, a, b);
			i++;
		}
		(*current) = (*current)->next;
	}
	return (0);
}
