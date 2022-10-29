/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:36:22 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/29 19:17:15 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **ptr)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = *ptr;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*ptr = prev;
}

void	stackrev(t_stack *node)
{
	int		i;
	t_stack	*current;
	int		*array;

	i = 0;
	current = node;
	array = (int *)malloc(sizeof(int) * stacksize(node));
	while (current)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	current = node;
	i--;
	while (current)
	{
		current->value = array[i];
		current = current->next;
		i--;
	}
}
