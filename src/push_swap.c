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
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		size;

	if (arc > 1)
	{
		a_stack = get_values(arc, arv);
		b_stack = NULL;
		size = stacksize(a_stack);
		get_index(a_stack, size);
		puts("");
		ft_printf("Stack A\t\tStack B\n");
		puts("-------------------------");
		stackdisplay(a_stack, b_stack);
		puts("-------------------------");
		ft_printf("Min value position:\t%d\n", min_value_pos(&a_stack));
		ft_printf("Number of values:\t%d\n", size);
	}
	return (0);
}
