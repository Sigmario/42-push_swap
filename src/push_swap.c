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
	int		min_value;
	int		size;

	if (arc > 1)
	{
		stack.a = get_values(arc, arv);
		stack.b = NULL;
		size = stacksize(stack.a);
		get_index(stack.a, size);
		min_value = min_value_pos(&stack.a);
		if (sorted(&stack.a) == TRUE)
			return (exit(EXIT_FAILURE), 0);
		puts("");
		ft_printf("Stack A\t\tStack B\n");
		puts("-------------------------");
		stackdisplay(stack.a, stack.b);
		puts("-------------------------");
		ft_printf("Min value position:\t%d\n", min_value);
		ft_printf("Number of values:\t%d\n", size);
	}
	return (0);
}
