/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:29:06 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/29 16:12:30 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort(t_stack **a, t_stack **b)
{
	if (sorted(a) == TRUE)
		return (stackclear(a), exit(EXIT_SUCCESS), 0);
	else if (sorted(a) == FALSE && stacksize(*a) == 2)
		sort_2(a);
	else if (sorted(a) == FALSE && stacksize(*a) == 3)
		sort_3(a);
	else if (sorted(a) == FALSE && stacksize(*a) == 4)
		sort_4(a, b);
	else if (sorted(a) == FALSE && stacksize(*a) == 5)
		sort_5(a, b);
	else if (sorted(a) == FALSE && stacksize(*a) >= 6)
		sort_beyond(a, b);
	return (0);
}

int	main(int arc, char **arv)
{
	t_stack	stack;
	int		size;

	ft_bzero(&stack, sizeof(t_stack));
	if (arc > 1)
	{
		stack.a = get_values(arc - 1, arv);
		stack.b = NULL;
		size = stacksize(stack.a);
		get_pos(&stack.a);
		get_index(&stack.a, size);
		sort(&stack.a, &stack.b);
		stackclear(&stack.a);
	}
	return (0);
}
