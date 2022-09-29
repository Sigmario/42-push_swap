/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:00 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/29 16:04:35 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_to_list(int *array, int size, t_stack **ptr)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ps_lstadd_back(ptr, ps_lstnew(array[i]));
		i++;
	}
}

void	print_list(t_stack *ptr)
{
	if (!ptr)
		return ;
	while (ptr)
	{
		ft_printf("[%d] ", ptr->value);
		ptr = ptr->next;
	}
	ft_printf("\n");
}
