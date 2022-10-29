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

int	main(int arc, char **arv)
{
	t_stack	stack;
	int		size;

	if (arc > 1)
	{
		stack.a = get_values(arc, arv);
		stack.b = NULL;
		size = stacksize(stack.a);
		get_pos(&stack.a);
		get_index(&stack.a, size);
		if (sorted(&stack.a) == TRUE)
			return (exit(EXIT_FAILURE), 0);
		if (stacksize(stack.a) == 2)
			sort_two(&stack.a);
		else if (stacksize(stack.a) == 3)
			sort_three(&stack.a);
		else if (stacksize(stack.a) == 4)
			sort_four(&stack.a, &stack.b, 1);
		else if (stacksize(stack.a) == 5)
			sort_five(&stack.a, &stack.b);
		else
			sort_beyond(&stack.a, &stack.b);
		// stackdisplay(stack.a, stack.b);
	}
	return (0);
}
